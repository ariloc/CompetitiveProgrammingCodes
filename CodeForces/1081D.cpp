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

struct edge {
    int u,v,w;

    bool operator< (const edge &o) const {
        return w < o.w;
    }
};

struct DS {
    vi p,r,maxE;
    vector<bool> special;

    void init (int N) {
        p.assign(N,0);
        r.assign(N,0);
        special.assign(N,0);
        maxE.assign(N,0);
        forn(i,N) p[i] = i;
    }

    int find (int x) {return p[x] == x ? x : p[x] = find(p[x]);}
    bool join (int a, int b, int w) {
        int x = find(a), y = find(b);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x,y);
        p[x] = y; if (r[x] == r[y]) r[y]++;
        if (special[y] && special[x]) maxE[y] = w; // como voy en orden, siempre es el más grande, y además sólo si hay nodos especiales en ambos
        else if (special[x]) maxE[y] = maxE[x]; // si no, hereda el de su hijo
        bool aux1 = special[y], aux2 = special[x];
        special[y] = aux1|aux2;
        return true;
    }
};

DS UF;
vector<edge> edges;
vi spec;

int main() {
    int n,m,k; scanf("%d %d %d",&n,&m,&k);
    UF.init(n+5);
    forn(i,k) {
        int x; scanf("%d",&x); x--; spec.pb(x);
        UF.special[x] = true; // marco los que tienen nodos especiales
    }
    forn(i,m) {
        int u,v,w; scanf("%d %d %d",&u,&v,&w); u--, v--;
        edges.pb({u,v,w});
    }

    sort(all(edges));

    for (auto &i : edges) UF.join(i.u,i.v,i.w);

    forn(i,k) printf("%d ",UF.maxE[UF.find(spec[i])]);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
