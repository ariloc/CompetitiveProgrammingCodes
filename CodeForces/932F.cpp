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

const ll INF = 9e18;
const int MAXN = 1e5+5;
const int MAXV = MAXN;

// Li Chao Tree
struct fun {
    ld m,h; // y = mx + h | rta = b[i] * x + acc, x es un a[j] a pedido
    fun(){m = 0, h = INF;}
    fun (ld a, ld b) : m(a), h(b) {}
    ld operator() (ld x) {return m*x + h;}
};

struct li_chao {
    struct mon {
        fun f;
        int l,r;
        mon(){l = -1, r = -1;}
    };

    vector<mon> bag;

    int newNode (int i) {
        if (i == -1) {bag.pb(mon()); return (int)bag.size()-1;}
        return i;
    }

    int insert (int i, fun f, int tl = -MAXV, int tr = MAXV) {
        if (tl+1 >= tr) return i;

        i = newNode(i);

        int mid = (tl+tr)/2;
        bool lc = f(tl) < bag[i].f(tl);
        bool mc = f(mid) < bag[i].f(mid);

        if (mc) swap(f,bag[i].f);

        if (lc != mc) bag[i].l = insert(bag[i].l,f,tl,mid);
        else bag[i].r = insert(bag[i].r,f,mid,tr);

        return i;
    }

    ld query (int i, int x, int tl = -MAXV, int tr = MAXV) {
        if (i == -1) return INF;
        if (tl+1 >= tr) return bag[i].f(x);
        
        int mid = (tl+tr)/2;
        if (x < mid) return min(bag[i].f(x), query(bag[i].l,x,tl,mid));
        return min(bag[i].f(x), query(bag[i].r,x,mid,tr));
    }
};

struct DS {
    vi p,r;
    vector<li_chao> ST;

    void init (int N) {
        p.assign(N,0);
        r.assign(N,0);
        ST.resize(N);
        forn(i,N) p[i] = i;
    }

    int find (int x) {return p[x] == x ? x : p[x] = find(p[x]);}

    ld query (int c, int x) {
        c = find(c);
        return ST[c].query(ST[c].bag.empty() ? -1 : 0, x);
    }

    void insert (int c, fun f) {
        c = find(c);
        ST[c].insert(ST[c].bag.empty() ? -1 : 0, f);
    }

    void merge (int x, int y) {
        for (auto &i : ST[x].bag)
            insert(y,i.f);
    }

    bool join (int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x,y);
        if (r[x] == r[y]) r[y]++;
        p[x] = y, merge(x,y);
        return true;
    }
};

vi G[MAXN];
int a[MAXN], b[MAXN], deg[MAXN];
bitset<MAXN> done;
ll rta[MAXN];
DS UF;

void dfs (int st) {
    done[st] = true;

    for (auto &i : G[st])
        if (!done[i])
            dfs(i), UF.join(st,i);
    
    if (!st || deg[st] > 1)
        rta[st] = UF.query(st,a[st]);
    UF.insert(st,fun(b[st],rta[st]));
}

int main() {
    int n; scanf("%d",&n);

    forn(i,n) scanf("%d",&a[i]);
    forn(i,n) scanf("%d",&b[i]);

    forn(i,n-1) {
        int u,v; scanf("%d %d",&u,&v), u--, v--;
        deg[u]++, deg[v]++;
        G[u].pb(v), G[v].pb(u);
    }

    UF.init(n+5);

    dfs(0);

    forn(i,n) printf("%lld ",rta[i]);

    return 0;
}