// https://ibero1.contest.codeforces.com/group/BXJ6xt3tnH/contest/361751/problem/D
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

const int MAXN = 1e6+5;
const int INF = 2e9;

int dp[MAXN];

int main() {
    int n; scanf("%d",&n);
    
    forn(i,n+1) dp[i] = INF;
    dp[1] = 0;

    forsn(i,1,n) {
        if (2*i < MAXN) dp[2*i] = min(dp[2*i],dp[i]+1);
        if (3*i < MAXN) dp[3*i] = min(dp[3*i],dp[i]+1);
        dp[i+1] = min(dp[i+1],dp[i]+1);
    }

    printf("%d",dp[n]);

    return 0;
}