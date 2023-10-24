#include<bits/stdc++.h>
#include <queue>
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 1e5+5;

struct edges {
    int v;
    ll w;

    bool operator< (const edges &o) const {
        return w > o.w;
    }
};

ll D[MAXN];
vi P[MAXN];
vector<edges> G[MAXN];
vi G2[MAXN];
bitset<MAXN> done, passeda;
int n,m,p,g;
vi rta;

void dfs (int st) {
    done[st] = true;
    passeda[st] = true;

    for (auto &i : G2[st])
        if (!done[i])
            dfs(i);
}

void dijkstra (int st) {
    forn(i,n) D[i] = -1;
    priority_queue<edges> Q;
    D[st] = 0;
    Q.push({st,0});

    while (!Q.empty()) {
        auto e = Q.top(); Q.pop();

        if (D[e.v] != e.w) continue;

        for (auto &i : G[e.v]) {
            if (D[i.v] == -1 || D[i.v] > D[e.v] + i.w) {
                D[i.v] = D[e.v] + i.w;
                P[i.v].clear();
                Q.push({i.v,D[i.v]});
            }
            if (D[i.v] == D[e.v] + i.w) {
                P[i.v].pb(e.v);
            }
        }
    }
}

int main() {
    FAST_IO;

    cin >> n >> m;
    cin >> p >> g; --p, --g;

    forn(i,m) {
        int u,v,d; cin >> u >> v >> d; --u, --v;
        G[u].pb({v,d}), G[v].pb({u,d});
    }

    dijkstra(p);

    forn(i,n) for (auto &j : P[i]) G2[j].pb(i);

    done[g] = true;
    dfs(p);
    forn(i,n) if (D[i] == D[g]*2LL && !passeda[i]) rta.pb(i);

    if (rta.empty()) cout << '*';
    else for (auto &i : rta) cout << i+1 << ' ';
    cout << '\n';

    return 0;
}
