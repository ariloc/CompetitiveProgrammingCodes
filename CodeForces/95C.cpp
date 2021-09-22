#include <bits/stdc++.h>

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

const int MAXN = 1002;

struct nodo {
    int v; ll d;

    bool operator< (const nodo &o) const{
        return o.d < d;
    }
};

const ll INF = 1e13;

vector<nodo> G1[MAXN], G2[MAXN];
ii taxi[MAXN]; // dist,cost
ll dp[MAXN][MAXN], dp2[MAXN];
int x,y;

void dijkstra (int st, ll *D, vector<nodo> (&G)[MAXN]) {
    priority_queue<nodo> Q;
    Q.push({st,0});
    D[st] = 0;

    while (not Q.empty()) {
        int e = Q.top().v; Q.pop();

        for (auto &w : G[e]) {
            if (D[w.v] == -1 or D[w.v] > D[e] + w.d) {
                D[w.v] = D[e] + w.d;
                Q.push({w.v,D[w.v]});
            }
        }
    }
}

int main() {
    FAST_IO;
    memset(dp,-1,sizeof(dp));
    memset(dp2,-1,sizeof(dp2));

    int n,m; cin >> n >> m;

    cin >> x >> y; x--; y--;

    forn (i,m) {
        int a,b,d; cin >> a >> b >> d; a--; b--;
        G1[a].push_back({b,d});
        G1[b].push_back({a,d});
    }

    forn (i,n) cin >> taxi[i].fst >> taxi[i].snd;

    forn (i,n) {
        dijkstra(i,dp[i],G1);

        forn (j,n) {
            if (dp[i][j] > taxi[i].fst) continue;
            if (dp[i][j] == -1) continue;
            if (i == j) continue;
            G2[i].pb({j,taxi[i].snd});
        }
    }

    dijkstra(x,dp2,G2);

    cout << dp2[y];

    return 0;
}