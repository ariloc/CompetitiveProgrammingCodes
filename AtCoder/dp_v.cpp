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

vi G[MAXN];
int MOD;
bitset<MAXN> done;
int down[MAXN], up[MAXN];

int sumMod (int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int prodMod (ll a, int b) {
    a *= b;
    a %= MOD;
    return (int)a;
}

int dfs(int st) {
    done[st] = true;

    for (auto &i : G[st]) {
        if (!done[i]) return dfs(i);
    }

    return st;
}

int dfs2(int st) {
    done[st] = true;

    int posib = 1;
    for (auto &i : G[st]) {
        if (!done[i]) {
            posib = prodMod(posib,sumMod(dfs2(i),1));
        }
    }

    return down[st] = posib;
}

void dfs3 (int st) {
    done[st] = true;

    vi nodes;
    for (auto &i : G[st]) {
        if (!done[i]) nodes.pb(i);
    }

    int n = (int)nodes.size();
    vi dpl(n+2, 1), dpr(n+2, 1);

    forn(i,n) {
        dpl[i+1] = prodMod(dpl[i], sumMod(down[nodes[i]],1));
    }
    dforn(i,n) {
        dpr[i+1] = prodMod(dpr[i+2], sumMod(down[nodes[i]],1));
    }

    forn(i,n) {
        up[nodes[i]] = sumMod(prodMod(prodMod(dpl[i], dpr[i+2]), up[st]), 1);
    }

    forn(i,n) dfs3(nodes[i]);
}

int main() {
    int n,m; scanf("%d %d",&n,&m);
    forn(i,n-1) {
        int u,v; scanf("%d %d",&u,&v); u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    MOD = m;

    int leaf = dfs(0);

    forn(i,n) done[i] = 0, up[i] = 1, down[i] = 1;
    dfs2(leaf);

    forn(i,n) done[i] = 0;
    dfs3(leaf);

    forn(i,n) {
        printf("%d\n", prodMod(up[i], down[i]));
    }
   
    return 0;
}
