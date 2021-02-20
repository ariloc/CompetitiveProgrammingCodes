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
bitset<MAXN> done;
int col[MAXN];
bool bipart = true;

void dfs (int st, bool myCol) { // bicoloreo
    done[st] = true;
    col[st] = myCol;

    for (auto &i : G[st])
        if (!done[i]) dfs(i,!myCol);
        else if (col[i] == myCol) bipart = false;
}

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,m) {
        int u,v; cin >> u >> v; u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    forn(i,n) if (!done[i]) dfs(i,0);

    if (!bipart) cout << "-1";
    else {
        vi set1, set2;
        forn(i,n) if (col[i]) set1.pb(i); else set2.pb(i);
        cout << set1.size() << '\n';
        for (auto &i : set1) cout << i+1 << ' ';
        cout << '\n' << set2.size() << '\n';
        for (auto &i : set2) cout << i+1 << ' ';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
