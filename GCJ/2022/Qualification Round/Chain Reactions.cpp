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
const ll INF = 9e18;

int fun[MAXN], deg[MAXN];
ll dp[MAXN][3]; // 0 es hecho, 1 si me llevo min, 2 si me llevo max
bitset<MAXN> done;
vi G[MAXN];

ii dfs (int st, int p = -1) {
    done[st] = true;

    vector<ii> minmaxes;
    ll tot = 0;
    for (auto &i : G[st])
        if (!done[i]) {
            minmaxes.pb(dfs(i,st));
            tot += dp[i][0];
        }
        else minmaxes.pb({-1,-1}); // dummy
    
    ii ret = {fun[st],fun[st]};
    forn(i,G[st].size()) {
        int j = G[st][i];
        if (j != p) {
            // done
            dp[st][0] = max(dp[st][0], tot-dp[j][0]+dp[j][1]+max(minmaxes[i].fst,fun[st]));
            dp[st][0] = max(dp[st][0], tot-dp[j][0]+dp[j][2]+max(minmaxes[i].snd,fun[st]));

            ll aux = tot-dp[j][0]+dp[j][2]+max(minmaxes[i].snd,fun[st]);
            if (aux > dp[st][2] || (aux == dp[st][2] && max(minmaxes[i].snd,fun[st]) > ret.snd)) // max
                dp[st][2] = aux - max(minmaxes[i].snd,fun[st]), ret.snd = max(minmaxes[i].snd,fun[st]);

            aux = tot-dp[j][0]+dp[j][1];
            if (aux > dp[st][1] || (aux == dp[st][1] && max(minmaxes[i].fst,fun[st]) < ret.fst))
                dp[st][1] = aux, ret.fst = max(minmaxes[i].fst,fun[st]);
        }
    }

    return ret;
}

int main() {
    int t; scanf("%d",&t);
    forn(o,t) {
        int n; scanf("%d",&n);

        forn(i,n) scanf("%d",&fun[i+1]);
        forn(i,n+1) 
            G[i].clear(), dp[i][0] = dp[i][1] = dp[i][2] = -INF, done[i] = 0, deg[i] = 0;

        forn(i,n) {
            int x; scanf("%d",&x);
            G[i+1].pb(x), G[x].pb(i+1);
            deg[i+1]++, deg[x]++;
        }

        forsn(i,1,n+1) if (deg[i] <= 1) dp[i][0] = fun[i], dp[i][1] = dp[i][2] = 0;

        dfs(0);
        printf("Case #%d: %lld\n",o+1,dp[0][0]);
    }

    return 0;
}
