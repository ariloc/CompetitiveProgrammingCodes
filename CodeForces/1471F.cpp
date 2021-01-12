#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 3e5+2;

vi G[MAXN];
bitset<MAXN> done;
int col[MAXN];
int reach = 0;

void dfs2 (int st) {
    done[st] = true; reach++;
    for (auto &i : G[st]) if (!done[i]) dfs2(i);
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n,m; cin >> n >> m;

        reach = 0; // reset
        forn(j,n) {col[j] = -1; G[j].clear(); done[j] = 0;}

        forn(j,m) {
            int u,v; cin >> u >> v; u--, v--;
            G[u].pb(v); G[v].pb(u);
        }

        col[0] = 1;
        queue<int> Q;
        for (auto &j : G[0]) {col[j] = 0; Q.push(j);}

        while (!Q.empty()) {
            auto e = Q.front(); Q.pop();

            for (auto &j : G[e])
                if (col[j] == -1) {
                    col[j] = 1;
                    for (auto &k : G[j]) if (col[k] == -1) {col[k] = 0; Q.push(k);}
                }
        }
        dfs2(0);

        if (reach == n) {
            cout << "YES\n";
            vi lst;
            forn(j,n) if (col[j]) lst.pb(j+1);
            cout << lst.size() << '\n';
            for (auto &j : lst) cout << j << ' ';
            cout << '\n';
        }
        else cout << "NO\n";
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
