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

int const MAXN = 405;

int dp[3][MAXN][MAXN][2];

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;

    dp[0][1][0][0] = 1;
    forsn(i,1,n) {
        forn(j,n+1) forn(k,j) dp[i%3][j][k][0] = dp[i%3][j][k][1] = 0;
        forsn(j,2,n+1) {
            int acc = 0;
            forn(k,j) {
                dp[i%3][j][k][1] = acc;
                acc = (acc + (dp[(i-1)%3][j-1][k][0] + dp[(i-1)%3][j-1][k][1])%m)%m;
            }
            acc = 0;
            dforn(k,j) {
                acc = (acc + (dp[(i-1)%3][j-1][k][0])%m)%m;
                dp[i%3][j][k][0] = acc;
            }
            if (i > 1) {
                int acc2 = 0;
                forn(k,j-1)
                    acc2 = (acc2 + (dp[(i-2)%3][j-1][k][0] + dp[(i-2)%3][j-1][k][1])%m)%m;
                forn(k,j)
                    dp[i%3][j][k][0] = (dp[i%3][j][k][0] + acc2)%m;
            }
        }
    }

    int r = 0;
    int lst = (n-1)%3;
    forsn(j,2,n+1) forn(k,j) r = (r + (dp[lst][j][k][0] + dp[lst][j][k][1])%m)%m;

    cout << r << '\n';

    return 0;
}
