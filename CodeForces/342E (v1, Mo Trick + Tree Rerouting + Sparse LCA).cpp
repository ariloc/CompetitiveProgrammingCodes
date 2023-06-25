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
const int INF = 1e9;
const int MAXK = 18;
const int MAXT = 1<<MAXK;
const int BLOCK = 320;

int n,m;
bitset<MAXN> painted,done;
vi G[MAXN];
int D[MAXN];
int FA[MAXT], L[MAXT], T[MAXT];
int actT = 0;
ii SP[MAXK][MAXT];
vi recent;

void tour (int st, int lvl = 0) {
    done[st] = true;
    T[actT] = st;
    L[actT] = lvl;
    FA[st] = actT++;

    for (auto &i : G[st]) {
        if (!done[i]) {
            tour(i,lvl+1);
            L[actT] = lvl;
            T[actT++] = st;
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

int dfs (int st) {
    done[st] = true;

    int mini = INF;
    for (auto &i : G[st]) {
        if (!done[i]) {
            mini = min(mini,dfs(i));
        }
    }

    if (painted[st]) mini = -1;
    return D[st] = mini+1;
}

void dfs2 (int st, int bst = INF) {
    done[st] = true;
    
    if (painted[st]) bst = 0;
    D[st] = min(D[st],bst);

    pair<ii,ii> mins = {{bst, -1},{INF,INF}};
    for (auto &i : G[st]) {
        if (!done[i]) {
            if (D[i]+1 < mins.fst.fst || D[i]+1 == mins.fst.fst) {
                swap(mins.fst,mins.snd);
                mins.fst = {D[i]+1,i};
            }
            else if (D[i]+1 < mins.snd.fst) {
                mins.snd = {D[i]+1,i};
            }
        }
    }

    for (auto &i : G[st]) {
        if (!done[i]) {
            int dist = (i != mins.fst.snd) ? mins.fst.fst : mins.snd.fst;
            dfs2(i,dist+1);
        }
    }
}

void solve() {
    forn(i,n) done[i] = 0, D[i] = INF;

    dfs(0);

    forn(i,n) done[i] = 0;

    dfs2(0);
}

int query (int x){
    if ((int)recent.size() >= BLOCK) {
        for (auto &i : recent) painted[i] = true;
        recent.clear();
        solve();
    }

    int rta = D[x];

    for (auto &i : recent) {
        rta = min(rta, L[FA[i]] + L[FA[x]] - 2*L[FA[lca(i,x)]]);
    }

    return rta;
}

int main() {
    scanf("%d %d",&n,&m);

    painted[0] = true;

    forn(i,n-1) {
        int u,v; scanf("%d %d",&u,&v); u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    tour(0);
    forn(i,actT) SP[0][i] = {L[i],T[i]};
    forsn(k,1,MAXK) forn(i,actT)
        SP[k][i] = min(SP[k-1][i], SP[k-1][min(i+(1<<(k-1)),MAXT-1)]);

    solve();

    forn(i,m) {
        int typ,v; scanf("%d %d",&typ,&v), v--;
        if (typ == 1) recent.pb(v);
        else printf("%d\n",query(v));
    } 

    return 0;
}
