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

struct DS {
    vi p,r,acc;

    void init (int N) {
        p.assign(N,0);
        r.assign(N,0);
        acc.assign(N,0);
        forn(i,N) p[i] = i;
    }

    int find (int x) { return p[x] == x ? x : p[x] = find(p[x]); }

    void reset (int x, int accval) {
        p[x] = x;
        r[x] = 0;
        acc[x] = accval;
    }

    void merge (int x, int y) {
        acc[y] += acc[x];
    }

    bool join (int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x,y);
        merge(x,y);
        p[x] = y;
        if (r[x] == r[y]) r[y]++;
        return true;
    }


};

struct edge {
    int u,v;
    int col_u, col_v;

    bool operator< (const edge &o) const {
        if (col_u != o.col_u) return col_u < o.col_u;
        if (col_v != o.col_v) return col_v < o.col_v;
        if (u != o.u) return u < o.u;
        return v < o.v;
    }

    bool operator!= (const edge &o) const {
        return (col_u != o.col_u || col_v != o.col_v);
    }
};

int cod[MAXN];
vi G[MAXN];
bitset<MAXN> done;
int comps = 0, cnt = 0;
int cmp[MAXN], colcmp[MAXN], cmpacc[MAXN];
bitset<MAXN> mark;
vector<edge> edges;
DS UF;

void dfs (int st) {
    done[st] = true;
    cmp[st] = comps;
    cnt++;

    for (auto &i : G[st])
        if (!done[i] && cod[i] == cod[st])
            dfs(i);
}

int main() {
    int n,m; scanf("%d %d",&n,&m);
    forn(i,n) scanf("%d",&cod[i]);

    forn(i,m) {
        int u,v; scanf("%d %d",&u,&v), u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    forn(i,n) if (!done[i]) dfs(i), colcmp[comps] = cod[i], cmpacc[comps] = cnt, comps++, cnt = 0;
    forn(i,n) for (auto &j : G[i]) {
        edge toPush = {cmp[i],cmp[j],cod[i],cod[j]};
        if (toPush.u > toPush.v) swap(toPush.u,toPush.v);
        if (toPush.col_u > toPush.col_v) swap(toPush.col_u,toPush.col_v);
        edges.pb(toPush);
    }

    sort(all(edges));

    int rta = 1;
    vi touched;
    UF.init(comps+2);
    forn(i,comps) UF.acc[i] = cmpacc[i];
    forn(i,edges.size()) {
        if (i && edges[i] != edges[i-1]) { // != defined to cols
            while (!touched.empty()) {
                int e = touched.back(); touched.pop_back();
                UF.reset(e, cmpacc[e]), mark[e] = false;
            }
        }

        edge cur = edges[i];

        if (!mark[cur.u]) mark[cur.u] = true, touched.pb(cur.u);
        if (!mark[cur.v]) mark[cur.v] = true, touched.pb(cur.v);
        UF.join(cur.u,cur.v);
        rta = max(rta, UF.acc[UF.find(cur.u)]);
    }

    printf("%d",rta);

    return 0;
}
