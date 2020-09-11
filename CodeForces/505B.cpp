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

const int MAXN = 105;

bitset<MAXN> done;

struct edges {
    int v,c;
};

vector<edges> G[MAXN];

bool dfs(int st, int c, int nd) {
    done[st] = true;

    bool can = false;
    for(auto &i : G[st]) {
        if (i.c != c) continue;
        if (!done[i.v]) can |= dfs(i.v,c,nd);
    }

    return (can|(st == nd));
}

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,m) {
        int a,b,c; cin >> a >> b >> c; a--; b--; c--;
        G[a].pb({b,c}); G[b].pb({a,c});
    }

    int q; cin >> q;
    forn (i,q) {
        int a,b; cin >> a >> b; a--; b--;
        int cnt = 0;
        forn(j,m){
            done.reset();
            cnt += dfs(a,j,b);
        }
        cout << cnt << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
