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

const int MAXN = 21;
const int MOD = 1e9+7;

int dp[1<<MAXN], mat[MAXN][MAXN];

int sumMod (int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int main() {
    int n; scanf("%d",&n);
    forn(i,n) forn(j,n) scanf("%d", &mat[i][j]);

    dp[0] = 1;
    forsn(mk,1,1<<n) {
        int bits = __builtin_popcount(mk);
        forn(i,n)
            if (mk&(1<<i) && mat[bits-1][i])
                dp[mk] = sumMod(dp[mk], dp[mk^(1<<i)]);
    }

    printf("%d", dp[(1<<n)-1]);
      
    return 0;
}

