// https://ibero1.contest.codeforces.com/group/BXJ6xt3tnH/contest/361751/problem/H
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
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 1e5+5;
const int MOD = 1e9+7;

int dp[MAXN][4];

int main() {
    int n; scanf("%d",&n);

    dp[0][0] = dp[0][1] = dp[0][2] = 1;
    forsn(i,1,n) {
        dp[i][0] = (((dp[i-1][0] + dp[i-1][1])%MOD) + dp[i-1][3])%MOD;
        dp[i][1] = dp[i][2] = dp[i-1][0];
        dp[i][3] = dp[i-1][2];
    }

    printf("%d",(((dp[n-1][0] + dp[n-1][1])%MOD) + dp[n-1][3])%MOD);

    return 0;
}