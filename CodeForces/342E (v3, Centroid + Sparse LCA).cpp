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
const int MAXT = 2*MAXN;
const int MAXK = 19;
const int INF = 2e9;

bitset<MAXN> centroid, done;
vi G[MAXN];
int P[MAXN];
ii D[MAXN];
int FA[MAXT], L[MAXT], T[MAXT], actT = 0;
ii SP[MAXK][MAXT];
int cent = 0,N,M;
vi pushed;

void tour (int st, int lvl = 0) {
    done[st] = true;
    FA[st] = actT;
    T[actT] = st;
    L[actT++] = lvl;

    for (auto &i : G[st]) {
        if (!done[i]) {
            tour(i,lvl+1);
            T[actT] = st;
            L[actT++] = lvl;
        }
    }
}

int lca (int u, int v) {
    if (u == v) return u;
    int l = FA[u], r = FA[v];
    if (l > r) swap(l,r);
    int dif = (r-l);
    int bit = (31-__builtin_clz(dif));
    return min(SP[bit][l], SP[bit][r-(1<<bit)+1]).snd;
}

int calc_dist (int u, int v) {
    return L[FA[u]] + L[FA[v]] - 2*L[FA[lca(u,v)]];
}

int find_centroid (int st, int n) {
    done[st] = true;
    pushed.pb(st);

    bool posib = 1;
    int cnt = 0;
    for (auto &i : G[st]) {
        if (!done[i] && !centroid[i]) {
            int aux = find_centroid(i,n);
            if (aux > n/2) posib = false;
            cnt += aux;
        }
    }

    if (n-cnt-1 > n/2) posib = false;
    if (posib) cent = st;
    return cnt+1;
}

int dfs (int st) {
    done[st] = true;
    pushed.pb(st);

    int cnt = 1;
    for (auto &i : G[st])
        if (!done[i] && !centroid[i]) cnt += dfs(i);

    return cnt;
}

void reset() {
    for (auto &i : pushed) done[i] = 0;
    pushed.clear();
}

int solve(int st) {
    int n = dfs(st);
    reset();

    find_centroid(st, n);
    reset();

    centroid[cent] = true;

    int act_cent = cent;
    for (auto &i : G[act_cent])
        if (!centroid[i]) {
            int ot_cent = solve(i);
            P[ot_cent] = act_cent;
        }
    
    return act_cent;
}

void paint(int st, int x) {
    D[st] = min(D[st], {calc_dist(st,x),x});
    if (P[st] != -1) paint(P[st], x);
}

int query (int st, int x) {
    if (P[st] == -1) return D[st].fst != INF ? calc_dist(D[st].snd,x) : INF;
    return min(D[st].snd != INF ? calc_dist(D[st].snd,x) : INF, query(P[st],x));
}

int main() {
    scanf("%d %d",&N,&M);

    forn(i,N) D[i] = {INF,INF}, P[i] = -1;

    forn(i,N-1) {
        int u,v; scanf("%d %d",&u,&v); u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    forn(i,N) done[i] = 0;
    tour(0);
    forn(i,actT) SP[0][i] = {L[i],T[i]};
    forsn(k,1,MAXK) forn(i,actT)
        SP[k][i] = min(SP[k-1][i], SP[k-1][min(i+(1<<(k-1)), MAXT-1)]);

    forn(i,N) done[i] = 0;
    solve(0);
    paint(0,0);

    forn(i,M) {
        int typ,v; scanf("%d %d",&typ,&v); --v;
        if (typ == 1) paint(v,v);
        else printf("%d\n",query(v,v));
    }
        
    return 0;
}
