#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 402;

ld dp[MAXN][MAXN]; // haciendo el k-ésimo flip, la cantidad de monedas boca arriba

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;

    dp[0][0] = 1;
    forn(i,k) {
        forn(j,n) { // agarraré siempre uno que solo me sume
            dp[i+1][j] += dp[i][j]/2;
            dp[i+1][j+1] += dp[i][j]/2;
        }
        // caso n, tengo outcome nulo o negativo, y estoy obligado
        dp[i+1][n-1] += dp[i][n]/2;
        dp[i+1][n] += dp[i][n]/2;
    }

    ld rta = 0;
    forn(j,n+1) rta += dp[k][j]*j;

    cout << fixed << setprecision(15) << rta;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
