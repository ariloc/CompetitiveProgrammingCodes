#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 2502;
const ll INF = 1e18;

struct edges {
    int v,w;
};

vector<edges> G[MAXN]; vi RG[MAXN];
bitset<MAXN> done;
bool reachable[MAXN][2];
ll D[MAXN];
int n,m;

void dfs1 (int st) {
    reachable[st][0] = true;
    for (auto &i : RG[st])
        if (!reachable[i][0]) dfs1(i);
}

void dfs2 (int st) {
    reachable[st][1] = true;
    for (auto &i : G[st])
        if (!reachable[i.v][1]) dfs2(i.v);
}

int main() {
    forsn(i,1,MAXN) D[i] = INF;
    scanf("%d %d",&n,&m);

    forn(i,m) {
        int u,v,w; scanf("%d %d %d",&u,&v,&w); u--; v--;
        G[u].pb({v,-w}); // lo guardo al revés
        RG[v].pb(u); // lo guardo al revés
    }

    dfs1(n-1); // identify which ones are reachable from n-1
    dfs2(0); // identify which ones are reachable from 0

    forn(i,n-1) forn(u,n) for (auto &v : G[u])
        D[v.v] = min(D[v.v],D[u]+v.w);

    bool negCycle = false;
    forn(u,n) for (auto &v : G[u])
        if (D[u]+v.w < D[v.v] and (reachable[u][0] and reachable[u][1])) {negCycle = true; break;}

    if (negCycle) printf("-1");
    else printf("%lld",-D[n-1]);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMER/O!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
