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

const int MAXN = 2e5;

vi G[MAXN];
vector<ii> queries[MAXN];
int rta[MAXN];
vi path;

void dfs(int st) {
    path.pb(st);

    for (auto &i : queries[st]) {
        int ind = (int)path.size()-i.fst-1;
        rta[i.snd] = (ind < 0 ? -1 : path[ind]+1);
    }

    for (auto &i : G[st]) dfs(i);

    path.pop_back();
}

int main() {
    int n,q; scanf("%d %d",&n,&q);
    forn(i,n-1) {
        int x; scanf("%d",&x);
        G[x-1].pb(i+1);
    }
    forn(i,q) {
        int x,k; scanf("%d %d",&x,&k);
        queries[x-1].pb({k,i});
    }

    dfs(0);

    forn(i,q) printf("%d\n",rta[i]);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
