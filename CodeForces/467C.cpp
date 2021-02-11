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

const int MAXN = 5005;
const ll INF = 9e18;

ll dp[MAXN][MAXN];
ll TAd[MAXN];

int main() {
    FAST_IO;

    int n,m,k; cin >> n >> m >> k;
    forn(i,n) cin >> TAd[i+1];

    forsn(i,1,n+1) TAd[i] += TAd[i-1];

    forsn(i,1,MAXN) forsn(j,1,MAXN) dp[i][j] = -INF;
    forsn(r,m,n+1) forsn(i,1,k+1)
        dp[r][i] = max(dp[r-1][i],dp[r-m][i-1]+TAd[r]-TAd[r-m]);

    cout << dp[n][k];

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
