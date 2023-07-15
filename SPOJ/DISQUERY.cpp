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

int const MAXK = 18;
int const MAXN = 1<<MAXK;
int const INF = 2e9;

struct edge {
    int v,w;
};

vector<edge> G[MAXN];
bitset<MAXN> done;
int P[MAXK][MAXN], D[MAXN], pmin[MAXK][MAXN], pmax[MAXK][MAXN];

void dfs (int st, int lvl = 0) {
    done[st] = true;
    D[st] = lvl;

    for (auto &i : G[st]) {
        if (!done[i.v]) {
            dfs(i.v,lvl+1);
            P[0][i.v] = st;
            pmin[0][i.v] = pmax[0][i.v] = i.w;
        }
    }
}

int lca (int u, int v) {
    if (D[u] > D[v]) swap(u,v);
    int dif = D[v]-D[u];
    forn(i,MAXK) if (dif&(1<<i)) v = P[i][v];
    if (u == v) return u;
    dforn(i,MAXK)
        if (P[i][u] != P[i][v])
            u = P[i][u], v = P[i][v];
    return P[0][u];
}

int getmini (int x, int d) {
    int mini = INF;
    dforn(i,MAXK)
        if (d&(1<<i)) 
            mini = min(mini, pmin[i][x]), x = P[i][x];
    return mini;
}

int getmaxi (int x, int d) {
    int maxi = -INF;
    dforn(i,MAXK)
        if (d&(1<<i))
            maxi = max(maxi, pmax[i][x]), x = P[i][x];
    return maxi;
}

int main() {
    int n; scanf("%d",&n);
    forn(i,n-1) {
        int u,v,w; scanf("%d %d %d",&u,&v,&w); u--, v--;
        G[u].pb({v,w}), G[v].pb({u,w});
    }

    forn(k,MAXK) forn(i,n)
        pmin[k][i] = INF, pmax[k][i] = -INF;

    dfs(0);

    forsn(k,1,MAXK) forn(i,n) {
        P[k][i] = P[k-1][P[k-1][i]];
        pmin[k][i] = min(pmin[k-1][i], pmin[k-1][P[k-1][i]]);
        pmax[k][i] = max(pmax[k-1][i], pmax[k-1][P[k-1][i]]);
    }

    int q; scanf("%d",&q);
    forn(_,q) {
        int u,v; scanf("%d %d",&u,&v); u--, v--;
        int p = lca(u,v);
        int du = D[u]-D[p], dv = D[v]-D[p];
        int mini = min(getmini(u,du), getmini(v,dv));
        int maxi = max(getmaxi(u,du), getmaxi(v,dv));
        printf("%d %d\n",mini,maxi);
    }

    return 0;
}
