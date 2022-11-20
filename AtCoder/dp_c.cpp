#include <algorithm>
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

const int MAXN = 1e5+5;
const int INF = 2e9;

int hap[MAXN][3];
int dp[MAXN][3];

int main() {
    int n; scanf("%d", &n);
    forn(i,n) forn(j,3) scanf("%d", &hap[i][j]);

    forsn(i,1,n) forn(k,3) dp[i][k] = -INF;
    forn(k,3) dp[0][k] = hap[0][k];

    forn(i,n) forn(j,3) forn(k,3) if (j != k)
        dp[i+1][k] = max(dp[i+1][k], dp[i][j] + hap[i+1][k]);

    printf("%d", max({dp[n-1][0], dp[n-1][1], dp[n-1][2]}));
 
    return 0;
}

