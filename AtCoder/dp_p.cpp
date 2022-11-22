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
const int MOD = 1e9+7;

vi G[MAXN];
int dp[MAXN][2];
bitset<MAXN> done;

int sumMod (int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

void solve (int st) {
    done[st] = true;
    dp[st][0] = dp[st][1] = 1;

    int child = 0;
    for (auto &i : G[st])
        if (!done[i]) {
            solve(i);
            dp[st][0] = (dp[st][0] * (ll)sumMod(dp[i][0], dp[i][1]))%MOD;
            dp[st][1] = (dp[st][1] * (ll)dp[i][0])%MOD;
            child++;
        }
}

int main() {
    int n; scanf("%d", &n);
    forn(i,n-1) {
        int u,v; scanf("%d %d", &u, &v), u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    solve(0);

    printf("%d", sumMod(dp[0][0], dp[0][1]));
       
    return 0;
}

