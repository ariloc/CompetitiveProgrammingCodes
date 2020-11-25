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

const int MAXN = 305;
const int INF = 1e9+5;

int tablero[MAXN][MAXN];
int dp[MAXN][MAXN][MAXN];
int N;

int solve (int i, int j, int k) {
    if (i >= N or j >= N or k >= N or (i+j-k) >= N) return -INF;
    if (dp[i][j][k] != -INF) return dp[i][j][k];

    return dp[i][j][k] = max({solve(i+1,j,k+1),solve(i+1,j,k),solve(i,j+1,k+1),solve(i,j+1,k)}) +
                         + tablero[i][j] + ((i == k and j == (i+j-k)) ? 0 : tablero[k][i+j-k]);
}

int main() {
    FAST_IO;

    cin >> N;
    forn (i,MAXN) forn(j,MAXN) forn (k,MAXN) dp[i][j][k] = -INF;
    forn(i,N) forn(j,N) cin >> tablero[i][j];
    dp[N-1][N-1][N-1] = tablero[N-1][N-1];

    cout << solve(0,0,0);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
