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

const int MAXN = 505;

int ady[MAXN][MAXN],vals[MAXN];

int main() {
    FAST_IO;

    forn(i,MAXN) forn(j,MAXN) ady[i][j] = -1;

    int n,m; cin >> n >> m;

    forn(i,n) cin >> vals[i];

    /* caso óptimo -> todos nodos de 1e6 y solo se agrega una arista de 1 en c/paso
       Conclusión: mientras más agrego se mantiene igual. Salgo del caso
       y empeoro, porque sube el divisor o baja el dividendo. Busquemos entonces
       el mejor par de vértices.
    */

    forn(i,m) {
        int u,v,w; cin >> u >> v >> w; u--, v--;
        ady[u][v] = ady[v][u] = w;
    }

    ld maxi = 0;
    forn(i,n) forsn(j,i+1,n) if (ady[i][j] != -1) maxi = max(maxi,(vals[i]+vals[j])/(ld)ady[i][j]);

    cout << fixed << setprecision(15) << maxi;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
