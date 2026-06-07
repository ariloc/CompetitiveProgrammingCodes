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

int dp[MAXN][MAXN];
int arr[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;

    forn(i,n) cin >> arr[i];

    forn(i,n) forn(j,n) dp[i][j] = INF;
    forn(i,n) {
        dp[i][i] = 1;
        if (i < n-1 && arr[i] == arr[i+1])
            dp[i][i+1] = 1;
    }
    // Last movement is always a palindrome, so I can just reuse that movement
    // when both extremes are equal
    forsn(len,2,n+1) {
        forn(i,n-len+1) {
            int j = i+len-1;
            if (arr[i] != arr[j])
                dp[i][j] = min(dp[i][j], min(dp[i+1][j], dp[i][j-1]) + 1);
            else if (j-i > 1) {
                dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
            }
            forsn(k,i,j)
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
        }
    }

    cout << dp[0][n-1] << '\n';

    return 0;
}
