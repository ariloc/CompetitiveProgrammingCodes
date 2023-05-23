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

const int MAXN = 2e5+5;
const int MAXK = 20;
const int INF = 2e9;

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

struct edge {
    int u,v,w,id;

    bool operator< (const edge &o) const {
        return w < o.w;
    }
};

struct gedge {
    int v,w;
};

struct mon {
    int v;

    mon(){v = -INF;}
    mon(int v) : v(v) {}

    mon operator+ (const mon &o) const {
        return {max(v,o.v)};
    }
};

struct query {
    int f,id;
};

DS UF;
vector<edge> edges;
vector<gedge> G[MAXN];
bitset<MAXN> done;
int P[MAXK][MAXN], D[MAXN], maxi[MAXK][MAXN];
ll rta[MAXN];

void dfs (int st, int lvl = 0) {
    done[st] = true;
    D[st] = lvl;

    for (auto &i : G[st])
        if (!done[i.v]) {
            dfs(i.v,lvl+1);
            P[0][i.v] = st;
            maxi[0][i.v] = i.w;
        }
}

int lca (int a, int b) {
    if (D[a] > D[b]) swap(a,b);
    int dif = D[b] - D[a];
    forn(i,MAXK) if (dif&(1<<i)) b = P[i][b];
    if (a == b) return a;
    dforn(i,MAXK)
        if (P[i][a] != P[i][b])
            a = P[i][a], b = P[i][b];
    return P[0][a];
}

int querymax (int x, int d) {
    int ret = -INF;
    forn(i,MAXK) {
        if (d&(1<<i)) {
            ret = max(ret, maxi[i][x]);
            x = P[i][x];
        }
    }
    return ret;
}

int main() {
    int n,m; scanf("%d %d",&n,&m);
    forn(i,m) {
        int u,v,w; scanf("%d %d %d",&u,&v,&w); u--, v--;
        edges.pb({u,v,w,i});
    }

    sort(all(edges));

    UF.init(n+5);

    ll acc = 0;
    for (auto &i : edges) {
        if (UF.join(i.u,i.v)) G[i.u].pb({i.v,i.w}), G[i.v].pb({i.u,i.w}), acc += i.w;
    }

    dfs(0);

    forsn(k,1,MAXK) forn(i,n) P[k][i] = P[k-1][P[k-1][i]];
    forsn(k,1,MAXK) forn(i,n) maxi[k][i] = max(maxi[k-1][i], maxi[k-1][P[k-1][i]]);

    forn(i,m) {
        edge me = edges[i];
        int x = lca(me.u,me.v);
        rta[me.id] = acc - max(querymax(me.u,D[me.u]-D[x]), querymax(me.v,D[me.v]-D[x])) + me.w;
    }

    forn(i,m) printf("%lld\n",rta[i]);
    
    return 0;
}
