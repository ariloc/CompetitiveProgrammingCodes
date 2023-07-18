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

int const MAXN = 1e4+5;
int const MAXK = 105;

int arr[MAXN];
bool dp[MAXN][MAXK];

int main() {
    int t; scanf("%d",&t);
    forn(_,t) {
        int n,k; scanf("%d %d",&n,&k);
        forn(i,n) scanf("%d",&arr[i]);

        forn(i,n) forn(j,k) dp[i][j] = 0;

        dp[0][((arr[0]%k)+k)%k] = 1;
        forsn(i,1,n) forn(j,k)
            dp[i][(((j+arr[i])%k)+k)%k] |= dp[i-1][j], dp[i][(((j-arr[i])%k)+k)%k] |= dp[i-1][j];

        printf("%s\n",dp[n-1][0] ? "Divisible" : "Not divisible");
    }
    
    return 0;
}
