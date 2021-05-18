#include <stdio.h>
#include <algorithm>
 
#pragma GCC optimize("O3")
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
 
using namespace std;
 
const int MAXN = 1002;
const int INF = 1e9+5;
 
int dp[MAXN][MAXN];
int ansR[MAXN], ansL[MAXN];
 
int main() {
    //FAST_IO;
 
    int n,m; scanf("%d %d",&n,&m);
 
    getchar();
    forn(i,n) {forn(j,m) dp[i][j+1] = getchar(); getchar();}
    forn(i,n) dp[i][0] = dp[i][m+1] = -INF; // dummys
 
    dforn(i,n) forsn(j,1,m+1) dp[i][j] = (dp[i][j] == '.' ? dp[i+1][j]+1 : 0);
 
    int maxi = 0, ind;
    dforn (i,n) {
        dforsn (j,1,m+1) {for(ind = j+1; dp[i][ind] >= dp[i][j]; ind = ansR[ind]); ansR[j] = ind;}
        forsn(j,1,m+1) {for(ind = j-1; dp[i][ind] >= dp[i][j]; ind = ansL[ind]); ansL[j] = ind;}
        forsn(j,1,m+1) maxi = max(maxi,(ansR[j]-ansL[j]-1)*dp[i][j]);
    }
 
    printf("%d",maxi);
 
    return 0;
}
 
/// ESCRIB� en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO B�SICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!