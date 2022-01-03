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

const int MAXN = 2e5+5;
const int MAXB = 30;
const int INF = 2e9;

int dp[MAXB][MAXN];

int main() {
    forn(i,MAXB) {
        forsn(j,1,MAXN) dp[i][j] = dp[i][j-1] + ((j & (1<<i)) > 0);
    }

    int t; scanf("%d",&t);
    forn(o,t) {
        int l,r; scanf("%d %d",&l,&r);
        int aux = r, cnt = 0, rta = INF;
        while (aux)
            rta = min(rta, (r-l+1) - dp[cnt][r] + dp[cnt][l-1]), cnt++, aux >>= 1;
        
        printf("%d\n",rta);
    }

    return 0;
}