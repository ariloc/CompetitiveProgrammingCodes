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
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 2e6;
const int MAXST = (1<<(32-__builtin_clz(MAXN)));

struct segT {
    int z,o;

    segT operator+ (const segT &e) const {
        return {z+e.z,o+e.o};
    }
};

segT ST[2*MAXST], lazy[2*MAXST];
int N;

void passLazy (int i, int tl, int tr) {
    if (!lazy[i].z && !lazy[i].o) return;
    ST[i] = {0,0};
    if (lazy[i].o) ST[i] = {0,tr-tl};
    else ST[i] = {tr-tl,0};

    if (2*i+1 < MAXST) {
        lazy[2*i] = lazy[2*i+1] = lazy[i];
    }

    lazy[i] = {0,0};
}

void update (int i, int tl, int tr, int bl, int br, int v) {
    passLazy(i,tl,tr);
    if (tl >= br || tr <= bl) return;
    if (tl >= bl && tr <= br) {
        if (!v) lazy[i].z = 1, lazy[i].o = 0;
        else lazy[i].o = 1, lazy[i].z = 0;
        passLazy(i,tl,tr);
        return;
    }

    int mid = (tl+tr)/2;
    update(2*i,tl,mid,bl,br,v);
    update(2*i+1,mid,tr,bl,br,v);
    ST[i] = ST[2*i] + ST[2*i+1];
}

segT query (int i, int tl, int tr, int bl, int br) {
    passLazy(i,tl,tr);
    if (tl >= br || tr <= bl) return {0,0};
    if (tl >= bl && tr <= br) return ST[i];

    int mid = (tl+tr)/2;
    return query(2*i,tl,mid,bl,br)+query(2*i+1,mid,tr,bl,br);
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n,q; cin >> n >> q;
        string s,f; cin >> s >> f;

        N = (1<<(32-__builtin_clz(n)));
        forn(j,2*N+5) ST[j] = lazy[j] = {0,0}; // reset
        forn(j,n) ST[j+N] = {(f[j] == '0'),(f[j] == '1')};

        // build
        dforsn(j,1,N) ST[j] = ST[2*j] + ST[2*j+1];
        //forn(j,n) cerr << query(1,0,N,j,j+1).o << "!!" << endl;

        vector<ii> queries;
        forn(j,q) {int a,b; cin >> a >> b; queries.pb({a,b});}

        bool posib = true;
        dforn(j,q) {
            ii rang = queries[j];
            segT me = query(1,0,N,rang.fst-1,rang.snd);

            if (me.o == me.z) {posib = false; break;}
            else if (me.o < me.z) update(1,0,N,rang.fst-1,rang.snd,0);
            else update(1,0,N,rang.fst-1,rang.snd,1);
        }

        forn(j,n) {
            segT me = query(1,0,N,j,j+1);
            if ((me.o > 0) != (s[j] == '1')) {posib = false; break;}
        }

        cout << (posib ? "YES" : "NO") << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
