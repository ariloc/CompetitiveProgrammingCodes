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

const int MAXN = 2e5+5;

struct edge {
    int u,v; ll w;

    const operator< (const edge &o) const{
        return w < o.w;
    }
};

struct arista {
    int v; ll w;

    const operator< (const arista &o) const{
        return w > o.w;
    }
};

vector<edge> edges;
vector<arista> G[MAXN];
map<ii,ll> tmpEdges;
bitset<MAXN> done;
ll D[MAXN];

void dijkstra(int st) {
    forn(j,MAXN) D[j] = -1; // reset
    done.reset();
    priority_queue<arista> Q;
    Q.push({st,0}); D[st] = 0;

    while (not Q.empty()) {
        auto e = Q.top().v; Q.pop();
        if (done[e]) continue;
        done[e] = true;

        for (auto &i : G[e]) {
            if (D[i.v] == -1 or D[i.v] > D[e] + i.w) {
                D[i.v] = D[e] + i.w;
                Q.push({i.v,D[i.v]});
            }
        }
    }

    forn(i,MAXN) {
        if (st == i or D[i] == -1) continue;
        int a = st, b = i;
        if (a > b) swap(a,b);
        tmpEdges[{a,b}] = D[i]; // actualizo o creo correspondientemente
    }
}

int main() {
    FAST_IO;

    int n,m,k; cin >> n >> m >> k;
    forn(i,m) {
        int u,v,w; cin >> u >> v >> w; u--; v--;
        edges.pb({u,v,w});
    }

    sort(all(edges));

    set<int> nodes;
    forn(i,min(m,k)) {
        G[edges[i].u].pb({edges[i].v,edges[i].w});
        G[edges[i].v].pb({edges[i].u,edges[i].w});
        nodes.insert(edges[i].u);
        nodes.insert(edges[i].v);
    }

    for (auto &i : nodes) dijkstra(i);

    vector<ll> rta;
    for (auto &i : tmpEdges) rta.pb({i.snd});
    sort(all(rta));
    //for (auto &i : rta) cout << i << ' ';

    cout << rta[k-1];

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
