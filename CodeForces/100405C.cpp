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
typedef long double ld;

const int MAXN = 2005;

ld dp[MAXN];
int vals[MAXN];

int main() {
    FAST_IO;

    int n,m;
    while (cin >> n >> m) {
        int pos = m-1, last = m-1;
        
        forn(i,n*11+20) vals[i] = -1;

        forn(i,n) {
            string s; cin >> s;
            if (s == "J" || s == "K" || s == "Q" || (int)s.size() > 1)
                vals[pos] = 10;
            else if (s == "A")
                vals[pos] = 11;
            else vals[pos] = s[0]-'0';
            
            last = pos;
            pos += vals[pos];
        }

        forn(i,last+1) dp[i] = 0;
        forn(i,10) dp[i] = 0.1;

        forn(i,last) {
            if (vals[i] == -1) {
                forsn(j,2,12) dp[i+j] += dp[i]/13;
                dp[i+10] += (dp[i]/13)*3;
            }
            else dp[i+vals[i]] += dp[i];
        }

        cout << fixed << setprecision(10) << dp[last] << '\n';
    }
    
    return 0;
}