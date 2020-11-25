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

const int MAXN = 1002;
const int INF = 1e9+5;
const int MOD = 998244353;

const int posib[][4] = {{0,1,1,1},{0,0,2,0},{0,2,0,0},{1,1,1,0}};

int dp[MAXN][2*MAXN][4]; // n,k,mask

int main() {
    int N,K; scanf("%d %d",&N,&K);

    dp[0][2][1] = dp[0][2][2] = dp[0][1][0] = dp[0][1][3] = 1;
    forsn(i,1,N) forn(j,K+1) forn(k,4) forn(l,4) {
        if (j-posib[k][l] >= 0) dp[i][j][l] = (dp[i][j][l]+dp[i-1][j-posib[k][l]][k])%MOD;
    }
    int rta = 0;
    forn(i,4) rta = (rta+dp[N-1][K][i])%MOD;

    printf("%d",rta);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
