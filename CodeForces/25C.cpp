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

const int MAXN = 1005;

ll mat[MAXN][MAXN];

int main() {
    FAST_IO;

    int N; cin >> N;

    ll sum = 0;
    forn (i,N) forn(j,N) {cin >> mat[i][j]; sum += mat[i][j];}

    int M; cin >> M;
    forn (i,M) {
        int a,b,w; cin >> a >> b >> w; a--; b--;
        forn(j,N) forn(k,N) {
            sum -= mat[j][k];
            mat[j][k] = min(mat[j][k],mat[j][a]+w+mat[b][k]);
            mat[j][k] = min(mat[j][k],mat[j][b]+w+mat[a][k]);
            sum += mat[j][k];
        }
        cout << sum/2 << ' ';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!