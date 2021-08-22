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

const int MAXN = 1e5+5;

int dp[MAXN][2];

int main() {
    FAST_IO;

    string s; cin >> s;

    forn(i,s.size()-1) {
        if (s[i] == 'A' && s[i+1] == 'B') dp[i][0]++;
        if (s[i] == 'B' && s[i+1] == 'A') dp[i][1]++;
    }

    dforn(i,MAXN-1) dp[i][0] += dp[i+1][0], dp[i][1] += dp[i+1][1];

    bool posib = 0;
    forn(i,s.size()) {
        if (s[i] == 'A' && s[i+1] == 'B' && dp[i+2][1]) posib = 1;
        if (s[i] == 'B' && s[i+1] == 'A' && dp[i+2][0]) posib = 1;
    }

    cout << (posib ? "YES" : "NO");

    return 0;
}