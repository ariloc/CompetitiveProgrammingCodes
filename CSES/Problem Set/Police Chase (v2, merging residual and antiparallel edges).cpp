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
 
int const MAXN = 505;
int const MAXM = 1005;
int const INF = 2e9;
 
vi G[MAXN];
int res[MAXN][MAXN];
int P[MAXN];
int n,m;
 
int bfs (int st, int nd) {
    queue<ii> Q;
    Q.push({st,INF});
    forn(i,n) P[i] = -1;
 
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
 
int maxflow (int src, int snk) {
    int flow = 0, mini = -1;
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
 
bitset<MAXN> done;
 
void dfs (int st) {
    done[st] = true;
 
    for (auto &i : G[st]) 
        if (!done[i] && res[st][i] > 0) dfs(i);
}
 
int main() {
    FAST_IO;
 
    cin >> n >> m;
 
    forn(i,m) {
        int u,v; cin >> u >> v; --u, --v;
        G[u].pb(v), G[v].pb(u);
        res[u][v] += 1, res[v][u] += 1;
    }
 
    cout << maxflow(0,n-1) << '\n';
 
    dfs(0);
    forn(i,n) if(done[i]) for (auto &j : G[i]) if (!done[j]) cout << i+1 << ' ' << j+1 << '\n';
 
    return 0;
}
