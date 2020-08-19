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

const int MAXN = 2002;
const int INF = 1e9+2;

int cubo[MAXN][MAXN], TAdDiag[MAXN][MAXN];

int main() {
    freopen("latas.in","r",stdin);
    freopen("latas.out","w",stdout);

    int N; scanf("%d",&N);

    int sum = 0;
    forn (i,N) forn (j,i+1) {scanf("%d",&cubo[i][j]); sum += cubo[i][j];}

    forn (i,N-1) { // sumo diagonales hacia abajo
        int accum = 0;
        for (int x = 0, y = i; y >= 0; x++, y--)
            {accum += cubo[y][x]; TAdDiag[y][x] = accum;}
    }

    forn (i,N) {
        int accum = 0;
        for (int x = i, y = N-1; y >= 0; x++, y--)
            {accum += cubo[y][x]; TAdDiag[y][x] = accum;}
    }

    forn (i,N) { // Uno diagonales así tengo supuestos triángulos
        int accum = 0;
        forn (j,MAXN)
            {accum += TAdDiag[i][j]; TAdDiag[i][j] = accum;}
    }

    forn (i,MAXN) { // TAd 2D común
        int accum = 0;
        forn (j,MAXN) {
            if (i+1 < MAXN) cubo[i+1][j] += cubo[i][j];
            accum += cubo[i][j];
            cubo[i][j] = accum;
        }
    }

    // En resumen, tengo una tabla aditiva diagonal y otra común

    /*forn (i,N) {
    forn (j,N) cout << cubo[i][j] << ' ';
     cout << endl;}*/

    int toMove = INF;
    forn (i,N) {
        forn (j,MAXN) {
            int calc = TAdDiag[i][j];
            if (j >= N) {
                calc -= TAdDiag[i+N][j-N];
                calc -= (cubo[i+N-1][j-N] - (i-1 < 0 ? 0 : cubo[i-1][j-N]));
            }
            //if (i == 5 and j == 9) cout << TAdDiag[i+N][j-N] << ' ' << TAdDiag[i][j] << ' ' << (cubo[i+N-1][j-N] - cubo[i-1][j-N]) << endl;
            toMove = min(toMove,sum-calc);
        }
    }

    printf("%d",toMove);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
