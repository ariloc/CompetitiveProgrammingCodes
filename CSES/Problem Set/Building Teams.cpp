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

const int MAXN = 1e5+5;

vi G[MAXN];
int col[MAXN];
bool bipart = true;

void dfs(int st, bool myCol) {
    if (col[st] != -1) {
        if (col[st] != myCol) bipart = false;
        return;
    }
    col[st] = myCol;

    for (auto &i : G[st]) dfs(i,!myCol);
}

int main() {
    FAST_IO;

    memset(col,-1,sizeof(col));

    int n,m; cin >> n >> m;

    forn (i,m) {
        int a,b; cin >> a >> b; a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    forn (i,n) if (col[i] == -1) dfs(i,0);

    if (!bipart) cout << "IMPOSSIBLE";
    else forn (i,n) cout << col[i]+1 << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
