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

const int MAXN = 5005;

int dp[MAXN][MAXN];

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    string a,b; cin >> a >> b;

    int maxi = 0;
    forsn(i,1,n+1) forsn(j,1,m+1) {
        dp[i][j] = max(dp[i][j],dp[i-1][j-1] - 2 + 4*(a[i-1] == b[j-1]));
        if (i >= 2) dp[i][j] = max(dp[i][j],dp[i-2][j-1] - 3 + 4*(a[i-1] == b[j-1]));
        if (j >= 2) dp[i][j] = max(dp[i][j],dp[i-1][j-2] - 3 + 4*(a[i-1] == b[j-1]));
        dp[i][j] = max({dp[i][j],dp[i-1][j]-1,dp[i][j-1]-1});
        maxi = max(maxi,dp[i][j]);
    }

    cout << maxi;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
