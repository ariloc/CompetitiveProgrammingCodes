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

const int MAXN = 1e5+2;
const int INF_INT = 2e9+5;
const ll INF = 9e18;

int g[3][MAXN];

ll calc (ll x, ll y, ll z) {
    return (x-y)*(x-y) + (y-z)*(y-z) + (z-x)*(z-x);
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int sz[3]; forn(k,3) cin >> sz[k];
        forn(k,3) g[k][sz[k]] = INF_INT; // dummys

        forn(k,3) forn(j,sz[k]) cin >> g[k][j];
        forn(k,3) sort(g[k],g[k]+sz[k]);

        // eliminemos los repetidos inplace (así la ternary no se rompe pues func creciente strict)
        forn(k,3) {
            int idx = 1;
            forsn(j,1,sz[k]) if (g[k][j] != g[k][j-1]) g[k][idx++] = g[k][j];
            sz[k] = idx;
        }

        ll mini = INF;
        forn(k,3) forn(j,sz[k]) {
            int nxt = (k+1)%3, nxtnxt = (k+2)%3;
            forn(l,2) {
                swap(nxt,nxtnxt);
                int up1 = lower_bound(g[nxt],g[nxt]+sz[nxt],g[k][j])-g[nxt];
                if (up1 < sz[nxt]) {
                    int up2 = lower_bound(g[nxtnxt],g[nxtnxt]+sz[nxtnxt],g[nxt][up1])-g[nxtnxt];
                    if (up2 < sz[nxtnxt]) {

                        int av = g[k][j], cv = g[nxtnxt][up2];

                        int aux = upper_bound(g[nxt],g[nxt]+sz[nxt],cv)-g[nxt];
                        int low = up1-1, high = aux; // mínimo índice y máximo abierto-abierto
                        while (high-low > 1) {
                            int mid = (high+low)/2;
                            if (calc(av,g[nxt][mid],cv) < calc(av,g[nxt][mid+1],cv)) high = mid;
                            else low = mid;
                        }

                        if (high >= up1 && high < aux) mini = min(mini,calc(av,g[nxt][high],cv));
                        if (low >= up1 && low < aux) mini = min(mini,calc(av,g[nxt][low],cv));
                    }
                }
            }
        }

        cout << mini << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
