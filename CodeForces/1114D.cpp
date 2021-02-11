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

const int MAXN = 5005;
const int INF = 1e9+5;

int col[MAXN];
int dp[MAXN][MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> col[i+1];

    col[0] = col[1], col[n+1] = col[n]; // así no cuento de más
    forn(i,MAXN) forn(j,MAXN) dp[i][j] = INF;
    dp[0][n] = dp[1][n+1] = 0;

    forsn(l,1,n+1) dforsn(r,l,n+1) {
        dp[l][r] = min(dp[l-1][r] + (col[l] != col[l-1]),dp[l][r+1] + (col[r] != col[r+1]));
        if (col[l-1] == col[r+1] && col[l] != col[l-1] && col[r] != col[r+1])
            dp[l][r] = min(dp[l-1][r+1]+1,dp[l][r]);
    }

    int mini = INF;
    forsn(j,1,n+1) mini = min(mini,dp[j][j]);

    cout << mini;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
