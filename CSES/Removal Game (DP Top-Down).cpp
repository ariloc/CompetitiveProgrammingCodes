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
bool done[MAXN][MAXN];

ll solve (int a, int b) {
    if (b < a) return 0;
    if (b == a) return arr[a];
    if (done[a][b]) return dp[a][b];

    done[a][b] = true;
    return dp[a][b] = max(arr[a] + min(solve(a+2,b),solve(a+1,b-1)),
                          arr[b] + min(solve(a+1,b-1),solve(a,b-2)));
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> arr[i];
    //forn(i,n) dp[i+2][i+2] = arr[i];
    //forn(i,n-1) dp[i+2][i+3] = dp[i+3][i+2] = max(arr[i],arr[i+1]);

    /*
    dforsn (i,2,n+2) forsn(j,2,n+2) {
        dp[i][j] = max(arr[i-2] + min(dp[i+2][j],dp[i+1][j-1]),
                       arr[j-2] + min(dp[i+1][j-1],dp[i][j-2]));
    }*/


    cout << solve(0,n-1);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
