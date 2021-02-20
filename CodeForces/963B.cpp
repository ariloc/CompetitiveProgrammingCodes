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

const int MAXN = 2e5+5;
const int INF = 1e9+5;

int child[MAXN];
bitset<MAXN> done;
vi rta;
vi G[MAXN];

/*  OK, tenemos que eliminar nodos con grado par
    en cada paso eliminamos cantidades pares de aristas
    eso implica que para eliminar todas las artistas (que implica de sacar los nodos),
    por lo que si restamos par, para que desaparezcan todas tiene que ser la cantidad
    original de aristas, par. Eso implica que la cantidad de nodos, al ser un árbol,
    debe ser impar (resto de casos imposible).

    Entonces procederé solo con cantidad impar de nodos. Si me paro en un nodo, tendré
    subárboles de cantidad de nodos pares e impares. Esto implica que si tengo cantidad de nodos impar,
    la cantidad de subárboles impares tiene que ser impar. Porque al fin y al cabo
    par + par... es par, y si me sumo al que estoy parado es impar. Entonces si tengo alguno
    más impar volvería a ser par, lo que cual no puede suceder. Así la cantidad
    de subárboles impares es par. Dado esto, primero resolveré entonces los subárboles
    pares, ya que al tener cantidad de aristas impar, sumado la que conecta conmigo que lo hace
    par, debería resolverse solo como un SUBPROBLEMA (DFS recursivo). Si es impar, lo
    resolveré después de todo lo de los pares, así lo reduzco a lo más chico, que sería que me quede un
    solo nodo digamos. Lo hacemos en recursivo además porque es importante resolver primero
    cerca de las hojas para no dejar nada colgando mal. Así entonces cuando vuelva, me quedarán
    solo nodos simples en cantidad par (incluyéndome, pues cantidad par de impares más impar es impar de nodos, como es),
    determinándome grado par, pudiendo eliminarse todo.
*/

int dfs1 (int st) {
    done[st] = true;

    int sum = 0;
    for (auto &i : G[st])
        if (!done[i]) sum += dfs1(i); // si tenés un sum usalo y ponele el += EH!

    return child[st] = sum+1;
}

void dfs2 (int st) {
    done[st] = true;

    for (auto &i : G[st])
        if (!done[i] && !(child[i]&1)) dfs2(i);

    rta.pb(st);

    for (auto &i : G[st])
        if (!done[i] && (child[i]&1)) dfs2(i);
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) {
        int x; cin >> x; x--;
        if (x >= 0) G[i].pb(x), G[x].pb(i);
    }

    if (!(n&1)) return cout << "NO", 0;

    dfs1(0); done.reset();
    dfs2(0);

    cout << "YES\n";
    for (auto &i : rta) cout << i+1 << '\n';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
