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
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

int const MAXN = 42;
int const MAXR = 22;
int const MAXK = 22;

int dp[MAXN][MAXK][MAXR][2];

int main() {
    int N,R,K;

    while (scanf("%d %d %d",&N,&R,&K) != -1) {
        forn(i,2*N+2) forn(j,N+2) forn(k,R+2) dp[i][j][k][0] = dp[i][j][k][1] = 0;

        dp[0][0][0][0] = 1;
        forsn(i,1,2*N+1) forn(j,N+1) forn(k,R+1) {
            if (j) {
                dp[i][j][k][1] += dp[i-1][j-1][k][0] + dp[i-1][j-1][k][1];
            }
            if (j+1 != K) dp[i][j][k][0] += dp[i-1][j+1][k][0] + dp[i-1][j+1][k][1];
            else {
                dp[i][j][k][0] += dp[i-1][j+1][k][0];
                dp[i][j][k+1][0] += dp[i-1][j+1][k][1];
            }
        }
        printf("%d\n",dp[2*N][0][R][0] + dp[2*N][0][R][1]);
    }
       
    return 0;
}
