#include <bits/stdc++.h>
 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);
 
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

int const MAXN = 1024005;
int const MAXST = (1<<(32-__builtin_clz(MAXN)));

struct mon {
    int cnt;

    mon(){cnt = 0;}
    mon(int a) : cnt(a){}

    mon operator+ (const mon &o) const {
        return mon(cnt+o.cnt);
    }
};

int lazy[2*MAXST];
mon ST[2*MAXST];
int N;

// mode:
// 1 -> set bucaneer (+)
// 2 -> set barbary (-)
// 3 -> inverse
void setLazy (int mode, int i) {
    if (!mode) return;
    if (mode == 1 || mode == 2) {
        lazy[i] = mode;
    }
    else {
        if (!lazy[i]) lazy[i] = 3; // si no hay nada, lo establezco
        else if (lazy[i] == 1) lazy[i] = 2; // cambia los set
        else if (lazy[i] == 2) lazy[i] = 1;
        else lazy[i] = 0; // cancela inverse
    }
}

void passLazy (int i, int tl, int tr) {
    if (lazy[i] == 1) ST[i].cnt = tr-tl;
    if (lazy[i] == 2) ST[i].cnt = 0;
    if (lazy[i] == 3) ST[i].cnt = (tr-tl)-ST[i].cnt;

    if (2*i+1 < 2*MAXST) {
        setLazy(lazy[i],2*i);
        setLazy(lazy[i],2*i+1);
    }

    lazy[i] = 0;
}

void update (int i, int bl, int br, int mode, int tl = 0, int tr = N) {
    passLazy(i,tl,tr);

    if (tl >= br || tr <= bl) return;
    if (tl >= bl && tr <= br) {
        setLazy(mode,i);
        passLazy(i,tl,tr);
        return;
    }

    int mid = (tl+tr)/2;
    update(2*i,bl,br,mode,tl,mid);
    update(2*i+1,bl,br,mode,mid,tr);
    ST[i] = ST[2*i] + ST[2*i+1];
}

mon query (int i, int bl, int br, int tl = 0, int tr = N) {
    passLazy(i,tl,tr);
    if (tl >= br || tr <= bl) return mon();
    if (tl >= bl && tr <= br) return ST[i];

    int mid = (tl+tr)/2;
    return query(2*i,bl,br,tl,mid) + query(2*i+1,bl,br,mid,tr);
}

int main() {
    FAST_IO;

    int T; cin >> T;
    forn(o,T) {
        int m; cin >> m;
        string nd;
        forn(i,m) {
            int t; string s;
            cin >> t >> s;
            forn(j,t) forn(k,s.size()) nd.pb(s[k]);
        }

        int n = (int)nd.size();
        N = (1<<(32-__builtin_clz(n)));

        forn(i,2*N) ST[i] = mon(), lazy[i] = 0;

        forn(i,n) ST[i+N].cnt = (nd[i] == '1');

        dforsn(i,1,N) ST[i] = ST[2*i] + ST[2*i+1];

        int q; cin >> q;
        cout << "Case " << o+1 << ":\n";
        int outs = 0;
        forn(i,q) {
            char typ; int a,b; cin >> typ >> a >> b, b++;
            if (typ == 'F') update(1,a,b,1);
            if (typ == 'E') update(1,a,b,2);
            if (typ == 'I') update(1,a,b,3);
            if (typ == 'S')
                cout << "Q" << ++outs << ": " << query(1,a,b).cnt << '\n';
        }
    }
    
    return 0;
}
