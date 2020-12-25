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

const int MAXN = 72;
const int INF = 1e9+5;

int grid[MAXN][MAXN];
int dp[MAXN][MAXN]; // (en cada fila) agarrando k elementos, el mayor número con el resto dicho
int dpBst[MAXN][MAXN]; // para cada fila, la mejor suma posible en dicha con el resto corresp.

int main() {
    FAST_IO;
    forn(i,MAXN) forn(j,MAXN) dpBst[i][j] = -INF; // init

    int n,m,k; cin >> n >> m >> k;
    forn(i,n) forn(j,m) cin >> grid[i][j];

    forn(i,n) {
        // init
        forn(e,m/2+1) forn(r,k) dp[e][r] = -INF;
        dp[0][0] = 0;

        // fill
        forn(j,m) dforn(e,m/2) forn(r,k) {
            int ind = (r+grid[i][j])%k;
            dp[e+1][ind] = max(dp[e+1][ind],dp[e][r]+grid[i][j]);
        }

        // get best
        forn(e,m/2+1) forn(r,k) dpBst[i][r] = max(dpBst[i][r],dp[e][r]);
    }

    int tmp[MAXN];
    forsn(i,1,n) {
        forn(j,k) tmp[j] = dpBst[i][j];
        forn(r1,k) forn(r2,k) {
            int ind = (dpBst[i][r1]+dpBst[i-1][r2])%k;
            tmp[ind] = max(tmp[ind],dpBst[i][r1]+dpBst[i-1][r2]);
        }
        forn(j,k) dpBst[i][j] = tmp[j];
    }

    cout << dpBst[n-1][0];

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
