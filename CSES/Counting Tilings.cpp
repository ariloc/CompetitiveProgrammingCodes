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
const int MAXM = 1002;
const int MAXN = 10;

int dp[MAXM][1<<MAXN],n,m;

void pass (int row, int bit, int mk, int nxt_mk) {
    if (bit >= n) {
        int aux = (dp[row+1][nxt_mk]+dp[row][mk]);
        if (aux >= MOD) aux -= MOD;
        dp[row+1][nxt_mk] = aux;
        return;
    }
    if (mk&(1<<bit)) pass(row,bit+1,mk,nxt_mk);
    else {
        pass(row,bit+1,mk,nxt_mk|(1<<bit));
        if (bit+1 < n && !(mk&(1<<(bit+1)))) pass(row,bit+2,mk,nxt_mk);
    }
}

int main() {
    scanf("%d %d",&n,&m);

    dp[0][0] = 1;
    forn(i,m) forn(j,(1<<n)) pass(i,0,j,0);

    printf("%d",dp[m][0]);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
