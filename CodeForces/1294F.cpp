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
bitset<MAXN> done,mark;
int maxi = -1, nod = -1;

void dfs (int st, int dep) {
    done[st] = true;
    if (dep > maxi) maxi = dep, nod = st;

    for (auto &i : G[st])
        if (!done[i] && !mark[i]) dfs(i,dep+1);
}

bool dfs2 (int st, int nd) {
    done[st] = true;

    bool stat = 0;
    for (auto &i : G[st])
        if (!done[i]) stat |= dfs2(i,nd);

    return mark[st] = stat|(st == nd);
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n-1) {
        int u,v; cin >> u >> v; u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    int prim,sec,terc = -1;
    dfs(0,0); prim = nod; done.reset();
    nod = maxi = -1; dfs(prim,0); sec = nod; done.reset();
    int dist1 = maxi;

    dfs2(prim,sec); done.reset(); // marcar camino

    int dist2 = -1; // así al menos terc engancha 1
    forn(i,n) if (mark[i]) { //cerr << i << ' ' << prim << ' ' << sec << endl;
        nod = maxi = -1, dfs(i,0); // las ramas restantes de c/u, puedo usar dfs siempre porque antes no marqué nada y es todo 0
        if (maxi > dist2 && i != prim && i != sec) dist2 = maxi, terc = nod;
    }

    cout << dist1+dist2 << '\n';
    cout << prim+1 << ' ' << sec+1 << ' ' << terc+1;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
