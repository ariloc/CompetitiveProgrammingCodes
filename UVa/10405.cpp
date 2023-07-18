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

int const MAXN = 1005;

int dp[MAXN][MAXN];
string a,b;

int main() {
    FAST_IO;

    while (getline(cin,a) && getline(cin,b)) {
        int n = (int)a.size(), m = (int)b.size();
        forn(i,n+1) forn(j,m+1) dp[i][j] = 0;
        forsn(i,1,n+1) forsn(j,1,m+1) {
            dp[i][j] = max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1] + (a[i-1] == b[j-1])));
        }
        cout << dp[n][m] << '\n';
    }
   
    return 0;
}
