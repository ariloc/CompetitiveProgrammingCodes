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
int const INF = 2e9;

vi G[MAXN],G2[MAXN];
bool ady[MAXN][MAXN];
int res[MAXN][MAXN];
int P[MAXN];

int bfs (int st, int nd) {
    forn(i,MAXN) P[i] = -1;
    queue<ii> Q;
    Q.push({st,INF});

    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        if (e.fst == nd) return e.snd;

        for (auto &i : G[e.fst])
            if (P[i] == -1 && res[e.fst][i] > 0) {
                P[i] = e.fst;
                Q.push({i,min(e.snd,res[e.fst][i])});
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

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,m) {
        int u,v; cin >> u >> v; --u, --v;
        ady[u][v] = 1;
    }

    int prox_libre = n;
    forn(i,n) forsn(j,i+1,n) {
        int u = i, v = j;
        if (!ady[u][v]) swap(u,v);
        if (!ady[u][v]) continue;
        G[u].pb(v), G[v].pb(u);
        G2[u].pb(v);
        res[u][v] = 1;
        
        if (ady[v][u]) {
            G[v].pb(prox_libre), G[prox_libre].pb(v);
            G[prox_libre].pb(u), G[u].pb(prox_libre);
            G2[v].pb(prox_libre), G2[prox_libre].pb(u);
            res[v][prox_libre] = res[prox_libre][u] = 1;
            ++prox_libre;
        }
    }

    int paths = maxflow(0,n-1);
    cout << paths << '\n';

    forn(i,paths) {
        vi cpath;
        int act = 0;
        while (act != n-1) {
            if (act < n) cpath.pb(act);
            int auxi = act;
            while (res[act][G2[act].back()]) G2[act].pop_back();
            act = G2[act].back();
            G2[auxi].pop_back();
        }
        cpath.pb(n-1);
        cout << (int)cpath.size() << '\n';
        for (auto &j : cpath) cout << j+1 << ' ';
        cout << '\n';
    }

    return 0;
}
