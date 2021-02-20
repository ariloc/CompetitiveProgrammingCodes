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

const int MAXN = 1e5+5;
const int MAXW = 52;

struct edges {
    int v,w;
};

struct nodoDijk {
    int v; ll w,pW; // actual, peso acc, peso del que llego (-1 si no va el turno)

    bool operator< (const nodoDijk &o) const {
        if (w == o.w) return pW > o.pW; // por el peso del padre, just in case
        return w > o.w;
    }
};

int DM[MAXN][MAXW], D[MAXN]; // distancia si es midpoint, distancia común
vector<edges> G[MAXN];

void dijkstra (int st) {
    priority_queue<nodoDijk> Q;
    Q.push({st,0,-1}); D[st] = 0;

    while (!Q.empty()) {
        auto e = Q.top(); Q.pop();

        for (auto &i : G[e.v]) {
            if (e.pW == -1) { // si es -1, implica que no es midpoint
                if (DM[i.v][i.w] == -1 || DM[i.v][i.w] > D[e.v]) { // vamos a un midpoint
                    DM[i.v][i.w] = D[e.v];
                    Q.push({i.v,D[e.v],i.w});
                }
            }
            else { // salimos de un midpoint
                ll calc = DM[e.v][e.pW] + (e.pW+i.w)*(e.pW+i.w);
                if (D[i.v] == -1 || D[i.v] > calc) {
                    D[i.v] = calc;
                    Q.push({i.v,calc,-1});
                }
            }
        }
    }
}

int main() {
    FAST_IO;

    forn(i,MAXN) forn(j,MAXW) DM[i][j] = -1;
    forn(i,MAXN) D[i] = -1;

    int n,m; cin >> n >> m;
    forn(i,m) {
        int u,v,w; cin >> u >> v >> w; u--, v--;
        G[u].pb({v,w}), G[v].pb({u,w});
    }

    dijkstra(0);

    forn(i,n) cout << D[i] << ' ';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
