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

const int MAXN = 5e4+10;
const int MAXK = 17;

struct edges {
    int v,w;
};

struct edge {
    int u,v,w;

    bool operator< (const edge &o) const {
        return w < o.w;
    }
};

struct DS {
    vi p,r;

    void init (int N) {
        p.assign(N,0);
        r.assign(N,0);
        forn(i,N) p[i] = i;
    }

    int find (int x) {return p[x] == x ? x : p[x] = find(p[x]);}

    bool join (int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x,y);
        p[x] = y;
        if (r[x] == r[y]) r[y]++;
        return true;
    }
};

vector<edges> G[MAXN];
vector<edge> edgLst;
DS MST;
int dep[MAXN], P[MAXK][MAXN], D[MAXK][MAXN];

void dfs (int st, int lvl = 0) {
    dep[st] = lvl;
    for (auto &i : G[st])
        if (dep[i.v] == -1) {
            dfs(i.v, lvl+1);
            P[0][i.v] = st;
            D[0][i.v] = i.w;
        }
            
}

int kth_ancestor (int x, int k) {
    int lvl = 0;
    while (k) {
        if (k&1) x = P[lvl][x];
        lvl++, k >>= 1;
    }
    return x;
}

int lca (int a, int b) {
    if (dep[a] > dep[b]) swap(a,b);
    int dif = dep[b]-dep[a];

    b = kth_ancestor(b,dif);
    if (a == b) return a;

    dforn(i,MAXK)
        if (P[i][a] != P[i][b])
            a = P[i][a], b = P[i][b];

    return P[0][a];
}

int kth_anc_dist (int x, int k) {
    int r = 0, lvl = 0;
    while (k) {
        if (k&1) r = max(r, D[lvl][x]), x = P[lvl][x];
        lvl++, k >>= 1;
    }
    return r;
}

int main() {
    int t; scanf("%d",&t);
    forn(o,t) {
        int n,m; scanf("%d %d",&n,&m);

        MST.init(n+5);
        forn(i,n) G[i].clear(), dep[i] = -1;
        forn(i,MAXK) P[0][i] = i, D[0][i] = 0;
        edgLst.clear();

        forn(i,m) {
            int u,v,w; scanf("%d %d %d",&u,&v,&w); u--, v--;
            edgLst.pb({u,v,w});
        }

        sort(all(edgLst));
        forn(i,m) {
            auto aux = edgLst[i];
            int u = aux.u, v = aux.v, w = aux.w;
            if (MST.join(u,v))
                G[u].pb({v,w}), G[v].pb({u,w});
        }


        dfs(0);
        forsn(i,1,MAXK) forn(j,MAXN) {
            P[i][j] = P[i-1][P[i-1][j]];
            D[i][j] = max(D[i-1][j], D[i-1][P[i-1][j]]);
        }


        int q; scanf("%d",&q);
        printf("Case %d:\n",o+1);
        forn(i,q) {
            int u,v; scanf("%d %d",&u,&v); u--, v--;
            int aux = lca(u,v);
            int rta = max(kth_anc_dist(u,dep[u]-dep[aux]), kth_anc_dist(v,dep[v]-dep[aux]));
            printf("%d\n",rta);
        }
    }

    return 0;
}