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

const int MAXN = 5005;

bitset<MAXN> child[MAXN], parent[MAXN], done, done2;
vi G[MAXN],RG[MAXN];

void dfs (int st) {
    done[st] = true;

    child[st][st] = 1;
    for (auto &i : G[st]) {
        if (!done[i]) dfs(i);
        child[st] |= child[i];
    }
}

void dfs2 (int st) {
    done2[st] = true;

    parent[st][st] = 1;
    for (auto &i : RG[st]) {
        if (!done2[i]) dfs2(i);
        parent[st] |= parent[i];
    }
}

int main() {
    FAST_IO;

    int a,b,e,p; cin >> a >> b >> e >> p;
    forn(i,p) {
        int u,v; cin >> u >> v;
        G[u].pb(v), RG[v].pb(u);
    }

    forn(i,e) if (!done[i]) dfs(i);
    forn(i,e) if (!done2[i]) dfs2(i);

    int cntMin = 0, cntMaxi = 0, cntNo = 0;
    forn(i,e) {
        int cntA = child[i].count(), cntB = parent[i].count(); // clave los bitsets para no contar repetidos
        cntA--, cntB--; // me descuento
        if (e-1-cntA < a) cntMin++;
        if (e-1-cntA < b) cntMaxi++;
        if (cntB >= b) cntNo++;
    }

    cout << cntMin << '\n' << cntMaxi << '\n' << cntNo;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
