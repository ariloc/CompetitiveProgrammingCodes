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

const int MAXN = 305;
const int MAXV = 2e5;
const int OFFSET = 1e5;
const int MOD = 998244353;

int dp[MAXN][MAXV];
int arr[MAXN];

int sumMod (int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int main() {
    int n; scanf("%d",&n);
    forn(i,n) scanf("%d",&arr[i]);

    dp[1][arr[1]+OFFSET] = 1;

    forsn(i,1,n-1) forn(x,MAXV) {
        int v1 = arr[i+1]+x;
        int v2 = arr[i+1]+2*OFFSET-x;
        if (v1 >= 0 && v1 < MAXV) {
            dp[i+1][v1] = sumMod(dp[i+1][v1], dp[i][x]);
        }
        if (v2 >= 0 && v2 < MAXV && v1 != v2) {
            dp[i+1][v2] = sumMod(dp[i+1][v2], dp[i][x]);
        }
    }

    int acc = 0;
    forn(i,MAXV) acc = sumMod(acc, dp[n-1][i]);

    printf("%d",acc);
   
    return 0;
}
