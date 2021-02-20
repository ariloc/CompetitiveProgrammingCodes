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
const int MAXTYP = 105;
const int INF = 1e9+5;

vi G[MAXN];
int typ[MAXN], D[MAXN][MAXTYP];
bitset<MAXN> done;

int main() {
    FAST_IO;
    forn(i,MAXN) forn(j,MAXTYP) D[i][j] = INF; // reset

    int n,m,k,s; cin >> n >> m >> k >> s;

    forn(i,n) cin >> typ[i], typ[i]--;

    forn(i,m) {
        int u,v; cin >> u >> v; u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    forn(i,k) { // bfs!
        queue<ii> Q;
        forn(j,n) done[j] = 0; // reset
        forn(j,n) if (typ[j] == i) Q.push({j,0}), D[j][i] = 0, done[j] = true;

        while (!Q.empty()) {
            auto e = Q.front(); Q.pop();

            for (auto &j : G[e.fst]) {
                if (done[j]) continue;
                D[j][i] = min(D[j][i],e.snd+1);
                done[j] = true;
                Q.push({j,e.snd+1});
            }
        }
    }

    forn(i,n) {
        sort(D[i],D[i]+MAXTYP);
        ll sum = 0;
        forn(j,s) sum += D[i][j];
        cout << sum << ' ';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
