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

const int MAXN = 1e5+5;

ld dp[MAXN];
vi G[MAXN];
bitset<MAXN> done;

void dfs (int st, int len, ld prob) {
    done[st] = true;

    int outDeg = 0;
    for (auto &i : G[st]) if (!done[i]) outDeg++;
    for (auto &i : G[st])
        if (!done[i]) dfs(i,len+1,prob*(1/(ld)outDeg));

    if (!outDeg) dp[len] += prob;
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n-1) {
        int u,v; cin >> u >> v; u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    dfs(0,0,1);

    ld rta = 0;
    forn(i,n+1) rta += dp[i]*i;

    cout << fixed << setprecision(15) << rta;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!

