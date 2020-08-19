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

const int MAXN = 205;

ll dp[MAXN][MAXN][MAXN];
ll re[MAXN],gr[MAXN],bl[MAXN];

ll solve (int r, int g, int b) {
    if (dp[r][g][b] != -1) return dp[r][g][b];
    if (r < 0 or g < 0 or b < 0) return -1;

    if (r and g) dp[r][g][b] = max(dp[r][g][b],solve(r-1,g-1,b) + re[r-1]*gr[g-1]);
    if (r and b) dp[r][g][b] = max(dp[r][g][b],solve(r-1,g,b-1) + re[r-1]*bl[b-1]);
    if (g and b) dp[r][g][b] = max(dp[r][g][b],solve(r,g-1,b-1) + gr[g-1]*bl[b-1]);

    return (dp[r][g][b] == -1 ? 0 : dp[r][g][b]);
}

int main() {
    FAST_IO;

    memset(dp,-1,sizeof(dp));

    int R,G,B; cin >> R >> G >> B;

    forn(i,R) cin >> re[i];
    forn(i,G) cin >> gr[i];
    forn(i,B) cin >> bl[i];
    sort(re,re+R);
    sort(gr,gr+G);
    sort(bl,bl+B);

    cout << solve(R,G,B);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!