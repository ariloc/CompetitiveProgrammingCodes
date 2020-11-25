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

const int MAXN = 401;
const int INF = 2e9;

int city[MAXN],dp[MAXN][MAXN][MAXN]; // r_i,l,r

int main() {
    forn(i,MAXN) forn(j,MAXN) forn(k,MAXN) dp[i][j][k] = INF;
    int n,m; scanf("%d %d",&n,&m);
    forn(i,n) scanf("%d",&city[i]);
    forn(i,n) forsn(j,i,n) dp[0][i][j] = city[j]-city[i];
    forsn(k,1,n+1) forn(i,n) {
        int ind = i;
        forsn(j,i,n) {
            dp[k][i][j] = max(dp[k-1][i][ind],city[j]-city[ind]);
            while (ind+1 <= j && max(dp[k-1][i][ind+1],city[j]-city[ind+1]) < dp[k][i][j])
                {ind++; dp[k][i][j] = min(dp[k][i][j],max(dp[k-1][i][ind],city[j]-city[ind]));}
        }
    }
    ll rta = 0;
    forn(i,m) {
        int s,f,c,r; scanf("%d %d %d %d",&s,&f,&c,&r); s--; f--;
        int val = dp[r][s][f];
        rta = max(rta,(ll)val*c);
    }

    printf("%lld",rta);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
