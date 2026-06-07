#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(c) (c).size()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

int const MAXN = 1e5+5;
int const MAXK = 21;
int const INF = 2e9;

struct edge {
    int v,e;
};

int D[MAXK][MAXN];
vector<edge> G[MAXN];

int main() {
    FAST_IO;
    
    int n,m,k; cin >> n >> m >> k;
    
    forn(i,m) {
        int u,v,e; cin >> u >> v >> e; --u, --v;
        G[u].pb({v,e});
        G[v].pb({u,e});
    }
    
    queue<ii> Q;
    Q.push({0,0});
    forn(i,MAXK) forn(j,MAXN) D[i][j] = -1;
    D[0][0] = 0;
    int rta = -1;
    while (!Q.empty()) {
        ii e = Q.front(); Q.pop();
        
        if (e.fst == n-1) {
            rta = D[e.snd][e.fst];
            break;
        }
        
        for (auto &ed : G[e.fst]) {
            if (ed.e && e.snd+1 <= k && D[e.snd+1][ed.v] == -1) {
                D[e.snd+1][ed.v] = D[e.snd][e.fst]+1;
                Q.push({ed.v, e.snd+1});
            }
            if (!ed.e && D[e.snd][ed.v] == -1) {
                D[e.snd][ed.v] = D[e.snd][e.fst]+1;
                Q.push({ed.v, e.snd});
            }
        }
    }
    
    cout << rta << '\n';
    
    return 0;
}
