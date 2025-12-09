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

int const INF = 2e9;

int const MAXD = 62;
int const MAXMOV = 35;

int dp[MAXD][MAXMOV][2];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        ll n; int k; cin >> n >> k;

        forn(i,MAXD) forn(j,MAXMOV) dp[i][j][0] = dp[i][j][1] = -INF;
        dp[0][0][0] = 0;
        forsn(i,1,MAXD) forn(j,MAXMOV) {
            if (n & (1LL<<(i-1))) {
                dp[i][j][0] = max(dp[i][j][0],dp[i-1][j][0]);

                dp[i][j][1] = max(dp[i][j][1],dp[i-1][j][1]+1);
                if(j) dp[i][j][1] = max(dp[i][j][1],dp[i-1][j-1][0]+1);
            }
            else {
                dp[i][j][0] = max(dp[i][j][0],dp[i-1][j][0]);
                dp[i][j][0] = max(dp[i][j][0],dp[i-1][j][1]);

                if(j) dp[i][j][1] = max(dp[i][j][1],dp[i-1][j-1][1]+1);
                if(j) dp[i][j][1] = max(dp[i][j][1],dp[i-1][j-1][0]);
            }
        }

        int maxi = 0;
        forn(i,min(MAXMOV,k+1))
            maxi = max(maxi,max(dp[MAXD-1][i][0],dp[MAXD-1][i][1])+(k-i));
        cout << maxi << '\n';
    }

    return 0;
}
