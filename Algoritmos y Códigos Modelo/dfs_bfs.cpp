#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define forn(i, n) for(int i = 0; i < int(n); ++i)
using namespace std;

const int MAXN = 1024;

int N, M;
vector<int> G[MAXN];
vector<int> visitado;

int dfs(int v){
    visitado[v] = true;
    cout << "DFS - Estoy en " << v << endl;
    for(auto &w: G[v])
        if( not visitado[w])
             dfs(w);
}

void bfs(int v){
    queue<int> q;
    visitado[v] = true;
    q.push(v);
    while( not q.empty() ){
        v = q.front(); q.pop();
        cout << "BFS - Estoy en " << v << endl;
        for(auto &w: G[v])
            if( not visitado[w]){
                visitado[w] = true;
                q.push(w);
            }
    }
}

int main(){
    freopen("grafo.txt", "r", stdin);

    cin >> N >> M;
    forn(i, M){
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    visitado.resize(N, false);
    dfs(0);

    visitado.clear();
    visitado.resize(N, false);
    bfs(0);

    return 0;
}
