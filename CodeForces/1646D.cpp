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

struct estado { // cantidad de nodos, suma de pesos
    int cnt;
    ll s;
};

vi G[MAXN];
vi S[MAXN]; // considerando que estoy en 0 lo uso nomás
estado dp[MAXN][2]; 
int deg[MAXN],rta[MAXN];
bitset<MAXN> done;

void dfs (int st) {
    done[st] = true;

    S[st].assign(deg[st],-1);

    forn(i,G[st].size()) {
        int j = G[st][i];
        if (!done[j]) {
            dfs(j);

            bool choose = 0;
            if ( (dp[j][1].cnt > dp[j][0].cnt) ||
                 (dp[j][1].cnt == dp[j][0].cnt && dp[j][1].s < dp[j][0].s))
                    choose = 1;

            dp[st][0].cnt += dp[j][choose].cnt;
            dp[st][0].s += dp[j][choose].s;
            S[st][i] = (int)choose;

            dp[st][1].cnt += dp[j][0].cnt;
            dp[st][1].s += dp[j][0].s;
        }
    }
}

void dfs2 (int st, bool col) {
    rta[st] = col ? deg[st] : 1;

    forn(i,G[st].size()) {
        int j = G[st][i];
        if (rta[j] == -1) 
            dfs2(j, col ? 0 : S[st][i]);
    }
}

int main() {
    int n; scanf("%d",&n);
    forn(i,n-1) {
        int u,v; scanf("%d %d",&u,&v), u--, v--;
        G[u].pb(v), G[v].pb(u);
        deg[u]++, deg[v]++;
    }

    if (n == 2) return printf("2 2\n1 1 "), 0;

    forn(i,n) rta[i] = -1;
    forn(i,n) dp[i][1] = {1,(ll)deg[i]}, dp[i][0].s = 1;

    dfs(0);

    bool col_fst = 0;
    if ( (dp[0][1].cnt > dp[0][0].cnt) || 
         (dp[0][1].cnt == dp[0][0].cnt && dp[0][1].s < dp[0][0].s))
            col_fst = 1;

    printf("%d %lld\n", dp[0][col_fst].cnt, dp[0][col_fst].s);

    dfs2(0,col_fst);
    forn(i,n) printf("%d ",rta[i]);

    return 0;
}