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

const int MAXN = 1e5+5;
const int INF = 1e9+5;
const int MOD = 1e9+7;

struct edges {
    int v; ll w;

    bool operator< (const edges &o) const{
        return w > o.w;
    }
};

struct state {
    int mini,maxi,cnt;
};

state dp[MAXN];
bitset<MAXN> done;
ll D[MAXN];
vector<edges> G[MAXN];

void dijkstra(int st, int nd) {
    priority_queue<edges> Q;
    D[st] = 0; dp[0] = {0,0,1};
    Q.push({st,0});

    ll minP = -1;
    while (not Q.empty()) {
        auto e = Q.top().v; Q.pop();

        if (done[e])  continue;
        done[e] = true;

        if (minP != -1 and minP < D[e]) break;
        if (e == nd) minP = D[nd];

        for (auto &i : G[e]) {
            if (D[i.v] == -1 or D[i.v] > D[e] + i.w) {
                dp[i.v] = {dp[e].mini+1,dp[e].maxi+1,dp[e].cnt};

                D[i.v] = D[e] + i.w;
                Q.push({i.v,D[i.v]});
            }
            else if (D[i.v] == D[e] + i.w) {
                dp[i.v].mini = min(dp[i.v].mini,dp[e].mini+1);
                dp[i.v].maxi = max(dp[i.v].maxi,dp[e].maxi+1);
                dp[i.v].cnt = (dp[i.v].cnt+dp[e].cnt)%MOD;
            }
        }
    }
}

int main() {
    FAST_IO;

    forn(i,MAXN) {dp[i] = {INF,-1,1}; D[i] = -1;} // reset

    int n,m; cin >> n >> m;
    forn (i,m) {
        int a,b,w; cin >> a >> b >> w; a--; b--;
        G[a].pb({b,w});
    }

    dijkstra(0,n-1);

    cout << D[n-1] << ' ' << dp[n-1].cnt << ' ' << dp[n-1].mini << ' ' << dp[n-1].maxi;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
