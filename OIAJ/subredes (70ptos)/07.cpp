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
bitset<MAXN> ady[MAXN];
int touch[MAXN][MAXN]; // tomando el nodo i como central, la cantidad de aristas con un extremo en j que forman un triángulo con i
int touchT[MAXN]; // cantidad de aristas totales que forman triáng conmigo
int deg[MAXN];

int main() {
    FAST_IO;

    freopen("subredes07.in","r",stdin);

    int n; cin >> n;
    forn(i,n) {string s; cin >> s;} // los descarto porque es para el caso particular

    int k; cin >> k;
    forn(i,k) {
        int r,m; cin >> r >> m; // nodos, aristas
        pcs.pb({r,m});
    }

    forn(i,k) {
        forn(j,MAXN) ady[j].reset(), deg[j] = touchT[j] = 0;
        forn(j,MAXN) forn(l,MAXN) touch[j][l] = 0;
        edges.clear();

        forn(j,pcs[i].snd) {
            int u,v; cin >> u >> v; u--; v--;
            deg[u]++, deg[v]++;
            ady[u][v] = ady[v][u] = true;
            edges.pb({u,v});
        }

        ll rta = 0;
        for (auto &j : edges) {
            bitset<MAXN> comm = (ady[j.fst]&ady[j.snd]);
            forn(l,MAXN) if (comm[l]) {
                // todos los triangulos antes formados con los que soy compatible: todos - lo que tienen como extremo a j.fst - tiene extremo j.snd
                // (no hay intersec porque sólo hay una arista que tiene a ambos)
                ll triangCompat = touchT[l] - touch[l][j.fst] - touch[l][j.snd];
                rta += triangCompat;
                touchT[l]++, touch[l][j.fst]++, touch[l][j.snd]++;
            }
        }

        cout << rta << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
