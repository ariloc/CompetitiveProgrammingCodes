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

int const MAXN = 1e6+5;
int const INF = 2e9;

vi G[MAXN];
bitset<MAXN> done;
ll rta = 0;

void dfs (int st, set<int> &cur) {
    done[st] = true;

    int sum = 0;
    vi ramas;
    for (auto &i : G[st]) 
        if (!done[i]) {
            set<int> auxi;
            dfs(i,auxi);

            ramas.pb((int)auxi.size());
            sum += ramas.back();

            if ((int)auxi.size() > (int)cur.size()) swap(auxi,cur);
            for (auto &j : auxi) cur.insert(j);
        }

    if (!ramas.empty()) {
        int n = (int)ramas.size();
        vector<vi> dp(n, vi(sum+1,0));
        forn(i,n) forn(j,sum+1) dp[i][j] = -INF;
        dp[0][ramas[0]] = 0, dp[0][0] = ramas[0];
        forn(i,n-1) {
            forn(j,sum+1) {
                int nxtsum = j + ramas[i+1];
                if (nxtsum <= sum && abs(nxtsum-dp[i+1][nxtsum]) > abs(nxtsum-dp[i][j])) {
                    dp[i+1][nxtsum] = dp[i][j];
                }
                
                if (abs(j-dp[i+1][j]) > abs(j-(dp[i][j]+ramas[i+1]))) {
                    dp[i+1][j] = dp[i][j] + ramas[i+1];
                }
            }
        }

        ll maxi = 0;
        forn(i,sum+1) maxi = max(maxi,dp[n-1][i] * (ll)i);

        rta += maxi;
    }

    cur.insert(st);
}

int main() {
    int n; scanf("%d",&n);

    forn(i,n-1) {
        int x; scanf("%d",&x); x--;
        G[i+1].pb(x), G[x].pb(i+1);
    }

    set<int> aux;
    dfs(0,aux);

    printf("%lld\n",rta);

    return 0;
}
