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
const int MAXK = 18;
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
map<ii,int> mapToWeight;
bitset<MAXN> done, done2, edgesUsed;

int P[MAXK][MAXN], dep[MAXN];
ll D[MAXDIF][MAXDIF], sumUpTo[MAXN];
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
        mapToWeight[{min(u,v),max(u,v)}] = w;
    }

    dfs(0,0,0);
    
    // P[0][0] = 0
    forsn(i,1,MAXK) forn(j,n) P[i][j] = P[i-1][P[i-1][j]];

    vi special;
    forn(i,m) if (!edgesUsed[i]) {
        special.pb(myEdges[i].fst), special.pb(myEdges[i].snd);
    }

    // saco repetidos
    sort(all(special));
    special.erase(unique(all(special)),special.end());

    int sz = (int)special.size();

    // recordar que ya están ordenados
    forn(i,sz) {
        forsn(j,i+1,sz) {
            D[i][j] = D[j][i] = distTree(special[i],special[j]);
            auto it = mapToWeight.find({special[i],special[j]});
            if (it != mapToWeight.end())
                D[i][j] = D[j][i] = min(D[i][j], (ll)((*it).snd));
        }
    }

    forn(k,sz) forn(i,sz) forn(j,sz)
        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

    forn(i,sz) forn(j,n) dpTree[i][j] = distTree(special[i],j);

    int q; scanf("%d",&q);
    forn(o,q) {
        int u,v; scanf("%d %d",&u,&v); u--, v--;
        ll r = INF;
        forn(i,sz) forn(j,sz) {
            r = min(r, dpTree[i][u] + D[i][j] + dpTree[j][v]);
        }
        r = min(r, distTree(u,v));

        printf("%lld\n",r);
    }

    return 0;
}