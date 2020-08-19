#include <bits/stdc++.h>

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
const ll INF = 9e18;

ll T[MAXN][MAXN], dp[MAXN][MAXN];

int main() {
    int t; scanf("%d",&t);

    forn (i,t) {
        int n,m; scanf("%d %d",&n,&m);
        forn (j,n) forn (k,m) scanf("%lld",&T[j][k]);

        // I don't have fixed start so...
        // Given that I have profit when I don't make any operations on at least one cell
        // I'll suppose it's on my path to calculate the starting height
        // Once the start is fixed, I can run another DP to look up my possibilities
        // Also notice that even if my second DP doesn't include the fixed cell in my path
        // it'll not be optimal, and so later discarded.

        ll valF = T[0][0]; ll rta = INF;
        forn (o,n) forn (p,m) {
            ll actSt =  T[o][p] - o - p; // trying height considering {o,p} as unchanged
            if (actSt > valF) continue;
            T[0][0] = actSt;

            //reset
            forn (j,n) forn (k,m) dp[j][k] = INF;
            dp[0][0] = valF-actSt;

            forn (y,n) forn (x,m) {
                if (T[y][x+1] >= (T[0][0] + (x+1) + y))
                    dp[y][x+1] = min(dp[y][x+1], dp[y][x] + (T[y][x+1] - (T[0][0] + (x+1) + y)) );

                if (T[y+1][x] >= (T[0][0] + x + (y+1)))
                    dp[y+1][x] = min(dp[y+1][x], dp[y][x] + (T[y+1][x] - (T[0][0] + x + (y+1))) );
            }

            //forn (u,n) {forn (q,m) cout << dp[u][q] << ' '; cout << endl;}

            //cerr << dp[n-1][m-1] + valF-actSt << endl;
            rta = min(rta,dp[n-1][m-1]);
        }

        printf("%lld\n",rta);
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!