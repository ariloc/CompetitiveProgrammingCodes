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

const int MAXN = 205;
const ld INF = 9e18;

struct pt {
    ld x,y,z;
};

pt pts[MAXN];
ld D[MAXN][MAXN], P[MAXN][MAXN];
vi path;

void getPath (int u, int v) {
    int x = P[u][v];
    if (x == u) {path.pb(v); return;} // agarro siempre el de la derecha
    getPath(x,v);
    getPath(u,x);
}

ld hypot3D (pt a, pt b) {
    ld c1 = a.x-b.x, c2 = a.y-b.y, c3 = (a.z-b.z)*5; // the distance between floors is 5 meters
    return sqrt(c1*c1 + c2*c2 + c3*c3);
}

int main() {
    forn(i,MAXN) forn(j,MAXN) D[i][j] = INF, P[i][j] = -1;
    forn(i,MAXN) D[i][i] = 0; // distancia a mi mismo es 0

    int n,m; scanf("%d %d",&n,&m);
    forn(i,n) scanf("%Lf %Lf %Lf",&pts[i].z,&pts[i].x,&pts[i].y);
    forn(i,m) {
        int u,v; char s[15]; scanf("%d %d %s",&u,&v,s);
        ld aux;
        if (!strcmp("escalator",s)) {
            aux = hypot3D(pts[u],pts[v])*3;
            if (aux < D[v][u]) D[v][u] = aux, P[v][u] = v; // v -> u
            aux = 1; if (aux < D[u][v]) D[u][v] = aux, P[u][v] = u; // u -> v
        } else {
            if (!strcmp("stairs",s) || !strcmp("walking",s))
                aux = hypot3D(pts[u],pts[v]);
            else aux = 1; // "lift"
            if (aux < D[u][v]) D[u][v] = aux, P[u][v] = u;
            if (aux < D[v][u]) D[v][u] = aux, P[v][u] = v;
        }
    }

    // Floyd-Warshall
    forn(k,n) forn(i,n) forn(j,n) {
        ld aux = D[i][k]+D[k][j];
        if (aux < D[i][j]) D[i][j] = aux, P[i][j] = k;
    }

    int q; scanf("%d",&q);
    forn(i,q) {
        int u,v; scanf("%d %d",&u,&v);
        path.clear(); getPath(u,v); path.pb(u); // agrego el primero que no tiene izq
        dforn(j,path.size()) printf("%d ",path[j]);
        putchar('\n');
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
