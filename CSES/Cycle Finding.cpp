#include <bits/stdc++.h>

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

const int MAXN = 2502;
const ll INF = 1e18;

struct edges {
    int v,w;
};

vector<edges> G[MAXN];
int P[MAXN]; ll D[MAXN];

int main() {
    forn(i,MAXN) P[i] = -1;
    int n,m; scanf("%d %d",&n,&m);

    forn(i,m) {
        int u,v,w; scanf("%d %d %d",&u,&v,&w); u--; v--;
        G[u].pb({v,w});
    }

    int x = -1;
    forn(i,n) {x = -1; forn(u,n) for(auto &v : G[u]) {
        ll d = D[u]+v.w;
        if (d < D[v.v]) {D[v.v] = d; P[v.v] = u; x = v.v;}
    }}

    vi negCycle;
    if (x != -1) {
        forn(i,n) x = P[x];
        for (int i = x; ; i = P[i]) {
            negCycle.pb(i);
            if (i == x and negCycle.size() > 1) break;
        }
    }
    if (negCycle.empty()) printf("NO");
    else {
        printf("YES\n");
        dforn(i,negCycle.size()) printf("%d ",negCycle[i]+1);
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
