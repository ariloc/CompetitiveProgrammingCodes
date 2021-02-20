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

const int MAXN = 1e4+5;

vi G[MAXN];
bitset<MAXN> done;
int prox_libre = 0;
ii rta[MAXN];

void dfs (int st) {
    done[st] = true;
    rta[st].snd = prox_libre++;

    // para el primero ambas pueden ser nuevas bandas
    // entonces si tengo más de una arista libre, entonces encajo mi frecuencia vieja así suma uno más en tal caso
    bool pass = 0;
    for (auto &i : G[st])
        if (!done[i]) {
            rta[i].fst = (!pass ? rta[st].snd : rta[st].fst);
            dfs(i);
            pass = 1;
        }
}

int main() {
    int n; scanf("%d",&n);
    forn(i,n-1) {
        int u,v; scanf("%d %d",&u,&v); u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    rta[0].fst = prox_libre++;
    dfs(0);

    forn(i,n) if (((int)G[i].size() == 1)) rta[i] = rta[G[i][0]]; // con las hojas vamos a doble banda

    forn(i,n) printf("%d %d\n",rta[i].fst,rta[i].snd);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
