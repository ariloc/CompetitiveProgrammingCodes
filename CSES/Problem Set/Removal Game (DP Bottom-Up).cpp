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
const int INF = 1e9+5;

int arr[MAXN];
ll dp[MAXN][MAXN];

int main() {
    //FAST_IO;

    int n; scanf("%d",&n);
    forn(i,n) scanf("%d",&arr[i+2]);

    forsn(i,2,n+2) dp[i][i] = arr[i]; // the only one, best is me
    forsn(i,2,n+1) dp[i][i+1] = max(arr[i],arr[i+1]); // in pairs, best is max

    dforsn (i,2,n+2) forsn(j,i,n+2) {
        if (i == j or i == j+1) continue;
        dp[i][j] = max(arr[i] + min(dp[i+2][j],dp[i+1][j-1]),
                       arr[j] + min(dp[i+1][j-1],dp[i][j-2]));
    }

    printf("%lld",dp[2][n+1]);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
