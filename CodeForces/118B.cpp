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

const int MAXN = 1000;

char mat[MAXN][MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;

    forn (j,n+1) {
        int halfL = n, halfR = n, ind = j;
        forn (i,n-j) {
            mat[halfL--][ind] = j+'0';
            mat[halfR++][ind] = j+'0';
            ind++;
        }
        forn (i,n+1-j) {
            mat[halfL++][ind] = j+'0';
            mat[halfR--][ind] = j+'0';
            ind++;
        }
    }

    forn (i,2*n+1) {
        forn(j,2000) {
            if (mat[i][j]) {
                cout << mat[i][j];
                if (!mat[i][j+1]) break;
                cout << ' ';
            } else cout << "  ";
        }
        cout << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!