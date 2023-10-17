#include<bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;
 
int const MAXN = 1005;
int const MAXM = 1005;
ll const INF = 9e18;
 
vi G[MAXN];
ll cap[MAXN][MAXN];
ll res[MAXN][MAXN];
int P[MAXN];
int n,m;
 
ll bfs (int st, int nd) {
    forn(i,MAXN) P[i] = -1;
    queue<pair<int,ll>> Q;
    Q.push({st,INF});
 
    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();
 
        if (e.fst == nd) return e.snd;
        
        for (auto &i : G[e.fst]) {
            if (P[i] == -1 && res[e.fst][i] > 0) {
                P[i] = e.fst;
                Q.push({i,min(e.snd,res[e.fst][i])});
            }
        }
    }
 
    return -1;
}
 
ll maxflow(int src, int snk) {
    ll mini = -1, flow = 0;
    while ((mini = bfs(src,snk)) != -1) {
        flow += mini;
        int act = snk;
        while (act != src) {
            int prv = P[act];
            res[prv][act] -= mini;
            res[act][prv] += mini;
            act = prv;
        }
    }
    return flow;
}
 
int main() {
    FAST_IO;
 
    cin >> n >> m;
    forn(i,m) {
        int u,v,c; cin >> u >> v >> c; --u, --v;
        cap[u][v] += c; // multiple edges
    }
 
    int prox_libre = n;
    forn(i,n) forsn(j,i+1,n) {
        int u = i, v = j;
        if (!cap[u][v]) swap(u,v);
        if (!cap[u][v]) continue;
 
        G[u].pb(v), G[v].pb(u);
        res[u][v] = cap[u][v], res[v][u] = 0; // = 0 for clarity
 
        if (cap[v][u]) { // anti-parallel-edges
            G[v].pb(prox_libre), G[prox_libre].pb(v);
            G[prox_libre].pb(u), G[u].pb(prox_libre);
            res[v][prox_libre] = cap[v][u], res[prox_libre][v] = 0; // = 0 for clarity
            res[prox_libre][u] = cap[v][u], res[u][prox_libre] = 0;
            ++prox_libre;
        }
    }
 
    cout << maxflow(0,n-1) << '\n';
 
    return 0;
}
