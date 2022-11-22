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

const int MAXK = 1e5+5;
const int MAXN = 105;
const int MOD = 1e9+7;

int arr[MAXN], dp[MAXK], dp2[MAXK];

int sumMod (int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int main() {
    int n,k; scanf("%d %d", &n, &k);
    forn(i,n) scanf("%d", &arr[i]);

    dp[0] = 1;
    forn(j,k+1) dp2[j] = 1;
    forn(i,n) {
        forn(j,k+1) dp[j] = sumMod(dp2[j] - (j-arr[i]-1 >= 0 ? dp2[j-arr[i]-1] : 0), MOD);

        dp2[0] = dp[0];
        forsn(j,1,k+1) dp2[j] = sumMod(dp2[j-1], dp[j]);
    }

    printf("%d", dp[k]);
  
    return 0;
}

