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

const int MAXN = 1005;
const int MAXK = 2005;

int dp[MAXN][MAXK];

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;
    string s; cin >> s;

    forn(i,MAXN) forn(j,MAXK) dp[i][j] = -1;
    dp[0][k] = 0;

    forn(i,n) forsn(j,1,2*k) {
        if (dp[i][j] != -1) {
            if (s[i] == '?' || s[i] == 'D') dp[i+1][j] = j;
            if ((s[i] == '?' || s[i] == 'W') && j+1 <= 2*k) dp[i+1][j+1] = j;
            if ((s[i] == '?' || s[i] == 'L') && j-1 >= 0) dp[i+1][j-1] = j;
        }
    }

    if (dp[n][0] == -1 && dp[n][2*k] == -1) cout << "NO\n";
    else {
        string path;
        for (int i = n, ind = (dp[n][0] != -1 ? 0 : 2*k); i > 0; ind = dp[i][ind], --i) {
            if (dp[i][ind] == ind-1) path.pb('W');
            else if (dp[i][ind] == ind) path.pb('D');
            else path.pb('L');
        }

        reverse(all(path));

        cout << path;
    }

    return 0;
}