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

const int MAXN = 505;
const int MOD = 998244353;

ll dp[MAXN][MAXN];
ll S[MAXN];

int main() {
    FAST_IO;

    int n,K; cin >> n >> K;

    forn (i,MAXN) dp[0][i] = 1;
    forsn(j,1,n+1) forsn(i,1,n+1) forsn(k,1,min(i+1,j+1))
        dp[i][j] = (dp[i][j]+dp[i-k][j])%MOD;

    forsn(i,1,n+1)
        S[i] = ((dp[n][i] - dp[n][i-1]) + MOD) % MOD;

    ll rta = 0;
    forsn(i,1,n+1) forsn(j,1,n+1) {
        if (i*j >= K) continue;
        rta = (rta + S[i]*S[j])%MOD;
    }

    cout << (rta*2)%MOD;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!