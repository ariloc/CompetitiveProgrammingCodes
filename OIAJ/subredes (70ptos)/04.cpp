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

const int MAXN = 6000;

vector<ii> pcs,edges;
bool adj[MAXN][MAXN];
ll deg[MAXN];

int main() {
    FAST_IO;

    freopen("subredes04.in","r",stdin);

    int n; cin >> n;
    forn(i,n) {string s; cin >> s;} // los descarto porque es para el caso particular

    int k; cin >> k;
    forn(i,k) {
        int r,m; cin >> r >> m; // nodos, aristas
        pcs.pb({r,m});
    }

    forn(i,k) {
        forn(j,MAXN) deg[j] = 0;
        forn(j,MAXN) forn(l,MAXN) adj[j][l] = 0;
        edges.clear();

        forn(j,pcs[i].snd) {
            int u,v; cin >> u >> v; u--; v--;
            deg[u]++, deg[v]++;
            adj[u][v] = adj[v][u] = 1;
            edges.pb({u,v});
        }

        ll rta = 0;
        for (auto &j : edges) {
            for (auto &p : edges) {
                if (j.fst != p.fst && j.fst != p.snd && j.snd != p.fst && j.snd != p.snd)
                    rta += (adj[j.fst][p.fst] && adj[j.snd][p.snd])+(adj[j.fst][p.snd] && adj[j.snd][p.fst]);
            }
        }

        cout << rta << '\n'; // ME OLVIDÉ ACÁ, pero luego lo dividí a mano por 4, ya que cada par de edges lo elijo dos veces, y puedo elegir un par o el otro
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
