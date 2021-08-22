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

const int MAXN = 5005;
const int INF = 2e9+5;

struct edges {
    int v, w;
};

vector<edges> G[MAXN];
int dp[MAXN][MAXN];
int P[MAXN][MAXN];
int n,m,T;

int solve(int st, int k) {
    if ((k != 0 and !st) or k < 0) return INF;
    if (!st) return 0;
    if (dp[st][k] != -1) return dp[st][k];

    int mini = INF;
    for (auto &i : G[st]) {
        ll calc = solve(i.v,k-1) + i.w;
        if (calc > T or calc < 0) continue; // < 0 por si da overflow
        if (calc < mini) {
            mini = calc;
            P[st][k] = i.v;
        }
    }

    return dp[st][k] = mini;
}

int main() {
    FAST_IO;

    memset(P,-1,sizeof(P));
    forn(i,MAXN) forn(j,MAXN) {dp[i][j] = -1;} // reset

    cin >> n >> m >> T;

    forn (i,m) {
        int a,b,w; cin >> a >> b >> w; a--; b--;
        G[b].pb({a,w});
    }

    G[MAXN-1].pb({n-1,0});

    forn (i,MAXN) dp[0][i] = 0;
    dforsn (i,1,n+1) solve(MAXN-1,i);

    int rta = -1;
    dforsn (i,1,n+1) if (dp[MAXN-1][i] <= T) {rta = i; break;}

    vi path;
    int tmpR = rta;
    for (int e = MAXN-1; e != -1; e = P[e][tmpR--]) {
        path.pb(e+1);
    }

    cout << rta << '\n';
    dforsn (i,1,path.size()) cout << path[i] << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!