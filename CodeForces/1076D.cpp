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

const int MAXN = 3e5+5;

struct edges {
    int v; ll w; int id;

    bool operator< (const edges &o) const {
        return w > o.w;
    }
};

vector<edges> G[MAXN];
ll D[MAXN]; // DANG IT OVERFLOW !!!
int toKeep[MAXN],depth[MAXN];
bitset<MAXN> done,pass;
set<int> notProhib;

void dijkstra (int st) {
    priority_queue<edges> Q;
    Q.push({st,0,-1}); D[st] = 0; // -1 es placeholder

    while (!Q.empty()) {
        auto e = Q.top(); Q.pop();

        if (pass[e.v]) continue;
        pass[e.v] = true;

        for (auto &i : G[e.v])
            if (D[i.v] == -1 || D[i.v] > D[e.v] + i.w) {
                D[i.v] = D[e.v] + i.w;
                toKeep[i.v] = i.id;
                Q.push({i.v,D[i.v],-1});
            }
    }
}

void bfs (int st) {
    queue<ii> Q;
    Q.push({st,0}); done[st] = true;

    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        for (auto &i : G[e.fst])
            if (!done[i.v] && notProhib.count(i.id)) {
                done[i.v] = true;
                depth[i.id] = e.snd+1;
                Q.push({i.v,e.snd+1});
            }
    }
}

int main() {
    forn(i,MAXN) toKeep[i] = depth[i] = D[i] = -1; // init
    int n,m,k; scanf("%d %d %d",&n,&m,&k);
    forn(i,m) {
        int u,v,w; scanf("%d %d %d",&u,&v,&w); u--, v--;
        G[u].pb({v,w,i}); G[v].pb({u,w,i});
    }

    dijkstra(0);
    forn(i,n) if (toKeep[i] != -1) notProhib.insert(toKeep[i]);

    if ((int)notProhib.size() <= k) {
        // me olvidé maximizar...oops
        forn(i,m) {
            if ((int)notProhib.size() == k) break;
            if (!notProhib.count(i)) notProhib.insert(i);
        }

        OUT:
        printf("%d\n",(int)notProhib.size());
        for (auto &i : notProhib) printf("%d ",i+1);
        return 0;
    }

    bfs(0); // funca porque ahora es un rooted tree
    priority_queue<ii> toDel;
    forn(i,m) if (depth[i] != -1) toDel.push({depth[i],i});
    k = abs((int)notProhib.size()-k);
    while (!toDel.empty() && k > 0)
        notProhib.erase(toDel.top().snd), toDel.pop(), k--;
    goto OUT;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
