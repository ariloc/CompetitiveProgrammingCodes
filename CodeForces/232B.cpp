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

const int MAXN = 105;
const int MOD = 1e9+7;

int dp[MAXN][MAXN*MAXN]; // estando en la i-ésima columna, habiendo puesto j puntos
int vals[MAXN][MAXN]; // cantidad de posibilidades si pongo j puntos en la i-ésima columna
int fact[MAXN],factInv[MAXN],inv[MAXN];

void precomp() {
    fact[0] = 1;
    forsn(i,1,MAXN) fact[i] = (fact[i-1]*(ll)i)%MOD;

    inv[1] = 1;
    forsn(i,2,MAXN) inv[i] = MOD - ((MOD/(ll)i)*(ll)inv[MOD%i])%MOD;

    factInv[0] = 1;
    forsn(i,1,MAXN) factInv[i] = (factInv[i-1]*(ll)inv[i])%MOD;
}

int nCr (int n, int r) {
    if (r > n) return 0;
    return (((fact[n]*(ll)factInv[r])%MOD)*(ll)factInv[n-r])%MOD;
}

int binExp (int a, ll k) {
    int r = 1;
    while (k) {
        if (k&1) r = (r*(ll)a)%MOD;
        a = (a*(ll)a)%MOD; k >>= 1;
    }
    return r;
}

int main() {
    FAST_IO;

    precomp();

    ll n,m,k; cin >> n >> m >> k;

    forn(i,n) forn(j,min(n,k)+1)
        vals[i][j] = binExp(nCr(n,j),((m-i+n-1)/n)); // ceil((m-i)/n) (psstt... el exponente no se puede hacer %MOD :P)
    forn(j,min(n,k)+1) dp[0][j] = vals[0][j];

    forsn(i,1,n) forn(j,k+1) forn(l,min((int)n,j)+1) // estando en este casillero, si hay j puntos puestos hasta acá, si puse en este paso k puntos
        dp[i][j] = (dp[i][j] + ((vals[i][l]*(ll)dp[i-1][j-l])%MOD))%MOD;

    cout << dp[n-1][k];

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
