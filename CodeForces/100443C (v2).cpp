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
typedef long double ld;

const int MAXN = 205;
const ll INF = 9e18;

struct pt {
    int x,y,z;
};

pt loc[MAXN];
ld D[MAXN][MAXN];
int P[MAXN][MAXN];

int main() {
    FAST_IO;

    forn(i,MAXN) forn(j,MAXN) D[i][j] = INF;
    forn(i,MAXN) forn(j,MAXN) P[i][j] = i;
    forn(i,MAXN) P[i][i] = -1, D[i][i] = 0;

    int n,m; cin >> n >> m;
    forn(i,n) cin >> loc[i].z >> loc[i].x >> loc[i].y;
    forn(i,m) {
        int u,v; string s;
        cin >> u >> v >> s;

        ld cateto = hypotl(abs(loc[u].x-loc[v].x), abs(loc[u].y-loc[v].y));
        ld dist = hypotl(cateto, abs(loc[u].z-loc[v].z)*5LL);
        if (s == "walking" || s == "stairs") {
            D[u][v] = min(D[u][v], dist);
            D[v][u] = min(D[v][u], dist);
        }
        if (s == "lift") {
            D[u][v] = min(D[u][v],(ld)1);
            D[v][u] = min(D[v][u],(ld)1);
        }
        if (s == "escalator") {
            D[u][v] = min(D[u][v], (ld)1);
            D[v][u] = min(D[v][u], dist*3);
        }
    }

    forn(k,n) forn(i,n) forn(j,n) if (k != i && i != j) {
        ld aux = D[i][k] + D[k][j];
        if (aux < D[i][j]) {
            D[i][j] = aux;
            P[i][j] = P[k][j];
        }
    }

    int q; cin >> q;
    forn(o,q) {
        int u,v; cin >> u >> v;
        vi nodes;
        int act = v;
        while (act != -1) {
            nodes.pb(act);
            act = P[u][act];
        }
        reverse(all(nodes));
        for (auto &i : nodes) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}