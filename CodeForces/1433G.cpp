#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const int MAXN = 1005;
const int INF = 1e9+5;

struct edges {
    int v,w;

    bool operator< (const edges &o) const {
        return w > o.w;
    }
};

vector<edges> G[MAXN];
vector<ii> edgeLst;
int D[MAXN];
int cost[MAXN][MAXN],rta[MAXN][MAXN];

void dijkstra (int st) {
    priority_queue<edges> Q;
    D[st] = 0; Q.push({st,0});

    while (!Q.empty()) {
        auto e = Q.top().v; Q.pop();

        for (auto &i : G[e]) {
            if (D[i.v] == -1 || D[i.v] > D[e] + i.w) {
                D[i.v] = D[e] + i.w;
                Q.push({i.v,D[i.v]});
            }
        }
    }
}

int main() {
    FAST_IO;

    int n,m,k; cin >> n >> m >> k;
    forn(i,m) {
        int u,v,w; cin >> u >> v >> w; u--; v--;
        G[u].pb({v,w}); G[v].pb({u,w});
        edgeLst.pb({u,v});
    }

    forn(i,n) {
        forn(j,MAXN) D[j] = -1; // reset
        dijkstra(i);
        forn(j,n) cost[i][j] = D[j];
    }

    forn(i,k) {
        int u,v; cin >> u >> v; u--; v--;
        forn(o,m) {
            ii j = edgeLst[o];
            rta[i][o] = min({cost[u][v],cost[u][j.fst]+cost[j.snd][v],cost[u][j.snd]+cost[j.fst][v]});
        }
    }

    ll s = INF;
    forn(o,m) {
        ll mySum = 0;
        forn(i,k) mySum += rta[i][o];
        s = min(s,mySum);
    }

    cout << s;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
