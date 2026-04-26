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

int const MOD = 1e9+7;
int const MAXD = 105;
int const MAXK = 10005;

int dp[MAXK][MAXD][2];

int main() {
    FAST_IO;

    string s; cin >> s;
    int d; cin >> d;

    int n = (int)s.size();
    dp[0][0][0] = 1;
    forsn(i,1,n+1) {
        int dig = s[i-1]-'0';
        forn(j,d) {
            forn(k,10) {
                dp[i][(j+k)%d][1] = (dp[i][(j+k)%d][1] + dp[i-1][j][1])%MOD;

                if (k < dig)
                    dp[i][(j+k)%d][1] = (dp[i][(j+k)%d][1] + dp[i-1][j][0])%MOD;
                
                if (k == dig)
                    dp[i][(j+k)%d][0] = (dp[i][(j+k)%d][0] + dp[i-1][j][0])%MOD;
            }
        }
    }

    cout << ((dp[n][0][0] + dp[n][0][1])%MOD - 1 + MOD)%MOD << '\n';

    return 0;
}
