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

int const MAXN = 2e5+5;

ll dp[MAXN];

int main() {
    int n; scanf("%d",&n);
    forn(i,n) scanf("%lld",&dp[n-i]);

    forsn(i,1,n+1) dp[i] += dp[i-1];

    int q; scanf("%d",&q);
    forn(_,q) {
        int typ; scanf("%d",&typ);
        if (typ == 1) {
            int l,r; scanf("%d %d",&l,&r);
            printf("%lld\n",dp[n-l+1]-dp[n-r]);
        }
        else {
            int x; scanf("%d",&x);
            ++n;
            dp[n] = dp[n-1] + x;
        }
    }
        
    return 0;
}
