#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 305;
int const MOD = 1e9+7;

int dp[MAXN][MAXN][MAXN];
int arr[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        forn(i,n) cin >> arr[i];

        forn(i,n+1) forn(j,n+1) forn(k,n+1) dp[i][j][k] = 0;
        dp[0][0][0] = 1;

        forsn(i,1,n+1) {
            forn(j,n+1) {
                forn(k,j+1) {
                    dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k])%MOD;

                    if (arr[i-1] >= j) {
                        dp[i][arr[i-1]][k] = (dp[i][arr[i-1]][k] + dp[i-1][j][k])%MOD;
                    }
                    else if (arr[i-1] >= k) {
                        dp[i][j][arr[i-1]] = (dp[i][j][arr[i-1]] + dp[i-1][j][k])%MOD;
                    }
                }
            }
        }

        int s = 0;
        forn(j,n+1) forn(k,j+1) s = (s+dp[n][j][k])%MOD;
        cout << s << '\n';
    }

    return 0;
}
