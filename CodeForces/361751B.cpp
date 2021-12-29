// https://ibero1.contest.codeforces.com/group/BXJ6xt3tnH/contest/361751/problem/B
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

const int MAXN = 505;
const ll INF = 9e18;

ll dp[MAXN][MAXN];
int mesa[MAXN][MAXN];

int main() {
    int n,m; scanf("%d %d",&n,&m);
    forn(i,n) forn(j,m) scanf("%d",&mesa[i][j]);

    forn(i,n) forn(j,m) dp[i][j] = -INF;

    dp[0][0] = mesa[0][0];
    forn(i,n) forn(j,m) {
        dp[i+1][j] = max(dp[i+1][j], dp[i][j] + mesa[i+1][j]);
        dp[i][j+1] = max(dp[i][j+1], dp[i][j] + mesa[i][j+1]);
    }

    printf("%lld",dp[n-1][m-1]);

    return 0;
}