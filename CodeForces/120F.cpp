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

const int MAXN = 105;

vi G[MAXN];
bitset<MAXN> done;
int maxi = -1, nod = -1;

void dfs (int st, int dep) {
    done[st] = true;
    if (dep > maxi) maxi = dep, nod = st;

    for (auto &i : G[st])
        if (!done[i]) dfs(i,dep+1);
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    FAST_IO;

    int n; cin >> n;

    int rta = 0;
    forn(i,n) {
        int m; cin >> m;
        forn(j,m) G[j].clear(); // reset

        forn(j,m-1) {
            int u,v; cin >> u >> v; u--, v--;
            G[u].pb(v), G[v].pb(u);
        }

        done.reset(); nod = maxi = -1; dfs(0,0);
        int aux = nod; done.reset(); nod = maxi = -1; dfs(aux,0);
        rta += maxi;
    }

    cout << rta;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
