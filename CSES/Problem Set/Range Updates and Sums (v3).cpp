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

int const MAXN = 2e5+5;
int const MAXST = (1<<(32-__builtin_clz(MAXN)));

// mode | num
pair<int,ll> lazy[2*MAXST];
ll ST[2*MAXST];
int N;

// mode:
// 0 -> nothing
// 1 -> set
// 2 -> inc
void setLazy (int mode, ll v, int i) {
    if (!mode) return;
    if (mode == 1) {
        lazy[i] = {1,v};
    }
    if (mode == 2) {
        if (lazy[i].fst == 0) lazy[i] = {2,v};
        else lazy[i].snd += v;
    }
}

void passLazy (int i, int tl, int tr) {
    if (lazy[i].fst == 1) ST[i] = (tr-tl) * (ll)lazy[i].snd;
    if (lazy[i].fst == 2) ST[i] = ST[i] + (tr-tl) * (ll)lazy[i].snd;

    if (2*i+1 < 2*MAXST) {
        setLazy(lazy[i].fst,lazy[i].snd,2*i);
        setLazy(lazy[i].fst,lazy[i].snd,2*i+1);
    }

    lazy[i] = {0,0};
}

void update (int i, int mode, int v, int bl, int br, int tl = 0, int tr = N) {
    passLazy(i,tl,tr);

    if (tl >= br || tr <= bl) return;
    if (tl >= bl && tr <= br) {
        setLazy(mode,v,i);
        passLazy(i,tl,tr);
        return;
    }

    int mid = (tl+tr)/2;
    update(2*i,mode,v,bl,br,tl,mid);
    update(2*i+1,mode,v,bl,br,mid,tr);
    ST[i] = ST[2*i] + ST[2*i+1];
}

ll query (int i, int bl, int br, int tl = 0, int tr = N) {
    passLazy(i,tl,tr);
    if (tl >= br || tr <= bl) return 0;
    if (tl >= bl && tr <= br) return ST[i];

    int mid = (tl+tr)/2;
    return query(2*i,bl,br,tl,mid) + query(2*i+1,bl,br,mid,tr);
}

int main() {
    int n,q; scanf("%d %d",&n,&q);

    N = (1<<(32-__builtin_clz(n)));

    forn(i,n) scanf("%lld",&ST[i+N]);
    
    dforsn(i,1,N) ST[i] = ST[2*i] + ST[2*i+1];

    forn(i,q) {
        int typ; scanf("%d",&typ);
        int a,b; scanf("%d %d",&a,&b), a--;
        if (typ == 1) {
            int x; scanf("%d",&x);
            update(1,2,x,a,b);
        }
        else if (typ == 2) {
            int x; scanf("%d",&x);
            update(1,1,x,a,b);
        }
        else printf("%lld\n",query(1,a,b));
    }
       
    return 0;
}
