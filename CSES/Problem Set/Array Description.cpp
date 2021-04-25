#include <bits/stdc++.h>

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

const int MAXN = 1e5+5;
const int MAXW = 104;
const int MOD = 1e9+7;

int dp[MAXN][MAXW];
int arr[MAXN];

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn (i,n) cin >> arr[i];

    forn (i,MAXW) dp[0][i] = 1;
    forn (i,n) {
        if (!arr[i])
            forsn(k,1,m+1) {
                dp[i+1][k+1] = (dp[i+1][k+1] + dp[i][k])%MOD;
                dp[i+1][k] = (dp[i+1][k] + dp[i][k])%MOD;
                dp[i+1][k-1] = (dp[i+1][k-1] + dp[i][k])%MOD;
            }
        else {
            int k = arr[i];
            dp[i+1][k+1] = (dp[i+1][k+1] + dp[i][k])%MOD;
            dp[i+1][k] = (dp[i+1][k] + dp[i][k])%MOD;
            dp[i+1][k-1] = (dp[i+1][k-1] + dp[i][k])%MOD;
        }
    }

    //forn (i,MAXW) {forn(j,n) cout << dp[j][i] << ' '; cerr << endl;}

    int sum = 0;
    if (arr[n-1]) cout << dp[n-1][arr[n-1]];
    else {
        forsn (i,1,m+1) sum = (sum+dp[n-1][i])%MOD;
        cout << sum;
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
