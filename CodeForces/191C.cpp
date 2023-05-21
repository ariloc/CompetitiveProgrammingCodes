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

struct edge {
    int v,id;
};

vector<edge> G[MAXN];
int D[MAXN], dp[MAXN], P[MAXK][MAXN], rta[MAXN];
bitset<MAXN> done;

void dfs(int st, int lvl = 0) {
    done[st] = true;
    D[st] = lvl;

    for (auto &i : G[st])
        if (!done[i.v]) dfs(i.v, lvl+1), P[0][i.v] = st;
}

int lca (int a, int b) {
    if (D[a] > D[b]) swap(a,b);
    int dif = D[b] - D[a];
    forn(i,MAXK) if (dif&(1<<i)) b = P[i][b];
    if (a == b) return a;
    dforn(i,MAXK) {
        if (P[i][a] != P[i][b]) {
             a = P[i][a], b = P[i][b];
        }
    }
    return P[0][a];
}

int dfs2(int st) {
    done[st] = true;

    int s = 0;
    for (auto &i : G[st])
        if (!done[i.v]) {
            int aux = dfs2(i.v);
            rta[i.id] = aux;
            s += aux;
        }

    return s + dp[st];
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n-1) {
        int u,v; cin >> u >> v; u--, v--;
        G[u].pb({v,i}), G[v].pb({u,i});
    }

    dfs(0);
    forsn(k,1,MAXK) forn(i,n) P[k][i] = P[k-1][P[k-1][i]];

    int k; cin >> k;
    forn(_,k) {
        int a,b; cin >> a >> b; a--, b--;
        int x = lca(a,b);
        dp[x] -= 2;
        dp[a]++, dp[b]++;
    }

    forn(i,n) done[i] = 0;
    dfs2(0);

    forn(i,n-1) cout << rta[i] << ' ';

    return 0;
}
