#include <algorithm>
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
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int MAXN = 205;
const int INF = 2e9;

int arr[MAXN];
int dp[2][MAXN][MAXN]; // i, inc, dec
vi pts;

void update (int &x) {
    x = lower_bound(all(pts),x)-pts.begin()+1;
}

int main() {
    FAST_IO;

    int n;
    while (cin >> n) {
        if (n == -1) break;

        pts.clear();

        forn(i,n) cin >> arr[i], pts.pb(arr[i]);

        sort(all(pts));
        pts.erase(unique(all(pts)),pts.end());
        forn(i,n) update(arr[i]);

        forn(i,2) forn(j,n+2) forn(k,n+2) dp[i][j][k] = -INF;
        dp[0][0][n+1] = 0;

        forn(i,n) {
            forn(j,n+2) forn(k,n+2) {
                dp[1^(i&1)][j][k] = max(dp[1^(i&1)][j][k], dp[i&1][j][k]);
                if (arr[i] > j) 
                    dp[1^(i&1)][arr[i]][k] = max(dp[1^(i&1)][arr[i]][k], dp[i&1][j][k]+1);
                if (arr[i] < k)
                    dp[1^(i&1)][j][arr[i]] = max(dp[1^(i&1)][j][arr[i]], dp[i&1][j][k]+1);
            }
            forn(j,n+2) forn(k,n+2) dp[i&1][j][k] = -INF;
        }

        int maxi = -INF;
        forn(j,n+2) forn(k,n+2) maxi = max(maxi,dp[n&1][j][k]);

        cout << n-maxi << '\n';
    }

    return 0;
}
