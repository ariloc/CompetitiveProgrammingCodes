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

int const MAXN = 2e5+5;
int const INF = 2e9;
ll const INFL = 9e18;

struct DS {
    vi p,r;
    vector<ll> sum;
    vi maxi;
    vector<vi> inds;

    void init(int N) {
        p.assign(N,0);
        r.assign(N,0);
        sum.assign(N,0);
        maxi.assign(N,0);
        inds.assign(N,{});
        forn(i,N) p[i] = i;
    }

    int find (int x) { return p[x] == x ? x : p[x] = find(p[x]); }

    void merge(int x, int y) {
        sum[y] += sum[x];
        if (maxi[x] > maxi[y]) inds[y].clear(), maxi[y] = maxi[x];
        if (maxi[x] == maxi[y])
            for (auto &j : inds[x]) inds[y].pb(j);
    }

    bool join (int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x,y);

        p[x] = y;
        merge(x,y);
        
        if (r[x] == r[y]) r[y]++;
        return true;
    }
};

int vals[MAXN];
vi G[MAXN];
vi toUpd[MAXN];
ll rta[MAXN];
vector<ii> pairs;
DS UF;

int main() {
    int n; scanf("%d",&n);

    UF.init(n+5);

    forn(i,n-1) {
        int u,v; scanf("%d %d",&u,&v), u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    forn(i,n) scanf("%d",&vals[i]);
    
    forn(i,n) UF.sum[i] = vals[i], UF.maxi[i] = vals[i], UF.inds[i].pb(i);

    forn(i,n) pairs.pb({vals[i],i});
    sort(all(pairs));

    pairs.pb({INF,-1}); // dummy

    vi cur;
    int prv = -1;
    forn(i,n+1) {
        if (pairs[i].fst != prv) {
            for (auto &j : cur) {
                for (auto &k : G[j])
                    if (vals[k] <= vals[j]) {
                        int ind = UF.find(k);
                        if (UF.maxi[ind] < vals[j]) {
                            for (auto &o : UF.inds[ind]) {
                                toUpd[j].pb(o);
                            }
                        }
                        UF.join(j,k);
                    }
            }

            for (auto &j : cur) {
                bool posib = false;
                for (auto &k : G[j])
                    if (vals[k] < vals[j]) posib = true;

                if (posib) rta[j] = UF.sum[UF.find(j)];
                else rta[j] = vals[j];
            }

            cur.clear();
        }
        cur.pb(pairs[i].snd);
        prv = pairs[i].fst;
    }

    dforn(k,n) {
        int i = pairs[k].snd;
        for (auto &j : toUpd[i]) {
            // cerr << i << ' ' << j << "!!!!" << endl;
            if (rta[j] > vals[i]) rta[j] = max(rta[j], rta[i]);
        }
    }

    forn(i,n) printf("%lld ",rta[i]);
             
    return 0;
}
