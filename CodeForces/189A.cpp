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

const int MAXN = 4005;
const int INF = 1e9+5;

int dp[MAXN];

int main() {
    FAST_IO;

    int n,a,b,c; cin >> n >> a >> b >> c;

    forn(i,MAXN) dp[i] = -INF;
    dp[0] = 0;
    forn(i,n+1) {
        if (i >= a) dp[i] = max(dp[i],dp[i-a]+1);
        if (i >= b) dp[i] = max(dp[i],dp[i-b]+1);
        if (i >= c) dp[i] = max(dp[i],dp[i-c]+1);
    }
    cout << dp[n];

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!