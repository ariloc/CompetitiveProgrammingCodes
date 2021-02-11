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

const int MAXN = 1010;
const int MOD = 1e9+7;
const int INF = 1e9+5;

int follow[MAXN], dp[MAXN][MAXN], ways[MAXN][MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int k,n; cin >> n >> k;
        forn(j,n) cin >> follow[j+1];

        forn(j,n+3) forn(l,n+3) dp[j][l] = 0, ways[j][l] = 0; // reset
        //forsn(j,1,n+3) forsn(l,1,n+3) dp[j][l] = -INF;
        forn(j,n+3) ways[j][0] = 1;

        forsn(j,1,n+1) {
            forn(l,k+1) dp[j][l] = dp[j-1][l], ways[j][l] = ways[j-1][l];
            forsn(l,1,k+1) {
                if (dp[j-1][l-1]+follow[j] > dp[j][l]) {
                    dp[j][l] = dp[j-1][l-1]+follow[j];
                    ways[j][l] = ways[j-1][l-1];
                }
                else if (dp[j-1][l-1]+follow[j] == dp[j][l])
                    ways[j][l] = (ways[j-1][l-1]+ways[j][l])%MOD;

                //dbg(dp[j-1][l-1]); dbg(follow[j]); dbg(dp[j][l]); dbg(ways[j][l]); dbg(j); dbg(l);
            }
        }

        cout << ways[n][k] << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
