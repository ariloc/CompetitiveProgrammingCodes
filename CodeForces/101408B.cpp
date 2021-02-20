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

const int MAXN = 2e4+5;

vi G[MAXN],GC[MAXN]; // Grafo Condensado
vector<vi> cmps; // guardo comps para luego procesar
bitset<MAXN> done,matched,doneC;
int inDeg[MAXN], outDeg[MAXN], col[MAXN], tin[MAXN], actT = 1;

vi pila;
int tarjan (int st) {
    tin[st] = actT++;
    pila.pb(st);

    int mini = actT-1;
    for (auto &i : G[st]) {
        if (!tin[i]) mini = min(mini,tarjan(i));
        if (!matched[i]) mini = min(mini,tin[i]);
    }

    if (mini >= tin[st]) {
        cmps.pb({});
        while (!pila.empty()) {
            auto e = pila.back(); pila.pop_back();
            cmps.back().pb(e); col[e] = (int)cmps.size()-1; // 0-indexed, just in case
            matched[e] = true;
            if (e == st) break;
        }
    }

    return mini;
}

int main() {
    int t; scanf("%d",&t);
    forn(o,t) {
        int n,m; scanf("%d %d",&n,&m);

        pila.clear(), cmps.clear(), actT = 1; // para tarjan, reset
        forn(i,n) { // reset
            G[i].clear(), GC[i].clear();
            inDeg[i] = outDeg[i] = tin[i] = (done[i] = doneC[i] = matched[i] = 0);
        }

        forn(i,m) {
            int u,v; scanf("%d %d",&u,&v); u--, v--;
            G[u].pb(v);
        }

        forn(i,n) if (!tin[i]) tarjan(i); // SCC

        // reconstruyo grafo (condensado)
        int idx = 0, zero_in = 0, zero_out = 0;
        for (auto &i : cmps) {
            vi tmp;
            for (auto &j : i)  // me fijo los nodos de la componente
                for (auto &k : G[j]) tmp.pb(col[k]); // me fijo en las aristas de los nodos y me guardo componentes a las que voy
            sort(all(tmp));
            tmp.erase(unique(all(tmp)),tmp.end()); // elimino repetidos (compression)
            for (auto &j : tmp) if (j != idx) GC[idx].pb(j), inDeg[j]++, outDeg[idx]++; // transfiero aristas (NO PUEDO TENER A MI MISMO INDEGREE)

            idx++; // mantengo id del color
        }

        forn(i,cmps.size()) { // después de procesar todo
            if (!inDeg[i]) zero_in++;
            if (!outDeg[i]) zero_out++;
        }

        if (cmps.size() <= 1) cout << "0\n";
        else cout << max(zero_in,zero_out) << '\n';
    }


    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
