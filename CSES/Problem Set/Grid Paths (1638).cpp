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

const int MOD = 1e9+7;
const int MAXN = 1001;

char grid[MAXN][MAXN];
int dp[MAXN][MAXN];

int main() {
    int n; scanf("%d",&n);
    forn(i,n) scanf("%s",grid[i]);

    dp[0][0] = 1;
    forn(i,n) forn(j,n)
        if (grid[i][j] != '*') {
            dp[i+1][j] = (dp[i+1][j]+dp[i][j])%MOD;
            dp[i][j+1] = (dp[i][j+1]+dp[i][j])%MOD;
        }

    printf("%d",grid[n-1][n-1] == '.' ? dp[n-1][n-1] : 0);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
