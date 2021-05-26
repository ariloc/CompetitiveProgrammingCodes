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

const int MAXN = 40000;

vector<ii> pcs,edges;
int deg[MAXN];

int main() {
    FAST_IO;

    freopen("subredes02.in","r",stdin);

    int n; cin >> n;
    forn(i,n) {string s; cin >> s;} // los descarto porque es para el caso particular

    int k; cin >> k;
    forn(i,k) {
        int r,m; cin >> r >> m;
        pcs.pb({r,m});
    }

    forn(i,k) {
        forn(j,MAXN) deg[j] = 0;
        edges.clear();

        forn(j,pcs[i].snd) {
            int u,v; cin >> u >> v; u--; v--;
            deg[u]++, deg[v]++;
            edges.pb({u,v});
        }

        ll rta = 0;
        for (auto &j : edges)
            rta += pcs[i].snd-deg[j.fst]-deg[j.snd]+1;

        cout << rta/2 << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
