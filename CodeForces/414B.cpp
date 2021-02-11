#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 2005;
const int MOD = 1e9+7;

int dp[2][MAXN];

int main() {
    FAST_IO;

    int n,K; cin >> n >> K;

    forsn(i,1,n+1) dp[0][i] = 1;
    forsn(i,1,K) {
        forsn(j,1,n+1) dp[i&1][j] = dp[1^(i&1)][j];
        dforsn(j,1,n+1) for(int k = j+j; k <= n; k += j)
            dp[i&1][k] = (dp[i&1][k]+dp[i&1][j])%MOD;
    }

    int rta = 0;
    forsn(i,1,n+1) rta = (rta + dp[(K-1)&1][i])%MOD;

    cout << rta;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
