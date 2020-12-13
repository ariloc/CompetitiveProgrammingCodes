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

const int MAXN = 502;
const ll INF = 1e18+5;

char grid[MAXN][MAXN];
ll dp[MAXN][MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n,m; cin >> n >> m;
        forn(j,n) forn(k,m) cin >> grid[j][k];
        forn(j,n) forn(k,m) dp[j][k] = (grid[j][k] == '*');
        ll rta = 0;
        dforn(j,n) forn(k,m)
            if (dp[j][k]) {
                ll mini = INF, cnt = 0;
                if (j+1 < n && k-1 >= 0) mini = min(mini,dp[j+1][k-1]), cnt++; else mini = 0;
                if (j+1 < n) mini = min(mini,dp[j+1][k]), cnt++; else mini = 0;
                if (j+1 < n && k+1 < m) mini = min(mini,dp[j+1][k+1]), cnt++; else mini = 0;
                dp[j][k] += mini;
            }
        forn(j,n) forn(k,m) rta += dp[j][k];

        cout << rta << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
