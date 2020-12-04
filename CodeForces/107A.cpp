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

const int MAXN = 1002;
const int INF = 1e9;

struct ans {int a,b,c;};

vector<ii> G[MAXN];
int inDegree[MAXN];
bitset<MAXN> done;
vector<ans> rta;

void dfs (int st, int orig, int mini) {
    done[st] = true;

    for (auto &i : G[st])
        if (!done[i.fst]) dfs(i.fst,orig,min(mini,i.snd));

    if (G[st].empty()) rta.pb({orig,st,mini});
}

int main() {
    FAST_IO;

    int n,p; cin >> n >> p;
    forn(i,p) {
        int u,v,w; cin >> u >> v >> w; u--, v--;
        G[u].pb({v,w});
        inDegree[v]++;
    }

    forn(i,n) if (!inDegree[i] && !done[i] && !G[i].empty()) dfs(i,i,INF);

    cout << rta.size() << '\n';
    for (auto &i : rta) cout << i.a+1 << ' ' << i.b+1 << ' ' << i.c << '\n';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
