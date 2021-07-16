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
const int INF = 1e9+5;

struct edge {
    int v,id;
};

vector<edge> G[MAXN];
vi G2[MAXN];
int tin[MAXN], actT = 1, col[MAXN];
bitset<MAXN> matched, lucky;

bool is_bipart (int st, bool myCol) {
    col[st] = myCol;
    for (auto &i : G2[st]) {
        if (col[i] == myCol) return false;
        if (col[i] == -1 && !is_bipart(i,!myCol)) return false;
    }
    return true;
}

vector<pair<ii,int>> pila;
int tarjan (int st) { // consigo componentes biconexas
    tin[st] = actT++;

    int mini = tin[st];
    for (auto &i : G[st]) {
        if (!matched[i.id]) {
            int aux = tin[st];
            matched[i.id] = true;
            pila.pb({{st,i.v},i.id});

            if (!tin[i.v]) aux = min(aux,tarjan(i.v));
            aux = min(aux,tin[i.v]);

            if (aux >= tin[st]) { // si tengo una componente
                vector<ii> pila_aux;

                auto prv = pila.back();
                do {
                    prv = pila.back(); pila.pop_back();
                    pila_aux.pb(prv.fst);
                    G2[prv.fst.fst].pb(prv.fst.snd), G2[prv.fst.snd].pb(prv.fst.fst);
                } while(prv.snd != i.id); // poppeo las aristas

                bool cond = is_bipart(i.v,false); // me fijo si el grafo formado es bipartito
                for (auto &j : pila_aux) {
                    if (!cond) lucky[j.fst] = lucky[j.snd] = true; // caso contrario, son lucky todas
                    col[j.fst] = col[j.snd] = -1; // reset, antes usé colores y ahora los vuelvo a -1
                    G2[j.fst].clear(), G2[j.snd].clear(); // limpio los grafos de aristas usadas
                }
            }

            mini = min(mini,aux);
        }
    }

    return mini;
}
 
int main() {
    int t; scanf("%d",&t);

    forn(o,t) {
        int n,m; scanf("%d %d",&n,&m);

        actT = 1; // reset contador
        forn(i,n+2) G[i].clear(), col[i] = -1, lucky[i] = 0, tin[i] = 0; // reset
        forn(i,m+2) matched[i] = false; // reset

        forn(i,m) {
            int u,v; scanf("%d %d",&u,&v); u--, v--;
            G[u].pb({v,i}), G[v].pb({u,i});
        }

        forn(i,n) if (!tin[i]) tarjan(i);

        int cnt = 0;
        forn(i,n) cnt += lucky[i];

        printf("%d\n",cnt);
    }
 
    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!