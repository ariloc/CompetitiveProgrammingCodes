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

const int MAXN = 2e5+5;

int arr[MAXN], h[MAXN], a[MAXN];
ll dp[MAXN];
set<int> vals;

int main() {
    int n; scanf("%d", &n);
    forn(i,n) scanf("%d", &h[i]);
    forn(i,n) scanf("%d", &a[i]);

    forn(i,n) dp[i] = -1;

    forn(i,n) {
        auto it = vals.lower_bound(h[i]);
        ll acc = a[i];
        if (it != vals.begin()) acc += dp[*prev(it)];
        
        dp[h[i]] = max(dp[h[i]], acc);
        vals.insert(h[i]);
        if (*it == h[i]) it++;

        while (it != vals.end() && dp[*it] < dp[h[i]]) {
            it++;
            dp[*prev(it)] = -1, vals.erase(prev(it));
        }
    }

    printf("%lld", dp[*vals.rbegin()]);
          
    return 0;
}

