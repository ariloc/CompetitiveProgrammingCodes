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

vector<ii> G[MAXN];
bitset<MAXN> done;
int rta = 0; bool cycle = 0;

void dfs (int st, int p_edge) { // por c/comp conexa, solo uno quedará separado
    done[st] = true;

    for (auto &i : G[st])
        if (!done[i.fst]) dfs(i.fst,i.snd);
        else if (i.snd != p_edge) cycle = 1; // si vuelvo a un visitado por una arista distinta por la que pasé ya
}

int main() {
    int n,m; scanf("%d %d",&n,&m);
    forn(i,m) {
        int u,v; scanf("%d %d",&u,&v); u--, v--;
        G[u].pb({v,i}); G[v].pb({u,i});
    }

    forn(i,n) if (!done[i]) {dfs(i,-1); if (!cycle) rta++; cycle = 0;}
    printf("%d",rta);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
