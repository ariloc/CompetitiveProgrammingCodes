#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 505;
int const INF = 10000;

int dp[MAXN][MAXN][2];
int arr[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;

    forn(i,n) cin >> arr[i];

    forn(i,n) forn(j,n) dp[i][j][0] = dp[i][j][1] = INF;
    forn(i,n) {
        dp[i][i][1] = 1;
        if (i < n-1 && arr[i] == arr[i+1])
            dp[i][i+1][1] = 1;
    }
    forsn(len,2,n+1) {
        forn(i,n-len+1) {
            int j = i+len-1;
            if (arr[i] != arr[j])
                forn(k,2) dp[i][j][0] = min(dp[i][j][0], min(dp[i+1][j][k], dp[i][j-1][k]) + 1);
            else if (j-i > 1) {
                dp[i][j][1] = min(dp[i][j][1], dp[i+1][j-1][1]);
                dp[i][j][1] = min(dp[i][j][1], dp[i+1][j-1][0]+1);
            }
            forsn(k,i,j)
                forn(l,2) forn(o,2)
                    dp[i][j][l] = min(dp[i][j][l], dp[i][k][o]+dp[k+1][j][l]);
            dforsn(k,i+1,j+1)
                forn(l,2) forn(o,2)
                    dp[i][j][l] = min(dp[i][j][l], dp[i][k-1][l]+dp[k][j][o]);
        }
    }

    int mini = INF;
    forn(k,2) mini = min(mini, dp[0][n-1][k]);

    cout << mini << '\n';

    return 0;
}
