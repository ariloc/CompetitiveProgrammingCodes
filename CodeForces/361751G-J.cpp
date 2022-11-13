// https://ibero1.contest.codeforces.com/group/BXJ6xt3tnH/contest/361751/problem/G.
// https://ibero1.contest.codeforces.com/group/BXJ6xt3tnH/contest/361751/problem/J.
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

int dp[MAXN][MAXN];
int a[MAXN][MAXN];

int main() {
    int n,m; scanf("%d %d",&n,&m);
    forn(i,n) forn(j,m) scanf("%d",&a[i][j]);

    dp[0][0] = 1;
    forn(i,n) forn(j,m) {
        if (i+a[i][j] < n)
            dp[i+a[i][j]][j] = (dp[i+a[i][j]][j] + dp[i][j])%MOD;
        if (j+a[i][j] < m)
            dp[i][j+a[i][j]] = (dp[i][j+a[i][j]] + dp[i][j])%MOD;
    }

    printf("%d",dp[n-1][m-1]);

    return 0;
}