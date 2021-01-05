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

const int MAXV = 1e5+2;
const int MAXE = 2e5+2;

void fs (int &x) {
    int c; x = 0;
    c = getchar_unlocked();
    if (c>'9'||c<'0') c=getchar_unlocked();
    for(; c>='0'&&c<='9'; c=getchar_unlocked())
        x = 10*x + c-'0';
}

vector<ii> G[MAXV];
bitset<MAXE> done;
int degree[MAXV],stFrom[MAXV];
vi rta;

int main() {
    int n,m; fs(n); fs(m);

    forn(i,m) {
        int u,v; fs(u); fs(v); u--; v--;
        G[u].pb({v,i}); // i as id
        G[v].pb({u,i});
        degree[u]++; degree[v]++;
    }

    forn(i,n) if (degree[i]&1) return printf("IMPOSSIBLE"), 0;

    // find Eulerian Cycle
    vi pila; pila.pb(0); int markedEdges = 0;
    while (!pila.empty()) {
        auto e = pila.back();
        if (!degree[e]) rta.pb(e), pila.pop_back();
        else {
            forsn(j,stFrom[e],G[e].size()) {
                ii i = G[e][j];
                if (!done[i.snd]) {
                    done[i.snd] = true; markedEdges++;
                    stFrom[e] = j+1;
                    degree[e]--, degree[i.fst]--;
                    pila.pb(i.fst); break;
                }
            }
        }
    }

    if (markedEdges != m) return printf("IMPOSSIBLE"), 0;
    for (auto &i : rta) printf("%d ",i+1);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
