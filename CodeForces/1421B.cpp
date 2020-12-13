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

const int MAXN = 205;

char grid[MAXN][MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        forn(j,n) forn(k,n) cin >> grid[j][k];
        bool colSt = 0;
        if ((grid[0][1] == grid[1][0] && grid[0][1] == '1') ||
            (grid[n-1][n-2] == grid[n-2][n-1] && grid[n-1][n-2] == '0')) colSt = 1;
        vector<ii> ch;
        if (grid[0][1] != (colSt+'0')) ch.pb({0,1});
        if (grid[1][0] != (colSt+'0')) ch.pb({1,0});
        if (grid[n-1][n-2] == (colSt+'0')) ch.pb({n-1,n-2});
        if (grid[n-2][n-1] == (colSt+'0')) ch.pb({n-2,n-1});

        cout << (int)ch.size() << '\n';
        for (auto &j : ch) cout << j.fst+1 << ' ' << j.snd+1 << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
