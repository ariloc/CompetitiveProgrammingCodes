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

const int MAXN = 3005;

int arr[MAXN];
ll dp[MAXN][MAXN];

int main() {
    int n; scanf("%d",&n);
    forn(i,n) scanf("%d",&arr[i+1]);

    ll sum = 0;
    forsn(i,1,n+1) sum += arr[i];

    forsn(i,1,n+1) dp[i][i] = arr[i];
    forsn(i,1,n+1) dp[i][i+1] = max(arr[i], arr[i+1]);

    dforsn(i,1,n+1) forsn(j,i+2,n+1)
        dp[i][j] = max(arr[i] + min(dp[i+2][j], dp[i+1][j-1]),
                       arr[j] + min(dp[i+1][j-1], dp[i][j-2]));

    printf("%lld", 2LL*dp[1][n] - sum);

    return 0;
}

