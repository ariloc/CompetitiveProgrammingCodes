
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
typedef unsigned long long ull;
typedef pair<int,int> ii;

const int MAXN = 2e5+5;
const int INF = 1e9+5;

int dp[MAXN][2], boss[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        //memset(dp,-1,sizeof(dp));
        int n; cin >> n;
        forn(j,n) cin >> boss[j];
        forn(j,n+5) dp[j][0] = dp[j][1] = INF;
        dp[0][0] = 0;
        forn(j,n) forn(k,2) {
            dp[j+1][!k] = min(dp[j+1][!k],dp[j][k]+(boss[j] && !k));
            dp[j+2][!k] = min(dp[j+2][!k],dp[j][k]+(boss[j] && !k)+(boss[j+1] && !k));
        }

        //forn(j,2) {forn(k,n) cerr << dp[j][k] << ' '; cerr << endl;}

        cout << min(dp[n][0],dp[n][1]) << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
