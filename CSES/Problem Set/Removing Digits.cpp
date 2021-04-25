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

const int MAXN = 1e6+5;
const int INF = 1e9+5;

int dp[MAXN];

int solve(int n) {
    if (n < 0) return INF;
    if (!n) return 0;
    if (dp[n] != -1) return dp[n];

    int mini = INF, cp = n;
    while (cp) {
        if (cp%10) mini = min(mini,solve(n-(cp%10)));
        cp /= 10;
    }

    return dp[n] = mini+1;
}

int main() {
    FAST_IO;

    memset(dp,-1,sizeof(dp));

    int n; cin >> n;
    cout << solve(n);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
