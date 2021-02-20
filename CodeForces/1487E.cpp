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

const int MAXN = 150005;
const int INF = 1e9+5;

ii costs[4][MAXN]; // costos con su índice en el ordenado
ii ordCosts[4][MAXN]; // auxiliar para ordenar
set<int> mex[MAXN];

int main() {
    FAST_IO;

    int n[4]; forn(i,4) cin >> n[i];
    forn(i,4) {
        forn(j,n[i]) cin >> costs[i][j].fst;
        forn(j,n[i]) ordCosts[i][j] = {costs[i][j].fst,j};
        sort(ordCosts[i],ordCosts[i]+n[i]);
        forn(j,n[i]) costs[i][ordCosts[i][j].snd].snd = j;
    }

    forn(i,3) {
        int m; cin >> m;
        forn(j,n[i+1]) mex[j].clear(); // reset
        forn(j,m) {
            int a,b; cin >> a >> b; a--, b--;
            mex[costs[i+1][b].snd].insert(costs[i][a].snd); // metemos con sus índices ordenados
        }
        forn(j,n[i+1]) { // fusionemos con el anterior para lograr mínimos
            int look = 0;
            for (auto &k : mex[j]) if (k == look) look++; else break; // sacamos el primer índice compatible más chico (en ordenado)
            if (look < n[i]) ordCosts[i+1][j].fst += ordCosts[i][look].fst;
            else ordCosts[i+1][j].fst = INF; // invalido si no es compatible con nadie, mantengo índices del segundo para mantener incompatibilidad
        }
        sort(ordCosts[i+1],ordCosts[i+1]+n[i+1]);
        bool broke = false;
        forn(j,n[i+1]) {
            // de paso actualizo índices ordenados para costs
            costs[i+1][ordCosts[i+1][j].snd].snd = j;

            if (!broke && ordCosts[i+1][j].fst == INF) {n[i+1] = j; broke = true;} // establezco nuevo tope reducido
        }
    }

    if (n[3] <= 0) cout << "-1";
    else cout << ordCosts[3][0].fst;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
