#include<bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 2005;
ll const INF = 9e18;

ll dp[MAXN][3*MAXN][3];
int b[MAXN][3];
ll rta[3*MAXN];

void vueltas(vector<int> &b0, vector<int> &b1, vector<int> &b2, vector<int> &retL, vector<long long> &retB) {
    int n = (int)b0.size();
    forn(i,n) b[i][0] = b0[i];
    forn(i,n) b[i][1] = b1[i];
    forn(i,n) b[i][2] = b2[i];

    forn(i,MAXN) forn(j,3*MAXN) forn(k,3) dp[i][j][k] = -INF;
    forn(i,3*MAXN) rta[i] = -1;
    if (b[0][0] >= 0 && b[0][1] >= 0) {
        dp[0][2][0] = b[0][0] + b[0][1];
        if (b[0][2] >= 0)
            dp[0][3][1] = b[0][0] + b[0][1] + (ll)b[0][2];
    }


    forsn(i,1,n) forsn(j,2,3*n+1) {
        if (b[i][0] >= 0 && b[i][1] >= 0) {
            dp[i][j][0] = max(dp[i][j][0], dp[i-1][j-2][0]+b[i][0]+b[i][1]);
            if (b[i][2] >= 0 && j >= 3) 
                dp[i][j][0] = max(dp[i][j][0], dp[i-1][j-3][1]+b[i][0]+b[i][1]+b[i][2]);
        }

        if (b[i][0] >= 0 && b[i][2] >= 0) {
            dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-2][1]+b[i][0]+b[i][2]);
            if (b[i][1] >= 0 && j >= 3) {
                dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-3][0]+b[i][0]+b[i][1]+b[i][2]);
                dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-3][2]+b[i][0]+b[i][1]+b[i][2]);
            }
        }

        if (b[i][1] >= 0 && b[i][2] >= 0) {
            dp[i][j][2] = max(dp[i][j][2], dp[i-1][j-2][2]+b[i][1]+b[i][2]);
            if (b[i][0] >= 0 && j >= 3)
                dp[i][j][2] = max(dp[i][j][2], dp[i-1][j-3][1]+b[i][0]+b[i][1]+b[i][2]);
        }
        
        rta[j] = max(rta[j],max(dp[i][j][0],dp[i][j][2]));
    }

    vi r1;
    vector<ll> r2;
    forsn(i,4,3*n+1)
        if (rta[i] >= 0)
            r1.pb(i), r2.pb(rta[i]);
    retL = r1;
    retB = r2;
}
