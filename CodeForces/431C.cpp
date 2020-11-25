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
const int MOD = 1e9+7;

int dp[MAXN][2]; // sum, used or not

int main() {
    FAST_IO;

    int n,k,d; cin >> n >> k >> d;

    dp[0][0] = 1;
    forn(i,n) forsn(w,1,k+1) {
        if (w >= d) dp[i+w][1] = (dp[i][0] + dp[i+w][1])%MOD;
        else dp[i+w][0] = (dp[i][0] + dp[i+w][0])%MOD;
        dp[i+w][1] = (dp[i][1] + dp[i+w][1])%MOD;
    }

    cout << dp[n][1];

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
