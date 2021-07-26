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
const int MAXM = 10005;

int cnt[MAXN];
int val[MAXN][MAXN];

int dpAux[MAXN][MAXN]; // por estante
int dp[MAXN][MAXN]; // máximo costo sacando del i-ésimo estante, j elementos
int dp2[MAXN][MAXM];

int main() {
    int n,m; scanf("%d %d",&n,&m);

    forn(i,n) {
        int x; scanf("%d",&x);
        forn(j,x) scanf("%d",&val[i][j+1]); // desfase 1
        cnt[i] = x;
    }

    // maxima cantidad sacando cierta cantidad de elementos de un estante ---> OK (?)
    forn(k,n) {
        forn(i,MAXN) forn(j,MAXN) dpAux[i][j] = 0; // reset, importante !!!

        int myN = cnt[k];
        forsn(i,1,myN+1) dforsn(j,1,myN+1)
            dpAux[i][j] = max(dpAux[i-1][j] + val[k][i-1], dpAux[i][j+1] + val[k][j+1]);
        
        // Caso 0 elementos -> 0 desde inicialización
        forsn(i,1,myN+1) forsn(j,i,myN+1) {
            int cntElem = myN-(j-i+1); // elementos que saqué
            dp[k][cntElem] = max(dp[k][cntElem],dpAux[i][j]);
        }
        dp[k][myN] = dpAux[1][1] + val[k][1]; // Caso N (todos): es el total, entonces no varía
    }

    // para los i, inicializado en 0 default
    forn(i,n) forn(j,cnt[i]+1) forn(k,m+1)  // sacando del i-ésimo estante, si saco j elementos de este estante, quedándome k berrinches
        if (k-j >= 0)
            dp2[i+1][k-j] = max( dp2[i+1][k-j], dp2[i][k] + dp[i][j] );

    printf("%d",dp2[n][0]);

    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!