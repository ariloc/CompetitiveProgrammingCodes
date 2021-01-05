#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 2e5+2;

vi G[MAXN],path,cycle;
bitset<MAXN> done,done2;

void dfs (int st, int prev) {
    done[st] = true;
    path.pb(st);

    for (auto &i : G[st]) {
        if (!done[i]) dfs(i,st);
        else if (i != prev && prev != -1) {
            while (!path.empty()) {
                auto e = path.back(); path.pop_back();
                cycle.pb(e); done2[e] = true;
                if (e == i) break;
            }
        }
        if (!cycle.empty()) break; // salgo si encontré ciclo
    }
    if (!cycle.empty()) return; // salgo y no hago pop_back en path

    path.pop_back(); // si llegué a una hoja, vuelvo
}

int dfs2 (int st) {
    done2[st] = true;

    int s = 0;
    for (auto &i : G[st])
        if (!done2[i]) s += dfs2(i);

    return s+1;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        ll rta = ((ll)n*((ll)n-1))/2LL;

        forn(j,n) {G[j].clear(); done[j] = done2[j] = false;} // reset
        path.clear(); cycle.clear();

        forn(j,n) {
            int u,v; cin >> u >> v; u--, v--;
            G[u].pb(v); G[v].pb(u);
        }
        dfs(0,-1); // encuentro el ciclo
        int rest = n;
        for (auto &j : cycle) {
            done2[j] = false; // lo desmarco temporalmente porque antes lo marqué
            int v = dfs2(j); rest -= (v-1);
            rta += (ll)(v-1)*(rest-1); // cuento desde los de esta componente al resto
        }

        rta += (ll)cycle.size()*((ll)cycle.size()-1)/2LL; // agrego caminos dentro del ciclo

        cout << rta << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
