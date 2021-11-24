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

const int MAXN = 2e5+5;
const int MAXK = 25;

vi G[MAXN];
int P[MAXK][MAXN], dep[MAXN];
bitset<MAXN> done;

void dfs (int st, int lvl) {
    done[st] = true;
    dep[st] = lvl;

    for (auto &i : G[st]) 
        if (!done[i]) 
            P[0][i] = st, dfs(i,lvl+1);
}

int lca (int a, int b) {
    if (dep[a] > dep[b]) swap(a,b);

    int dif = dep[b]-dep[a];
    forn(i,MAXK) if (dif&(1<<i)) b = P[i][b];

    if (a == b) return a;
    dforn(i,MAXK)
        if (P[i][a] != P[i][b])
            a = P[i][a], b = P[i][b];

    return P[0][a];
}

int main() {
    int n; scanf("%d",&n);

    forn(i,n-1) {
        int u,v; scanf("%d %d",&u,&v); u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    P[0][0] = 0;
    dfs(0,0);

    forsn(k,1,MAXK) forn(i,n) P[k][i] = P[k-1][P[k-1][i]];

    int q; scanf("%d",&q);
    forn(i,q) {
        int r,u,v; scanf("%d %d %d",&r,&u,&v); r--, u--, v--;

        if (dep[u] > dep[v]) swap(u,v);

        int uv = lca(u,v), ru = lca(r,u), rv = lca(r,v);
        
        int rta = -1;

        if (rv == v) rta = v; // si es su hijo. Pruebo 1º con v (el más profundo, por el caso que lca(u,v) == u || lca(u,v) == v)
        else if (uv != u && ru == u) rta = u; // el otro caso que es hijo, si están en ramas distintas
        else if (dep[ru] <= dep[uv] && dep[rv] <= dep[uv]) rta = uv; // para esté punto descarté lo de abajo. pruebo ahora si está arriba: en dicho caso es lca(u,v)
        else rta = (dep[ru] > dep[uv] ? ru : rv);

        printf("%d\n",rta+1);
    }

    return 0;
}