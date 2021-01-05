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

const int MAXN = 102;
const int MAXA = 27;

struct edges {
    int v; char c;
};

vector<edges> G[MAXN];
int dp[MAXN][MAXN][MAXA][2];

int solve (int a, int b, int let, bool turn) {
    if (dp[a][b][let][turn] != -1) return dp[a][b][let][turn];
    bool win = false;
    for (auto &i : G[(turn ? a : b)])
        if ((i.c-'a') >= let-1) win |= !solve((turn ? i.v : a),(turn ? b : i.v),i.c-'a'+1,!turn);
    return dp[a][b][let][turn] = win;
}

int main() {
    FAST_IO;
    memset(dp,-1,sizeof(dp));

    int n,m; cin >> n >> m;
    forn(i,m) {
        int u,v; char c; cin >> u >> v >> c; u--; v--;
        G[u].pb({v,c});
    }

    forn(i,n) {forn(j,n) cout << (solve(i,j,0,1) ? "A" : "B"); cout << '\n';}

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
