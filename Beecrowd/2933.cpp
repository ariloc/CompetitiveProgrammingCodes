#include <bits/stdc++.h>
 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) err << #x << " = " << x << endl;
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
const int MAXST = (1<<(32-__builtin_clz(MAXN)));
const int MAXK = 18;
const int INF = 2e9;

struct edge {
    int v,w;
};

struct fedge {
    int u,v,w;

    bool operator< (const fedge &o) const {
        return w < o.w;        
    }
};

struct mon {
    int v;
    mon(){v = -INF;}
    mon(int x) : v(x) {}

    mon operator+ (const mon &o) const {
        return mon(max(v,o.v));
    }
};

struct DS {
    vi p,r;

    void init(int N) {
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

vector<fedge> edges;
vector<edge> G[MAXN];
DS UF;
int P[MAXK][MAXN], dep[MAXN], N;
mon ST[2*MAXST];

void update (int p, int v) {
    p += N; ST[p] = v;
    
    while (p > 1)
        p /= 2, ST[p] = ST[2*p] + ST[2*p+1];
}

mon query (int l, int r) {
    mon ret; 
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l&1) ret = (ret + ST[l++]);
        if (r&1) ret = (ret + ST[--r]);
    }
    return ret;
}

void dfs (int st, int lvl = 0) {
    dep[st] = lvl;

    for (auto &i : G[st])
        if (dep[i.v] == -1) {
            P[0][i.v] = st; 
            dfs(i.v, lvl+1);
        }
}

int lca (int a, int b) {
    if (dep[a] > dep[b]) return lca(b,a);
    
    int dif = dep[b] - dep[a];
    dforn(i,MAXK)
        if (dif&(1<<i))
            b = P[i][b];
    
    if (a == b) return a;
    
    dforn(i,MAXK)
        if (P[i][a] != P[i][b])
            a = P[i][a], b = P[i][b];
    
    return P[0][a];
}

vector<ii> queries[MAXN];
int rta[MAXN], posic[MAXN];

void dfs2 (int st, int lvl = 0) {
    posic[st] = lvl;

    for (auto &i : queries[st])
        rta[i.snd] = max(rta[i.snd], query(posic[i.fst], lvl).v);

    for (auto &i : G[st])
        if (posic[i.v] == -1) {
            update(lvl, i.w);
            dfs2(i.v, lvl+1); 
        }
}

int main() {
    int n,m; scanf("%d %d",&n,&m); 
    
    UF.init(n+2);
    forn(i,n) dep[i] = posic[i] = -1;
    N = (1<<(32-__builtin_clz(n)));
    
    forn(i,m) {
        int u,v,w; scanf("%d %d %d",&u,&v,&w);
        edges.pb({u,v,w});
    }

    sort(all(edges));
    
    forn(i,m) {
        auto aux = edges[i];
        if (UF.join(aux.u, aux.v)) {
            G[aux.u].pb({aux.v, aux.w}), G[aux.v].pb({aux.u, aux.w});
        }
    }

    P[0][0] = 0; 
    dfs(0);

    forsn(i,1,MAXK) forn(j,n) P[i][j] = P[i-1][P[i-1][j]];

    int q; scanf("%d",&q);
    forn(i,q) {
        int x,y; scanf("%d %d",&x,&y);
        int r = lca(x,y);
        queries[x].pb({r,i}), queries[y].pb({r,i});
        rta[i] = -INF;
    }

    dfs2(0);

    forn(i,q)
        printf("%d\n", max(0,rta[i]));
    
    return 0;
}
