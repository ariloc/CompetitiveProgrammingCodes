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
const int INF = 1e9+5;

vi G[MAXN];//,RG[MAXN];
int dist[MAXN],rta[MAXN];
bitset<MAXN> done,done2;

void bfs (int st) {
    queue<int> Q; dist[st] = 0;
    Q.push(st); done[st] = true;
    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        for (auto &i : G[e]) {
            if (done[i]) continue;
            dist[i] = dist[e]+1;
            done[i] = true;
            Q.push(i);
        }
    }
}


int dfs (int st) {
    done2[st] = true;

    int mini = rta[st];
    for (auto &i : G[st]) {
        if (dist[i] > dist[st]) mini = min(mini,dfs(i));
        else mini = min(mini,dist[i]);
    }

    return rta[st] = mini;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n,m; cin >> n >> m;

        forn(j,n) {
            G[j].clear();// RG[j].clear();
            done[j] = done2[j] = false;
            dist[j] = 0;
        }

        forn(j,m) {
            int u,v; cin >> u >> v; u--, v--;
            G[u].pb(v);// RG[v].pb(u);
        }
        bfs(0); // distances from capital
        forn(j,n) rta[j] = dist[j];
        forn(j,n) for (auto &k : G[j]) rta[j] = min(rta[j],dist[k]);

        dfs(0);

        forn(j,n) cout << rta[j] << ' ';
        cout << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
