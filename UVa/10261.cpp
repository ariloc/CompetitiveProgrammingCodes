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
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

int const MAXC = 205;
int const MAXL = 10005;
int const INF = 2e9;

int dp[MAXC][MAXL], P[MAXC][MAXL], sums[MAXC];
vi cars;

int main() {
    int t; scanf("%d",&t);
    forn(o,t) {
        cars.clear();

        int len; scanf("%d",&len);
        len *= 100;

        int x = -1;
        do {
            scanf("%d",&x);
            cars.pb(x);
        } while (x);
        cars.pop_back();

        if (cars.empty() || cars[0] > len) {puts("0"); if(o != t-1) puts(""); continue;}

        sums[0] = cars[0];
        forsn(i,1,min(MAXC,(int)cars.size()))
            sums[i] = sums[i-1] + cars[i];

        forn(i,min(MAXC,(int)cars.size()+2)) forn(j,len+2)
            dp[i][j] = -INF, P[i][j] = -1;

        dp[0][0] = 1, dp[0][cars[0]] = 1, P[0][0] = 0;
        forsn(i,1,min(MAXC,(int)cars.size())) forn(j,len+1) {
            if (j >= cars[i] && dp[i-1][j-cars[i]] != -INF)
                dp[i][j] = dp[i-1][j-cars[i]]+1, P[i][j] = j-cars[i];
            if (sums[i]-j <= len && dp[i-1][j]+1 > dp[i][j])
                dp[i][j] = dp[i-1][j]+1, P[i][j] = j;
        }

        int maxi = 0; ii nd = {-1,-1};
        forn(i,min(MAXC,(int)cars.size())) forn(j,len+1)
            if (dp[i][j] > maxi) maxi = dp[i][j], nd = {i,j};

        printf("%d\n",maxi);
        vi rta;
        while (nd.fst >= 0) {
            if (P[nd.fst][nd.snd] != nd.snd) rta.pb(1);
            else rta.pb(0);
            nd.snd = P[nd.fst][nd.snd], nd.fst--;
        }
        reverse(all(rta));

        for (auto &i : rta) 
            if (i) printf("port\n");
            else printf("starboard\n");

        if (o != t-1) puts("");
    }
          
    return 0;
}
