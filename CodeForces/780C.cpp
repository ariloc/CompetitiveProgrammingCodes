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

int rta[MAXN],prox_libre = 1;
vi G[MAXN];
bitset<MAXN> done;

void dfs (int st, int pCol) {
    done[st] = true;

    int actCol = 1;
    for (auto &i : G[st])
        if (!done[i]) {
            while (actCol == rta[st] || actCol == pCol) actCol++;
            if (actCol > prox_libre) prox_libre = actCol;
            rta[i] = actCol++;
            dfs(i,rta[st]);
        }
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n-1) {
        int u,v; cin >> u >> v; u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    rta[0] = 1;
    dfs(0,-1);

    cout << prox_libre << '\n';
    forn(i,n) cout << rta[i] << ' ';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!

