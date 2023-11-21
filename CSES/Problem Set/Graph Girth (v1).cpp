#include<bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 2505;
int const INF = 1e9;

struct edges {
    int v,id;
};

struct edge {
    int u,v;
};

vector<edges> G[MAXN];
bitset<MAXN> done;
vector<edge> ari;
int block = -1;
int D[MAXN];
int n,m;

void bfs (int st) {
    forn(i,n) done[i] = 0, D[i] = INF;
    done[st] = true, D[st] = 0;
    queue<ii> Q;
    Q.push({st,0});

    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        for (auto &i : G[e.fst]) {
            if (i.id == block) continue;
            if (done[i.v]) continue;
            done[i.v] = true;
            D[i.v] = e.snd+1;
            Q.push({i.v,e.snd+1});
        }
    }
}

int main() {
    FAST_IO;

    cin >> n >> m;
    forn(i,m) {
        int u,v; cin >> u >> v; u--, v--;
        ari.pb({u,v});
        G[u].pb({v,i}), G[v].pb({u,i});
    }

    int mini = INF;
    forn(i,m) {
        block = i;
        bfs(ari[i].u);
        mini = min(mini,D[ari[i].v]);
    }

    cout << (mini == INF ? -1 : mini+1) << '\n';

    return 0;
}
