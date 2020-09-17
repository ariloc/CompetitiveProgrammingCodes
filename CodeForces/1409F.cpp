
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

const int MAXN = 205;
const int INF = 1e9+5;

int dp[MAXN][MAXN][MAXN]; // (pos, mov, cant prim letra)

int main() {
    FAST_IO;
    forn(i,MAXN) forn(j,MAXN) forn(k,MAXN) dp[i][j][k] = -INF;

    int n,K; cin >> n >> K;
    string s,t; cin >> s >> t;

    dp[0][0][(s[0] == t[0])] = dp[0][1][0] = dp[0][1][1] = 0;
    forn(i,n) forn(j,K+1) forn(k,n+1) {
        dp[i+1][j][k+(s[i+1] == t[0])] = max(dp[i+1][j][k+(s[i+1] == t[0])],dp[i][j][k]+(s[i+1] == t[1])*k);
        dp[i+1][j+1][k+(t[0] == t[1])] = max(dp[i+1][j+1][k+(t[0] == t[1])],dp[i][j][k]+k);
        dp[i+1][j+1][k+1] = max(dp[i+1][j+1][k+1],dp[i][j][k]+(t[0] == t[1]*k));
    }

    int maxi = 0;
    forn(j,K+1) forn(k,n+1) maxi = max(maxi,dp[n-1][j][k]);

    cout << maxi;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
