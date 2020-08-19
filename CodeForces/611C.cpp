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

const int MAXN = 505;

char tablero[MAXN][MAXN];
int ways[MAXN][MAXN];

int main() {
    FAST_IO;

    int h,w; cin >> h >> w;

    forn(i,h) forn(j,w) cin >> tablero[i][j];

    forn(j,h) forn(k,w) {
        int posib = 0;
        if (tablero[j][k] == '#') continue;
        if ((k+1) < w and tablero[j][k+1] != '#') posib++;
        if ((j+1) < h and tablero[j+1][k] != '#') posib++;
        ways[j+1][k+1] = posib;
    }

    forn (i,MAXN) { // TAd 2D
        int acc = 0;
        forn(j,MAXN) {
            acc += ways[i][j];
            if (i < MAXN-1) ways[i+1][j] += ways[i][j];
            ways[i][j] = acc;
        }
    }

    //forn(i,h+1) {forn(j,w+1) cout << ways[i][j] << ' '; cout << endl;}

    int q; cin >> q;
    forn(i,q) {
        int r1,c1,r2,c2; cin >> r1 >> c1 >> r2 >> c2;

        int posib = ways[r2][c2] + ways[r1-1][c1-1] - ways[r2][c1-1] - ways[r1-1][c2];
        if (c2 != w) forsn (j,r1,r2+1) if (tablero[j-1][c2] != '#' and tablero[j-1][c2-1] != '#') posib--;
        if (r2 != h) forsn (j,c1,c2+1) if (tablero[r2][j-1] != '#' and tablero[r2-1][j-1] != '#') posib--;

        cout << posib << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!