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

const int MAXN = 2e5+5;
const int INF = 1e9+5;

vi G[MAXN];
int D1[MAXN],D2[MAXN],spec[MAXN],dpR[MAXN];

void bfs (int st, int D[]) {
    queue<ii> Q; Q.push({st,0}); D[st] = 0;

    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        for (auto &i : G[e.fst])
            if (D[i] == -1) D[i] = e.snd+1, Q.push({i,D[i]});
    }
}

int main() {
    FAST_IO;

    forn(i,MAXN) D1[i] = D2[i] = -1; // init

    int n,m,k; cin >> n >> m >> k;
    forn(i,k) {int x; cin >> x; x--; spec[i] = x;}
    forn(i,m) {
        int u,v; cin >> u >> v; u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    bfs(0,D1), bfs(n-1,D2);

    int maxi = 0;
    sort(spec,spec+k,[&](const int &lhs, const int &rhs){return D1[lhs] < D1[rhs];}); // menor a mayor al origen
    dforn(i,k) dpR[i] = max(dpR[i+1],D2[spec[i]]); // el mayor a este punto
    forn(i,k-1) maxi = max(maxi,D1[spec[i]]+dpR[i+1]+1);

    cout << min(maxi,D2[0]);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
