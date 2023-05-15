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

const int MAXN = 1e5+5;
const int INF = 2e9;

struct edge {
    int u,v,w;

    bool operator< (const edge &o) const {
        return w < o.w;
    }
};

struct gedge {
    int v,w;
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

bitset<MAXN> special, done;
vi special_inp;
int down[MAXN], up[MAXN];
vector<gedge> G[MAXN];
vector<edge> edges;
DS UF;

int dfs (int st) {
    done[st] = true;

    for (auto &i : G[st])
        if (!done[i.v]) return dfs(i.v);

    return st;
}

int dfs2 (int st) {
    done[st] = true;

    int maxi = -INF;
    for (auto &i : G[st]) {
        if (!done[i.v]) {
            int aux = dfs2(i.v);
            if (special[i.v] || aux != -INF)
                aux = max(aux, i.w);
            maxi = max(maxi, aux);
        }
    }

    return down[st] = maxi;
}

void dfs3 (int st) {
    done[st] = true;

    vector<gedge> nodes;
    for (auto &i : G[st]) {
        if (!done[i.v]) nodes.pb(i);
    }
    
    int n = (int)nodes.size();

    vi dpl(n+2, -INF), dpr(n+2, -INF);
    forn(i,n) {
        dpl[i+1] = dpl[i];
        if (down[nodes[i].v] != -INF || special[nodes[i].v])
            dpl[i+1] = max(dpl[i+1], max(down[nodes[i].v], nodes[i].w));
    }
    dforn(i,n) {
        dpr[i+1] = dpr[i+2];
        if (down[nodes[i].v] != -INF || special[nodes[i].v])
            dpr[i+1] = max(dpr[i+1], max(down[nodes[i].v], nodes[i].w));
    }

    forn(i,nodes.size()) {
        gedge x = nodes[i];
        int aux = max(up[st], max(dpl[i], dpr[i+2]));
        if (aux != -INF || special[st])
            aux = max(aux, nodes[i].w);
        up[x.v] = aux;
    }

    forn(i,nodes.size()) dfs3(nodes[i].v);
}

int main() {
    int n,m,k; scanf("%d %d %d",&n,&m,&k);

    UF.init(n+5);

    forn(i,k) {
        int x; scanf("%d",&x); x--;
        special[x] = true;
        special_inp.pb(x);
    }

    forn(i,m) {
        int u,v,w; scanf("%d %d %d",&u,&v,&w);
        u--, v--;
        edges.pb({u,v,w});
    }

    sort(all(edges));

    for (auto &i : edges) {
        if (UF.join(i.u,i.v)) G[i.u].pb({i.v,i.w}), G[i.v].pb({i.u,i.w});
    }

    int leaf = dfs(0);

    forn(i,n) done[i] = 0, down[i] = up[i] = -INF;
    dfs2(leaf);

    forn(i,n) done[i] = 0;
    dfs3(leaf);

    for (auto &i : special_inp)
        printf("%d ",max(up[i],down[i]));
   
    return 0;
}
