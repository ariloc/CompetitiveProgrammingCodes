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

int const MAXN = 1e6+5;

int dp[MAXN];

int main() {
    FAST_IO;

    int k; cin >> k;
    string s; cin >> s;
    int n = (int)s.size();

    forn(i,n) dp[i+1] = dp[i] + (s[i] == '1');

    ll cnt = 0;
    forn(i,n) {
        int tg = dp[i]+k;
        int l = lower_bound(dp+i+1,dp+n+1,tg)-dp;
        int r = upper_bound(dp+i+1,dp+n+1,tg)-dp;
        cnt += r-l;
    }

    cout << cnt;
  
    return 0;
}
