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

const int INF = 1e9+5;

struct DS {
    vi p,r;

    void init (int N) {
        p.assign(N,0);
        r.assign(N,0);
        forn(i,N) p[i] = i;
    }

    int find (int x) {return p[x] == x ? x : p[x] = find(p[x]);}
    bool join (int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x,y);
        p[x] = y; if (r[x] == r[y]) r[y]++;
        return true;
    }
};

struct edge {
    int u,v,s;
};

DS UF;
vector<edge> edges;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n,m,k; cin >> n >> m >> k;

        UF.init(n); // reset
        edges.clear();

        forn(j,m) {
            int u,v,s; cin >> u >> v >> s; u--, v--;
            edges.pb({u,v,s});
        }

        sort(all(edges),[&](const edge &lhs, const edge &rhs){return max(0,lhs.s-k) < max(0,rhs.s-k);});

        int maxi = 0; ll cost = 0;
        for (auto &j : edges)
            if (UF.join(j.u,j.v)) {cost += max(j.s-k,0); if (j.s > maxi) maxi = j.s;}

        if (maxi < k) { // si me quedan todos más chicos, elegiré de antemano una arista que más me convenga, y no debería afectar pues máx una arista entre dos nodos
            UF.init(n); cost = 0; // reseteamos
            int mini = INF, ind = -1;
            forn(o,edges.size()) {
                int aux = abs(edges[o].s-k);
                if (aux < mini) mini = aux, ind = o;
            }
            UF.join(edges[ind].u,edges[ind].v); cost += mini;

            for (auto &j : edges)
                if (UF.join(j.v,j.u)) cost += max(j.s-k,0);
        }

        cout << cost << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
