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

const int MAXN = 105;

bool traps[2][MAXN], dp[2][MAXN];

int main() {
    FAST_IO;
    
    int t; cin >> t;
    forn(o,t) {
        int n; cin >> n;
        forn(k,2) {
            string s; cin >> s;
            forn(i,s.size()) traps[k][i] = (s[i]-'0');
        }
        forn(k,2) forn(i,n) dp[k][i] = 0;
        dp[0][0] = 1;

        forn(i,n) forn(k,2) forn(l,2) 
            if (!traps[l][i+1] && dp[k][i]) dp[l][i+1] = 1;
        
        printf("%s\n",dp[1][n-1] ? "YES" : "NO");
    }

    return 0;
}