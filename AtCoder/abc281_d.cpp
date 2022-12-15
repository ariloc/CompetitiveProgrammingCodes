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

const int MAXN = 105;
const ll INF = 9e18;

int arr[MAXN];
ll dp[MAXN][MAXN][MAXN]; // max with remainder, having used k

int main() {
    int N,K,D; scanf("%d %d %d",&N,&K,&D);
    forn(i,N) scanf("%d",&arr[i]);

    forn(i,MAXN) forn(j,MAXN) forn(l,MAXN) dp[i][j][l] = -INF;
    dp[N][0][0] = 0;
    dforn(i,N) forn(j,D) forn(k,K+1) {
        int nr = (j+arr[i])%D;
        if (k-1 >= 0) dp[i][nr][k] = max(dp[i][nr][k], dp[i+1][j][k-1] + arr[i]);
        dp[i][j][k] = max(dp[i][j][k], dp[i+1][j][k]);
    }

    printf("%lld", max(dp[0][0][K], -1LL));
   
    return 0;
}
