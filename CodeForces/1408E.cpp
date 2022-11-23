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

struct edge {
    int u,v,w;

    bool operator< (const edge &o) const {
        return w > o.w;
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

DS UF;
int a[MAXN], b[MAXN];
vector<edge> edges;

int main() {
    int m,n; scanf("%d %d", &m, &n);
    forn(i,m) scanf("%d", &a[i]);
    forn(i,n) scanf("%d", &b[i]);

    UF.init(n+m+5);

    ll rta = 0;
    forn(i,m) {
        int si; scanf("%d", &si);
        forn(j,si) {
            int u; scanf("%d", &u), u--;
            int cost = a[i] + b[u];
            int v = i+n;
            edges.pb({u,v,cost});
            rta += cost;
        }
    }

    sort(all(edges));

    for (auto &i : edges) {
        if (UF.join(i.u,i.v)) rta -= i.w;
    }

    printf("%lld", rta);
            
    return 0;
}

