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

const int MAXN = 2e5+2;
const ll INF = 9e18;

struct edges {
    ll v,w;
};

struct nodoDijk {
    ll v,w,mini,maxi;
    bool fixedMin, fixedMax;

    bool operator< (const nodoDijk &o) const {
        return w > o.w;
    }
};

vector<edges> G[MAXN];
ll D[MAXN][2][2]; // if fixedMin 0,1 | if fixedMax 0,1
bool done[MAXN][2][2];

void dijkstra (int st) {
    priority_queue<nodoDijk> Q;
    Q.push({st,0,INF,0,0,0});
    D[st][0][0] = 0;

    while (!Q.empty()) {
        auto e = Q.top(); Q.pop();

        if (done[e.v][e.fixedMin][e.fixedMax]) continue;
        done[e.v][e.fixedMin][e.fixedMax] = true;

        //cerr << e.v << ' ' << e.w << ' ' << e.fixedMin << ' ' << e.fixedMax << endl;

        for (auto &i : G[e.v]) {
            if (e.fixedMin && i.w < e.mini) continue;
            if (e.fixedMax && i.w > e.maxi) continue;

            if (D[i.v][e.fixedMin][e.fixedMax] == -1 || D[i.v][e.fixedMin][e.fixedMax] > D[e.v][e.fixedMin][e.fixedMax] + i.w) { // si no toco nada
                D[i.v][e.fixedMin][e.fixedMax] = D[e.v][e.fixedMin][e.fixedMax] + i.w;
                Q.push({i.v,D[i.v][e.fixedMin][e.fixedMax],min(e.mini,i.w),max(e.maxi,i.w),e.fixedMin,e.fixedMax});
            }

            ll calc1 = D[e.v][e.fixedMin][e.fixedMax] + 2LL*i.w, calc2 = D[e.v][e.fixedMin][e.fixedMax], calc3 = D[e.v][e.fixedMin][e.fixedMax] + i.w;
            if (!e.fixedMin && i.w <= e.mini && (D[i.v][1][e.fixedMax] == -1 || D[i.v][1][e.fixedMax] > calc1)) { /// IMP!, cambiar la condición a un menor o igual si es necesario
                D[i.v][1][e.fixedMax] = calc1;
                Q.push({i.v,calc1,min(e.mini,i.w),max(e.maxi,i.w),1,e.fixedMax});
            }
            if (!e.fixedMax && i.w >= e.maxi && (D[i.v][e.fixedMin][1] == -1 || D[i.v][e.fixedMin][1] > calc2)) { // si puedo hacer a máx
                D[i.v][e.fixedMin][1] = calc2;
                Q.push({i.v,calc2,min(e.mini,i.w),max(e.maxi,i.w),e.fixedMin,1});
            }
            if (!e.fixedMin && !e.fixedMax && i.w <= e.mini && i.w >= e.maxi && (D[i.v][1][1] == -1 || D[i.v][1][1] > calc3)) { // si puedo hacer ambos
                D[i.v][1][1] = calc3;
                Q.push({i.v,calc3,min(e.mini,i.w),max(e.maxi,i.w),1,1});
            }
        }
    }
}

int main() {
    FAST_IO;
    forn(i,MAXN) forn(j,2) forn(k,2) D[i][j][k] = -1;

    int n,m; cin >> n >> m;
    forn(i,m) {
        int u,v,w; cin >> u >> v >> w; u--, v--;
        G[u].pb({v,w});
        G[v].pb({u,w});
    }

    dijkstra(0);

    forn(j,n-1) cout << D[j+1][1][1] << ' ';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
