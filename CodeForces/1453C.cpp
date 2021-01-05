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

const int MAXN = 2005;
const int MAXD = 10;
const int INF = 1e9+5;

int grid[MAXN][MAXN];
int row[MAXN][2][MAXD], col[MAXN][2][MAXD]; // para row -> 0 (top to bottom), 1 (bottom to top) || para col -> 0 (left to right), 1 (right to left)
// el otro índice es el dígito
int rta[MAXD];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        forn(j,n) {
            string s; cin >> s;
            forn(k,n) grid[j][k] = s[k]-'0';
        }

        forn(j,n) forn(k,2) forn(l,MAXD) row[j][k][l] = col[j][k][l] = INF*(k ? -1 : 1); // reset
        forn(j,MAXD) rta[j] = 0; // reset rta

        forn(j,n) forn(k,n) {
            row[j][0][grid[j][k]] = row[j][1][grid[j][k]] = j;
            col[k][0][grid[j][k]] = col[k][1][grid[j][k]] = k;
        }

        forsn(j,1,n) forn(k,MAXD) {
            row[j][0][k] = min(row[j][0][k],row[j-1][0][k]);
            col[j][0][k] = min(col[j][0][k],col[j-1][0][k]);
        }

        dforn(j,n-1) forn(k,MAXD) {
            row[j][1][k] = max(row[j][1][k],row[j+1][1][k]);
            col[j][1][k] = max(col[j][1][k],col[j+1][1][k]);
        }

        forn(j,n) forn(k,n) {
            int d = grid[j][k], lh = max(n-k-1,k), lv = max(n-j-1,j);
            rta[d] = max({rta[d],lh*(j-row[j][0][d]),lh*(row[j][1][d]-j),lv*(k-col[k][0][d]),lv*(col[k][1][d]-k)});
        }
        forn(j,MAXD) cout << rta[j] << ' ';
        cout << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
