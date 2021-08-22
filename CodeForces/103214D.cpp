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

const int INF = 2e9;
const int MAXN = 1e5+5;

struct edge {
    int u,v,w;

    bool operator< (const edge &o) const {
        return w < o.w;
    }
};

struct G_edge {
    int v,w,id;
};

vector<G_edge> G[MAXN]; // fst -> destino, snd -> id
pair<ii,ii> best[MAXN]; // fst -> primero mejor, snd -> segundo mejor (más corto)
int cols[MAXN];

bool dfs (int st, int col = 0) {
    cols[st] = col;

    for (auto &i : G[st])
        if ((cols[i.v] == col) || (cols[i.v] == -1 && !dfs(i.v,1-col)))
            return false;
       
    return true;
}

bool posib (int D, int n, int m, vector<edge> &edges) {
    forn(i,n+2) {
        G[i].clear();
        best[i] = {{INF,-1},{INF,-1}}; // distancia, id
        cols[i] = -1;
    }

    // armo el grafo
    forn(i,m) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (w < D)
            G[u].pb({v,w,i}), G[v].pb({u,w,i});
    }

    // para cada nodo, saco las dos aristas más cortas
    forn(i,n) {
        for (auto &j : G[i]) {
            if (j.w < best[i].fst.fst) {
                swap(best[i].fst,best[i].snd);
                best[i].fst = {j.w,j.id};
            }
            else if (j.w < best[i].snd.fst)
                best[i].snd = {j.w,j.id};
        }
    }

    // ¿hay dos aristas consecutivas que sumen menor que D?
    forn(i,n) for (auto &j : G[i]) {
        ii mini_j = (best[j.v].fst.snd == j.id ? best[j.v].snd : best[j.v].fst);
        if (mini_j.snd != -1 && (j.w + mini_j.fst) < D)
            return false;
    }

    // ¿Es bicoloreable?
    bool ret = true;
    forn(i,n) if (cols[i] == -1 && !dfs(i)) ret = false;

    return ret;
}

int main() {
    FAST_IO;
    
    int t; cin >> t;
    forn(i,t) {
        int n,m; cin >> n >> m;

        vector<edge> edges;

        forn(j,m) {
            int u,v,w; cin >> u >> v >> w;
            edges.pb({u,v,w});
        }

        sort(all(edges));

        ll low = 1, high = INF+1;
        while (high - low > 1) {
            ll mid = (high+low)/2;

            if (posib(mid,n,m,edges)) low = mid;
            else high = mid;
        }

        if (posib(INF+1,n,m,edges)) cout << "INF\n";
        else cout << low << '\n';
    }

    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!