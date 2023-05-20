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

struct ds_event {
    int x, p; // x was previously children of p.
    int yv, ye; // y (current p[x]) previously had yv vertices and ye edges
    int ry; // previous rank of y
    int rta; // previous rta
};

struct DS {
    vi p,r;
    vi v,e;
    vector<ds_event> hist;
    int rta = 0;

    void init (int N) {
        p.assign(N,0);
        r.assign(N,0);
        v.assign(N,1);
        e.assign(N,0);
        forn(i,N) p[i] = i;
    }

    void rollback(int ver) { // rollback up to before version
        while ((int)hist.size() > ver) {
            auto i = hist.back(); hist.pop_back();
            int y = p[i.x];
            p[i.x] = i.p;
            v[y] = i.yv;
            e[y] = i.ye;
            r[y] = i.ry;
            rta = i.rta;
        }
    }

    int find(int x) { return p[x] == x ? x : find(p[x]); }

    int join (int a, int b) { // returns new version
        int x = find(a), y = find(b);
        if (x == y) {
            hist.pb({x,p[x],v[y],e[y],r[y],rta});
            rta -= calc(y);
            e[y]++;
            rta += calc(y);
            return (int)hist.size()-1;
        }
        if (r[x] > r[y]) swap(x,y);
        hist.pb({x,p[x],v[y],e[y],r[y],rta});
        rta -= calc(x) + calc(y);
        p[x] = y;
        v[y] += v[x];
        e[y] += e[x] + 1; // join is new edge
        if (r[x] == r[y]) r[y]++;
        rta += calc(y);
        return (int)hist.size()-1;
    }

    int calc (int x) {
        x = find(x);
        return min(v[x],e[x]);
    }
};

DS UF;
ii a[MAXN];
vi G[MAXN];
int rta[MAXN];
bitset<MAXN> done;

void dfs (int st) {
    done[st] = true;

    int ver = UF.join(a[st].fst, a[st].snd);
    rta[st] = UF.rta;

    for (auto &i : G[st]) {
        if (!done[i]) {
            dfs(i);
        }
    }

    UF.rollback(ver);
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> a[i].fst >> a[i].snd, --a[i].fst, --a[i].snd;
    forn(i,n-1) {
        int u,v; cin >> u >> v; u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    UF.init(n+5);

    dfs(0);

    forsn(i,1,n) cout << rta[i] << ' ';

    return 0;
}
