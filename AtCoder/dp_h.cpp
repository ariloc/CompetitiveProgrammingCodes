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

const int MAXN = 1005;
const int MOD = 1e9+7;

int dp[MAXN][MAXN];
string mat[MAXN];

int main() {
    FAST_IO;

    int h,w; cin >> h >> w;
    forn(i,h) cin >> mat[i];

    dp[0][0] = 1;
    forn(i,h) forn(j,w) {
        if (mat[i][j] == '#') continue;
        if (i-1 >= 0) dp[i][j] = (dp[i][j]+dp[i-1][j])%MOD;
        if (j-1 >= 0) dp[i][j] = (dp[i][j]+dp[i][j-1])%MOD;
    }

    printf("%d", dp[h-1][w-1]);
   
    return 0;
}

