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
typedef unsigned long long ull;
typedef pair<int,int> ii;

const int MAXN = 4e5+5;
const int MAXL = 900;
const int MOD = 1e9+7;

int dp[2][MAXN]; // considerando que usé en este punto, una cantidad de bloques rojos -> sé la cantidad de verdes por lo que ya pasé
int sums[MAXL];

int main() {
    FAST_IO;

    sums[0] = 1;
    forsn(i,1,MAXL) sums[i] = (sums[i-1] + i + 1);

    int r,g; cin >> r >> g;
    
    if (g > 0) dp[0][0] = 1;
    if (r > 0) dp[0][1] = 1;

    int h = upper_bound(sums,sums+MAXL,r+g)-sums-1; // índice máx de niveles (+1 es el posta)

    forsn(i,1,h+1) {
        forn(j,MAXN) dp[i&1][j] = 0; // reset
        forn(j,r+1) { // habiendo usado en este paso, j bloques rojos
            if (j-i-1 >= 0) dp[i&1][j] = (dp[i&1][j] + dp[1^(i&1)][j-i-1])%MOD; // pongo rojos
            if (g-sums[i]+j >= 0) dp[i&1][j] = (dp[i&1][j] + dp[1^(i&1)][j])%MOD; // pongo verdes
        }
    }

    int tot = 0;
    forn(i,r+1) tot = (tot + dp[h&1][i])%MOD;

    cout << tot;

    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!