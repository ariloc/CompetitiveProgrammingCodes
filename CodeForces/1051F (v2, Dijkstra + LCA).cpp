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
const int MAXDIF = 50;
const int MAXK = 20;
const ll INF = 9e18;

struct edges {
    int v; ll w;
    int id;

    bool operator< (const edges &o) const {
        return w > o.w;
    }
};

vector<edges> G[MAXN];
ii myEdges[MAXN];
bitset<MAXN> done, done2, edgesUsed;

int P[MAXK][MAXN], dep[MAXN];
ll dists[MAXDIF][MAXDIF];
ll D[MAXN], sumUpTo[MAXN];
ll dpTree[MAXDIF][MAXN];

void dfs (int st, ll acc, int lvl) { // tree with root in 0
    done[st] = true;
    dep[st] = lvl;
    sumUpTo[st] = acc;

    for (auto &i : G[st])
        if (!done[i.v]) {
            P[0][i.v] = st;
            edgesUsed[i.id] = true;
            dfs(i.v, acc+i.w, lvl+1);
        }
}

void dijkstra (int st) {
    forn(i,MAXN) D[i] = -1; // init
    done2.reset();
    priority_queue<edges> Q;
    Q.push({st,0,-1}); D[st] = 0;

    while (!Q.empty()) {
        auto e = Q.top().v; Q.pop();

        if (done2[e]) continue;
        done2[e] = true;

        for (auto &i : G[e]) {
            if (D[i.v] == -1 || D[i.v] > D[e] + i.w) {
                D[i.v] = D[e] + i.w;
                Q.push({i.v, D[i.v], -1}); // id placeholder
            }
        }
    }
}

int lca (int u, int v) {
    if (dep[u] > dep[v]) swap(u,v);
    int dif = dep[v]-dep[u];
    forn(i,MAXK) if (dif&(1<<i)) v = P[i][v];

    if (u == v) return v;

    dforn(i,MAXK) 
        if (P[i][u] != P[i][v]) 
            u = P[i][u], v = P[i][v];

    return P[0][u];
}

ll distTree (int u, int v) {
    int myLca = lca(u,v);

    return sumUpTo[u] + sumUpTo[v] - 2LL*sumUpTo[myLca];
}

int main() {
    int n,m; scanf("%d %d",&n,&m);
    forn(i,m) {
        int u,v,w; scanf("%d %d %d",&u,&v,&w); u--, v--;
        G[u].pb({v,w,i}), G[v].pb({u,w,i});
        myEdges[i] = {u,v};
    }

    dfs(0,0,0);
    
    // P[0][0] = 0
    forsn(i,1,MAXK) forn(j,n) P[i][j] = P[i-1][P[i-1][j]];

    vi special;
    forn(i,m) if (!edgesUsed[i])
        special.pb(myEdges[i].fst), special.pb(myEdges[i].snd);

    // saco repetidos
    sort(all(special));
    special.erase(unique(all(special)),special.end());

    forn(i,special.size()) {
        dijkstra(special[i]);
        forn(j,special.size()) dists[i][j] = D[special[j]];
    }

    forn(i,special.size()) forn(j,n) dpTree[i][j] = distTree(special[i],j);

    int q; scanf("%d",&q);
    forn(o,q) {
        int u,v; scanf("%d %d",&u,&v); u--, v--;
        ll r = INF;
        forn(i,special.size()) forn(j,special.size()) {
            r = min(r, dpTree[i][u] + dists[i][j] + dpTree[j][v]);
        }
        r = min(r, distTree(u,v));

        printf("%lld\n",r);
    }

    return 0;
}