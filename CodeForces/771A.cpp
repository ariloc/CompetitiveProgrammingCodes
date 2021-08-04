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

const int MAXN = 150005;

vi G[MAXN];
int deg[MAXN];
int cmp[MAXN], cnt_cmp[MAXN], cmps = 1;

void dfs (int st) {
    cmp[st] = cmps;
    cnt_cmp[cmps]++;

    for (auto &i : G[st])
        if (!cmp[i]) dfs(i);
}

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,m) {
        int u,v; cin >> u >> v; u--, v--;
        G[u].pb(v), G[v].pb(u), deg[u]++, deg[v]++;
    }

    forn(i,n) if (!cmp[i]) dfs(i), cmps++;

    bool ans = true;
    forn(i,n) if (deg[i] != cnt_cmp[cmp[i]]-1) ans = false;

    cout << (ans ? "YES" : "NO");

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!