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

const int MAXN = 105;
const int INF = 1e5+5;

ii glass[MAXN];
int dp[2][MAXN][MAXN*MAXN]; // para todo k, en el rango [0,i], con una capacidad de v
double rta[MAXN];

int main() {
    forn(i,2) forn(j,MAXN) forn(k,MAXN*MAXN) dp[i][j][k] = -INF;
    int n; scanf("%d",&n);

    forn(i,n) scanf("%d %d",&glass[i].fst,&glass[i].snd);

    int sum = 0; forn(i,n) sum += glass[i].snd;

    forn(i,n) dp[0][i][glass[i].fst] = glass[i].snd;
    forsn(i,1,n) forn(v,MAXN*MAXN) dp[0][i][v] = max(dp[0][i-1][v],dp[0][i][v]);
    forn(i,n) rta[0] = max(rta[0],dp[0][i][glass[i].fst] + min((double)(sum-dp[0][i][glass[i].fst])/2, (double)glass[i].fst-dp[0][i][glass[i].fst]));
    forsn(k,1,n) forsn(i,k,n) forn(v,MAXN*MAXN) {
        dp[k&1][i][v] = max(dp[k&1][i-1][v],(glass[i].fst <= v ? dp[!(k&1)][i-1][v-glass[i].fst] : 0) + glass[i].snd);
        if (i == n-1) rta[k] = max(rta[k],dp[k&1][i][v] + min((double)(sum-dp[k&1][i][v])/2, (double)v-dp[k&1][i][v]));
    }

    forn(k,n) printf("%.9f ",rta[k]);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
