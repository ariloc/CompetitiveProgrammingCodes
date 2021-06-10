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
#define nxtPow(x) (1<<(32-__builtin_clz(x)))

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 4e5+5;
const int MAXM = 2*MAXN;
const int MAXST = nxtPow(MAXM);
const int MAXC = 60;

struct nodo {
    ll mk;

    nodo operator+ (const nodo &o) const {
        return {mk|o.mk};
    }
};

vi G[MAXN];
nodo ST[2*MAXST], lazy[2*MAXST];
bitset<MAXN> done;
int F[MAXN],L[MAXN],tour[MAXM],col[MAXN],actT = 0;

void passLazy(int i) {
    if (lazy[i].mk) {
        int top = 2*MAXST;
        if (2*i+1 < top) lazy[2*i+1] = lazy[2*i] = lazy[i];
        ST[i] = lazy[i];
        lazy[i].mk = 0;
    }
}

void update(int i, int bl, int br, int c, int tl, int tr) {
    passLazy(i);
    if (tl >= br || tr <= bl) return;
    if (tl >= bl && tr <= br) {
        lazy[i].mk = 1LL<<c;
        passLazy(i);
    }
    else {
        int mid = (tl+tr)/2;
        update(2*i,bl,br,c,tl,mid);
        update(2*i+1,bl,br,c,mid,tr);
        ST[i] = ST[2*i]+ST[2*i+1];
    }
}

nodo query(int i, int bl, int br, int tl, int tr) {
    passLazy(i);
    if (tl >= br || tr <= bl) return {0};
    if (tl >= bl && tr <= br) return ST[i];

    int mid = (tl+tr)/2;
    return query(2*i,bl,br,tl,mid) + query(2*i+1,bl,br,mid,tr);
}

void dfs(int st) {
    done[st] = true;
    tour[actT] = st;
    F[st] = L[st] = actT++;

    for (auto &i : G[st])
        if (!done[i]) {
            dfs(i);
            tour[actT] = st;
            L[st] = actT++;
        }
}

int main() {
    int n,q; scanf("%d %d",&n,&q);

    forn(i,n) scanf("%d",&col[i]), col[i]--;

    forn(i,n-1) {
        int u,v; scanf("%d %d",&u,&v); u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    dfs(0);

    int N = nxtPow(actT);
    forn(i,actT) ST[i+N].mk = 1LL<<col[tour[i]];
    dforsn(i,1,N) ST[i] = ST[2*i]+ST[2*i+1];
    
    forn(i,q) {
        int typ; scanf("%d",&typ);
        if (typ == 1) {
            int v,c; scanf("%d %d",&v,&c); v--, c--;
            update(1,F[v],L[v]+1,c,0,N);
        }
        else {
            int v; scanf("%d",&v); v--;
            printf("%d\n",__builtin_popcountll(query(1,F[v],L[v]+1,0,N).mk));
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
