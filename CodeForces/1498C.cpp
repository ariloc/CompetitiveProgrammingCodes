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

const int MAXN = 1005;
const int MOD = 1e9+7;

int dp[MAXN][MAXN][2]; // 1 is right, 0 is left

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n,k; cin >> n >> k;

        forn(i,n+3) forn(j,k+3) dp[i][j][0] = dp[i][j][1] = 0; // reset

        dp[1][k][1] = 1;

        dforsn(i,1,k+1) {
            int acc = 0;
            forsn(j,1,n+1) {
                acc += dp[j][i][1], acc %= MOD;
                dp[j-1][i-1][0] += acc, dp[j-1][i-1][0] %= MOD;
            }
            acc = 0;
            dforsn(j,1,n+1) {
                acc += dp[j][i][0], acc %= MOD;
                dp[j+1][i-1][1] += acc, dp[j+1][i-1][1] %= MOD;
            }
        }

        int r = 0;
        forsn(i,1,k+1) forn(j,n+2) {
            r += dp[j][i][0], r %= MOD;
            r += dp[j][i][1], r %= MOD;
        }

        cout << r << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!