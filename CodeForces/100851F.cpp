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

const int MAXN = 3005;

struct edges {
    int v; ld w;

    bool operator< (const edges &o) const {
        return w > o.w;
    }
};

struct pt {
    ld x,y;
};

struct dijkEdge {
    int v; ld w; bool used; pt jmp;

    bool operator< (const dijkEdge &o) const {
        return w > o.w;
    }
};

pt pts[MAXN];
vector<edges> G[MAXN];
ld D[MAXN][2];

pt midPoint(pt a, pt b) {
    return {(a.x+b.x)/(ld)2,(a.y+b.y)/(ld)2};
}

pt dijkstra (int n, int w) {
    priority_queue<dijkEdge> Q;
    forn(i,n) {
        Q.push({i,pts[i].x,0,{.5,0}}), D[i][0] = pts[i].x; // .5 por si w = 1, entonces no toca ningún borde
        ld aux = pts[i].x/(ld)2;
        Q.push({i,aux,1,{aux,pts[i].y}}), D[i][1] = aux;
    }

    while (!Q.empty()) {
        auto e = Q.top(); Q.pop();

        if (pts[e.v].x == w) return e.jmp;

        for (auto &i : G[e.v]) {
            if (D[i.v][e.used] == -1 || D[i.v][e.used] > max(D[e.v][e.used],i.w)) { // 0 -> 0 || 1 -> 1
                D[i.v][e.used] = max(D[e.v][e.used],i.w);
                Q.push({i.v,D[i.v][e.used],e.used,e.jmp});
            }

            if (!e.used && (D[i.v][1] == -1 || D[i.v][1] > max(D[e.v][0],i.w/(ld)2))) { // 0 -> 1
                D[i.v][1] = max(D[e.v][0],i.w/(ld)2);
                Q.push({i.v,D[i.v][1],1,midPoint(pts[e.v],pts[i.v])});
            }
        }
    }

    return {.5,0};
}

int main() {
    freopen("froggy.in","r",stdin);
    freopen("froggy.out","w",stdout);

    int w,n; scanf("%d %d",&w,&n);

    pts[0] = {0,0}; // el origen
    forn(i,n) scanf("%Lf %Lf",&pts[i].x,&pts[i].y);
    int auxn = n; // agrego el pts[0] como cantidad
    forn(i,auxn) pts[n++] = {(ld)w,pts[i].y}; // agrego saltos finales

    forn(i,n) forsn(j,i+1,n) { // armo grafo completo
        ld d = hypot(abs(pts[i].x-pts[j].x),abs(pts[i].y-pts[j].y));
        G[i].pb({j,d}), G[j].pb({i,d});
    }

    pt rta = dijkstra(n,w);
    printf("%.3Lf %.3Lf",rta.x,rta.y);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
sss
