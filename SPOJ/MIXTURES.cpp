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

int const MAXN = 105;
int const MOD = 100;
ll const INF = 9e18;

int arr[MAXN], col[MAXN];
ll dp[MAXN][MAXN];

ll solve (int l, int r) {
    if (r-l <= 0) return 0;
    if (dp[l][r] != -1) return dp[l][r];

    ll mini = INF;
    forsn(i,l,r) {
        int coll = ((col[i+1]-col[l])%MOD + MOD)%MOD;
        int colr = ((col[r+1]-col[i+1])%MOD + MOD)%MOD;
        ll smoke = solve(l,i) + solve(i+1,r) + coll * (ll)colr;
        mini = min(mini,smoke);
    }

    return dp[l][r] = mini;
}

int main() {
    int n;
    while (scanf("%d",&n) != -1) {
        forn(i,n) scanf("%d",&arr[i]);
        forn(i,n) col[i+1] = (col[i] + arr[i])%MOD;

        forn(i,n+2) forn(j,n+2) dp[i][j] = -1;

        printf("%lld\n",solve(0,n-1));
    }
        
    return 0;
}
