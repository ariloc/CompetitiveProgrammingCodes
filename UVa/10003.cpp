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

int const MAXN = 55;
int const INF = 1e9;

int dp[MAXN][MAXN], cuts[MAXN];

int solve (int l, int r) {
    if (r-l <= 1) return dp[l][r] = 0;
    if (dp[l][r]) return dp[l][r];

    int mini = INF;
    forsn(i,l+1,r)
        mini = min(mini, solve(l,i)+solve(i,r));
    
    return dp[l][r] = mini+cuts[r]-cuts[l];
}

int main() {
    int len;
    while (scanf("%d",&len) != -1) {
        if (!len) break;
        int n; scanf("%d",&n);
        forn(i,n) scanf("%d",&cuts[i+1]);
        
        forn(i,n+2) forn(j,n+2) dp[i][j] = 0;

        cuts[0] = 0, cuts[n+1] = len;

        printf("The minimum cutting is %d.\n",solve(0,n+1));
    }
    
    return 0;
}
