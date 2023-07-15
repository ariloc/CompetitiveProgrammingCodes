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

int const MAXK = 14;
int const MAXN = 1<<MAXK;

int P[MAXK][MAXN], D[MAXN];
vi G[MAXN];

int lca (int u, int v) {
    if (D[u] > D[v]) swap(u,v);
    int dif = D[v]-D[u];
    forn(i,MAXK)
        if (dif&(1<<i)) v = P[i][v];
    if (u == v) return u;
    dforn(i,MAXK)
        if (P[i][u] != P[i][v]) 
            u = P[i][u], v = P[i][v];
    return P[0][u];
}

void dfs (int st, int lvl = 0) {
    D[st] = lvl;
    for (auto &i : G[st])
        dfs(i,lvl+1);
}

int main() {
    int n; scanf("%d",&n);
    forn(i,n) {
        int m; scanf("%d",&m);
        forn(_,m) {
            int x; scanf("%d",&x);
            P[0][x] = i;
            G[i].pb(x);
        }
    }

    forsn(k,1,MAXK) forn(i,n) P[k][i] = P[k-1][P[k-1][i]];

    dfs(0);

    int q; scanf("%d",&q);
    forn(_,q) {
        int u,v; scanf("%d %d",&u,&v);
        printf("%d\n",lca(u,v));
    }

    return 0;
}
