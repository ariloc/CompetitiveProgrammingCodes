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
const int MAXK = 18;

struct edges {
    int v,w;
};

int col[MAXN], prox_libre = 0;
vi comps[MAXN];
bitset<MAXN> done;
vector<edges> G[MAXN];
bitset<MAXN> isInfComp;
bitset<MAXN> done2;
ll sum[MAXN];

void dfs (int st) {
    done[st] = true;
    col[st] = prox_libre;
    comps[prox_libre].pb(st);

    for (auto &i : G[st])
        if (!done[i.v]) dfs(i.v);
}

void dfs2 (int st, int p = -1, ll acc = 0) {
    done2[st] = true;
    sum[st] = acc;

    for (auto &i : G[st]) {
        if (!done2[i.v]) dfs2(i.v, st, acc+i.w);
        else if (i.v != p && sum[i.v] != acc+i.w) {
            isInfComp[col[st]] = true;
        }
    }
}

int main() {
    int n,m,q; scanf("%d %d %d",&n,&m,&q);
    forn(i,m) {
        int u,v,c; scanf("%d %d %d",&u,&v,&c), u--, v--;
        G[u].pb({v,c});
        G[v].pb({u,-c});
    }

    forn(i,n) if (!done[i]) dfs(i), prox_libre++;

    forn(i,prox_libre) {
        int nod = comps[i].back();
        dfs2(nod);
    }

    forn(i,q) {
        int u,v; scanf("%d %d",&u,&v), u--, v--;
        if (col[u] != col[v])
            printf("nan\n");
        else if (isInfComp[col[u]])
            printf("inf\n");
        else {
            printf("%lld\n", sum[v] - sum[u]);
        }
    }

    return 0;
}


