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

const int MAXN = 2e5+5;

vi G[MAXN];
int col[MAXN];
bitset<MAXN> done;

void dfs(int st, bool me) {
    done[st] = true;
    col[st] = me;

    for (auto &i : G[st]) if (!done[i]) dfs(i,!me);
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n,m; cin >> n >> m;
        forn(i,n) G[i].clear(), done[i] = (col[i] = 0);
        forn(i,m) {
            int u,v; cin >> u >> v; u--, v--;
            G[u].pb(v), G[v].pb(u);
        }
        dfs(0,0);
        vi b,w;
        forn(i,n) if (col[i]) b.pb(i); else w.pb(i);
        if (b.size() > w.size()) swap(b,w);
        cout << b.size() << '\n';
        for (auto &i : b) cout << i+1 << ' ';
        cout << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!

