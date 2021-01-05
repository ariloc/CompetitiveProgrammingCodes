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

const int MAXN = 105;
const int INF = 1e9+5;

int r[MAXN],b[MAXN],dp[MAXN][MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {

        int n; cin >> n;
        forn(j,n) cin >> r[j];
        int m; cin >> m;
        forn(j,m) cin >> b[j];

        forn(j,n+3) forn(k,m+3) dp[j][k] = -INF;
        dp[0][0] = 0;
        int maxi = 0;
        forn(j,n+1) forn(k,m+1) {
            if (j) dp[j][k] = max(dp[j][k],dp[j-1][k]+r[j-1]);
            if (k) dp[j][k] = max(dp[j][k],dp[j][k-1]+b[k-1]);
            maxi = max(maxi,dp[j][k]);
        }
        cout << maxi << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
