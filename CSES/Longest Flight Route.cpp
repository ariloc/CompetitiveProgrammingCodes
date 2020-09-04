#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 2e5+5;
const int INF = 1e9+5;

int dp[MAXN],S[MAXN],n,m;
vi G[MAXN];

int dfs(int st) {
    if (dp[st] != -1) return dp[st];
    if (st == n-1) return dp[st] = 1;

    int maxi = -INF, child = -1;
    for(auto &i : G[st]) {
        int v = dfs(i);
        if (v+1 > maxi) {
            maxi = v+1;
            child = i;
        }
    }

    S[st] = child;
    return dp[st] = maxi;
}

int main() {
    FAST_IO;

    memset(dp,-1,sizeof(dp));
    memset(S,-1,sizeof(S));

    cin >> n >> m;
    forn (i,m) {
        int a,b; cin >> a >> b; a--; b--;
        G[a].pb(b);
    }

    dfs(0);
    if (dp[0] < 1) cout << "IMPOSSIBLE";
    else {
        vi path;
        for (int i = 0; i != -1; i = S[i]) path.pb(i+1);
        cout << path.size() << '\n';
        for (auto &i : path) cout << i << ' ';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
