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

const int MOD = 1e9+7;
const int MAXN = 1002;

int dp[2*MAXN][MAXN][2]; // para la fila, para el k, para la dimensión que lo haga

int main() {
    FAST_IO;

    int med[2];
    int n,m,k; cin >> med[0] >> med[1] >> k; // digamos que hay m columnas y n filas
    med[0] -= 2; med[1] -= 2;

    forn(j,2) forn(i,med[j]) dp[0][i][j] = 1;
    forn(l,2) {
        forn(i,(2*k)-1) {
            int sum = 0;
            forn(j,med[l]) {
                dp[i+1][j][l] = (((dp[i+1][j][l]+sum)%MOD)+(i == (2*k)-2 ? dp[i][j][l] : 0))%MOD;
                sum = (sum+dp[i][j][l])%MOD;
            }
        }
    }

    int r[2] = {0,0};
    forn(l,2) forn(i,med[l]) r[l]=(r[l]+dp[2*k-1][i][l])%MOD;

    cout << (((ll)r[0]*r[1])+MOD)%MOD;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
