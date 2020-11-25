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
typedef pair<int,int> ii;

const int MAXN = 302;
const int INF = 1e9;

int dp[MAXN][MAXN][MAXN],grid[MAXN][MAXN];

int main() {
    forn(i,MAXN) forn(j,MAXN) forn(k,MAXN) dp[i][j][k] = -INF;
    int N; scanf("%d",&N);
    forn(i,N) forn(j,N) scanf("%d",&grid[i][j]);

    dp[0][0][0] = 0;
    forn(k,N) forn(j,N) forn(i,N) {
        if (i-1 >= 0 && k-1 >= 0) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k-1]);
        if (j-1 >= 0 && k-1 >= 0) dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k-1]);
        if (j-1 >= 0) dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k]);
        if (i-1 >= 0) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]);
        dp[i][j][k] += grid[i][j] + (i == k ? 0 : grid[k][i+j-k]);
    }

    printf("%d",dp[N-1][N-1][N-1]);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
