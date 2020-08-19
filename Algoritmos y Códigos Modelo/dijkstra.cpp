#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <bitset>
#define forn(i, n) for(int i = 0; i < int(n); ++i)
using namespace std;

const int MAXN = 1024;


struct hedge{
    int v, d;
    bool operator<(const hedge &other) const {
        return d > other.d;
    }
};

int N, M;
vector<hedge> G[MAXN];
bitset<MAXN> done;
vector<int> D, P;

void dijkstra(int r){
    priority_queue<hedge> q;
    D[r] = 0;
    q.push({r, 0});
    while( not q.empty() ){
        auto v = q.top().v; q.pop();
        if (done[v]) continue;
        done[v] = true;
        //cout << "La distancia de " << r << " a " << v.v << " es " << v.d << endl;
        for(auto &w: G[v])
            if( D[w.v] == -1 or D[w.v] > D[v] + w.d) {
                D[w.v] = D[v] + w.d;
                P[w.v] = v;
                q.push({w.v, D[w.v]});
            }
    }
}

int main(){
    freopen("grafo.in", "r", stdin);

    cin >> N >> M;
    forn(i, M){
        int u, v, d;
        cin >> u >> v >> d;
        G[u].push_back({v, d});
        G[v].push_back({u, d}); // no dirigido
    }

    D.resize(N, -1);
    P.resize(N, -1);
    dijkstra(0);

    vector<int> camino;
    for(int v = 4; v != 0; v = P[v]) {
        camino.push_back(v);
    }
    reverse(camino.begin(), camino.end());

    cout << "Camino de 0 a 4:\n0";
    for(auto &v : camino)
        cout<< " -> " << v;

    return 0;
}
