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

const int INF = 1e9+5;

set<pair<ii,char>> edges;

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    int cyclesEq = 0, cycles = 0;
    forn(i,m) {
        char typ; cin >> typ;

        if (typ == '+') {
            int u,v; char c; cin >> u >> v >> c;
            edges.insert({{u,v},c});
            if (edges.count({{v,u},c})) cyclesEq++;
            auto it = edges.lower_bound({{v,u},-INF});
            if (it != edges.end()) {
                auto aux = (*it);
                if (aux.fst.fst == v && aux.fst.snd == u) cycles++;
            }
        }
        else if (typ == '-') {
            int u,v; cin >> u >> v;
            auto it = edges.lower_bound({{u,v},-INF});
            auto me = (*it);
            edges.erase(it);
            it = edges.lower_bound({{v,u},-INF});
            if (it != edges.end()) {
                auto aux = (*it);
                if (aux.fst.fst == v && aux.fst.snd == u) {
                    cycles--;
                    if (aux.snd == me.snd) cyclesEq--;
                }
            }
        }
        else {
            int k; cin >> k;
            if (k&1) cout << (cycles > 0 ? "YES" : "NO") << '\n';
            else cout << (cyclesEq > 0 ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
