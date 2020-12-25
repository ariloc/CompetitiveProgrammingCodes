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

const int MAXN = 1e5+5;

struct edges {
    int v; ll w;

    bool operator< (const edges &o) const {
        return w > o.w;
    }
};

vector<edges> G[MAXN];
pair<ii,int> coords[MAXN];
ll D[MAXN]; int n,m;
bitset<MAXN> done;

void dijkstra (int st) {
    priority_queue<edges> Q;
    D[st] = 0; Q.push({st,0});

    while (!Q.empty()) {
        auto e = Q.top().v; Q.pop();

        if (done[e]) continue;
        done[e] = true;

        for (auto &i : G[e]) {
            if (D[i.v] == -1 || D[i.v] > D[e]+i.w) {
                D[i.v] = D[e]+i.w;
                Q.push({i.v,D[i.v]});
            }
        }
    }
}

int getDist (int a, int b) {
    return min(abs(coords[a].fst.fst-coords[b].fst.fst),abs(coords[a].fst.snd-coords[b].fst.snd));
}

int getDistM (int a, int b) {
    return abs(coords[a].fst.fst-coords[b].fst.fst)+abs(coords[a].fst.snd-coords[b].fst.snd);
}

void drawEdges() {
    forn(i,m-1) { // instant-movement locations
        int v = getDist(i,i+1);
        G[coords[i].snd].pb({coords[i+1].snd,v});
        G[coords[i+1].snd].pb({coords[i].snd,v});
    }
}

int main() {
    FAST_IO;

    forn(i,MAXN) D[i] = -1; // init

    cin >> n >> m;
    int sx,sy,fx,fy; cin >> sx >> sy >> fx >> fy;
    forn(i,m) {int x,y; cin >> x >> y; coords[i] = {{x,y},i};}
    coords[m] = {{sx,sy},m}; coords[m+1] = {{fx,fy},m+1};

    forn(i,m) { // st & nd
        G[m].pb({coords[i].snd,getDist(i,m)});
        G[coords[i].snd].pb({m+1,getDistM(i,m+1)});
    }
    G[m].pb({m+1,getDistM(m,m+1)});

    // by X
    sort(coords,coords+m); // OJO, justo hasta m, el resto no toco (igual abajo)
    drawEdges();

    // by Y
    sort(coords,coords+m,[](const pair<ii,int> &lhs, const pair<ii,int> &rhs)
        {
            if (lhs.fst.snd == rhs.fst.snd) {
                if (lhs.fst.fst == rhs.fst.fst) return lhs.snd < rhs.snd;
                return lhs.fst.fst < rhs.fst.fst;
            }
            return lhs.fst.snd < rhs.fst.snd;
        });
    drawEdges();

    dijkstra(m);

    cout << D[m+1];

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
