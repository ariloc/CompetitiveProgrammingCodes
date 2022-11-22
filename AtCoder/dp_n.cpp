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

const int MAXN = 405;
const ll INF = 9e18;

ll dp[MAXN][MAXN], dp2[MAXN];
int arr[MAXN];

int main() {
    int n; scanf("%d", &n);
    forn(i,n) scanf("%d", &arr[i]);

    forsn(i,1,n+1) dp2[i] = dp2[i-1] + arr[i-1];

    forn(i,n+1) forn(j,n+1) dp[i][j] = INF;
    forn(i,n) dp[i][i+1] = 0;
    forsn(w,2,n+1) forn(l,n-w+1)
        forsn(i,1,w)
            dp[l][l+w] = min(dp[l][l+w], dp[l][l+i] + dp[l+i][l+w] + (dp2[l+w] - dp2[l]));

    printf("%lld", dp[0][n]);
   
    return 0;
}

