#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MOD = 998244353;
int const MAXN = 2e5+5;

int dp[MAXN][4];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;

        string s; cin >> s;

        forn(i,n+1) forn(j,4) dp[i][j] = 0;

        string st = s.substr(0,2);
        if (st == "00" || st == "0?" || st == "?0" || st == "??") dp[1][0] = 1;
        if (st == "01" || st == "0?" || st == "?1" || st == "??") dp[1][1] = 1;
        if (st == "10" || st == "1?" || st == "?0" || st == "??") dp[1][2] = 1;
        if (st == "11" || st == "1?" || st == "?1" || st == "??") dp[1][3] = 1;

        forsn(i,2,sz(s)) {
            if (s[i] == '0' || s[i] == '?') {
                dp[i][0] = (dp[i][0] + dp[i-1][2])%MOD;
                dp[i][2] = (dp[i][2] + dp[i-1][3])%MOD;
            }
            if (s[i] == '1' || s[i] == '?') {
                dp[i][1] = (dp[i][1] + dp[i-1][0])%MOD;
                dp[i][3] = (dp[i][3] + dp[i-1][1])%MOD;
            }
        }

        int r = 0;
        forn(j,4) r = (r + dp[n-1][j])%MOD;

        cout << r << '\n';
    }

    return 0;
}
