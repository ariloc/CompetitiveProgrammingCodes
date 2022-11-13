#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int MAXN = 5005;
const int INF = 1e9;

int dp[MAXN][MAXN];
int arr[MAXN];

int main() {
	FAST_IO;
	
	int n;
	while (cin >> n) {
		forn(i,n) cin >> arr[i+1];
		
		forn(i,n+3) forn(j,n+3) dp[i][j] = -INF;
		dp[1][n] = 0;
		
		int maxi = 0;
		forsn(i,1,n+1) dforsn(j,i+1,n+1) {
			if (arr[i] == arr[j]) {
				dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j]+1);
				maxi = max(maxi, dp[i+1][j-1]);
			}
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			maxi = max(maxi, dp[i+1][j]);
			dp[i][j-1] = max(dp[i][j-1], dp[i][j]);
			maxi = max(maxi, dp[i][j-1]);
		}
		
		printf("%d\n", maxi);
	}
}
