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

const int MAXN = 2005;
const int MAXL = 27;

char mat[MAXN][MAXN];
int dp[MAXN][MAXN][4]; // 0 -> der || 1 -> izq || 2 -> up || 3 -> down // directions
int dp2[MAXN][MAXN];
int n,m;

int main() {
    //FAST_IO;

    scanf("%d %d",&n,&m);

    forn(i,n) scanf("%s",mat[i]);
    //forn(i,n) forn(j,m) dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = dp[i][j][3] = 1;

    forn(i,n) dforn(j,m-1) dp[i][j][0] = (mat[i][j+1] == mat[i][j] ? dp[i][j+1][0] : 0)+1;
    forn(i,n) forsn(j,1,m) dp[i][j][1] = (mat[i][j-1] == mat[i][j] ? dp[i][j-1][1] : 0)+1;
    forn(j,m) forsn(i,1,n) dp[i][j][2] = (mat[i-1][j] == mat[i][j] ? dp[i-1][j][2] : 0)+1;
    forn(j,m) dforn(i,n-1) dp[i][j][3] = (mat[i+1][j] == mat[i][j] ? dp[i+1][j][3] : 0)+1;

    forn(i,n) forn(j,m) dp2[i][j] = min({dp[i][j][0],dp[i][j][1],dp[i][j][2],dp[i][j][3]});

    forn(i,n) dforn(j,m-1) dp2[i][j] = min(dp2[i][j], mat[i][j+1] == mat[i][j] ? dp2[i][j+1]+1 : 0);
    forn(i,n) forsn(j,1,m) dp2[i][j] = min(dp2[i][j], mat[i][j-1] == mat[i][j] ? dp2[i][j-1]+1 : 0);
    forn(j,m) forsn(i,1,n) dp2[i][j] = min(dp2[i][j], mat[i-1][j] == mat[i][j] ? dp2[i-1][j]+1 : 0);
    forn(j,m) dforn(i,n-1) dp2[i][j] = min(dp2[i][j], mat[i+1][j] == mat[i][j] ? dp2[i+1][j]+1 : 0);

    ll rta = 0;
    forn(i,n) forn(j,m) rta += dp2[i][j]+1;

    printf("%lld",rta);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!