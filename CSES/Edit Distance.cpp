#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

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

const int MAXN = 5005;
const int INF = 1e9+5;

int dp[MAXN][MAXN];

int main() {
    FAST_IO;

    string a,b; cin >> a >> b;

    forn(i,MAXN) forn(j,MAXN) dp[i][j] = INF;
    forn(i,MAXN) dp[i][0] = dp[0][i] = i; dp[0][0] = 0;
    forsn (i,1,a.size()+1) forsn(j,1,b.size()+1)
        dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + (a[i-1] != b[j-1])});

    cout << dp[(int)a.size()][(int)b.size()];

    return 0;
}

/// ESCRIB� en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO B�SICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
