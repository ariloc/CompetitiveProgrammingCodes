
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
typedef long double ld;

const int MAXN = 1e5+5;

int inp[MAXN], cant_col[MAXN];

struct DS {
    vi p,r;
    vector<ll> sums;
    map<int,int> cmp[MAXN];

    void init (int N) {
        p.assign(N,0);
        r.assign(N,0);
        sums.assign(N,0);
        forn(i,N) p[i] = i;
    }
    
    int find (int x) {return p[x] == x ? x : p[x] = find(p[x]);}

    void merge (int dest, int orig) {
        for (auto &i : cmp[orig]) {
            int col = i.fst, cant = i.snd;
            int old_col = cmp[dest][col];
            sums[dest] -= old_col * (ll)(cant_col[col] - old_col);
            
            int new_col = old_col + cant;
            cmp[dest][col] = new_col;
            sums[dest] += new_col * (ll)(cant_col[col] - new_col);
        }
    }

    bool join (int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x,y);
        p[x] = y; merge(y, x);
        if (r[x] == r[y]) r[y]++;
        return true;
    }
};

struct edge {
    int v,id;
};

vector<edge> G[MAXN];
DS UF;
bitset<MAXN> done;
ll rta[MAXN];

void dfs (int st, int parent = -1, int edge = -1)  {
    done[st] = true;

    for (auto &i : G[st])
        if (!done[i.v]) dfs(i.v,st,i.id);

    if (parent != -1) {
        rta[edge] = UF.sums[UF.find(st)];
        UF.join(st,parent);
    }
}

int main() {
    int n; scanf("%d", &n);

    UF.init(n+5);

    forn(i,n) {
        int x; scanf("%d",&x);
        cant_col[x]++;
        inp[i] = x;
    }

    forn(i,n) {
        int my_cmp = UF.find(i);
        UF.cmp[my_cmp][inp[i]]++;
        UF.sums[my_cmp] = cant_col[inp[i]]-1;
    }

    forn(i,n-1) {
        int u,v; scanf("%d %d",&u,&v), u--, v--;
        G[u].pb({v,i});
        G[v].pb({u,i});
    }

    forn(i,n) if(!done[i]) dfs(i);

    forn(i,n-1)
        printf("%lld ", rta[i]);

    return 0;
}
