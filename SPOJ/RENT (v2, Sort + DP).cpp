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

const int MAXN = 2e6+5;

struct order {
    int s,d,p;

    bool operator< (const order &o) const {
        return s < o.s;
    }
};

ll dp[MAXN];

int main() {
    int t; scanf("%d",&t);
    forn(_,t) {
        int n; scanf("%d",&n);
        forn(i,MAXN) dp[i] = 0;

        vector<order> orders;
        forn(i,n) {
            int s,d,p; scanf("%d %d %d",&s,&d,&p);
            orders.pb({s,d,p});
        }

        sort(all(orders));

        int ind = 0;
        forn(i,MAXN-2) {
            while (ind < n && orders[ind].s == i) {
                order j = orders[ind];
                dp[i+j.d] = max(dp[i+j.d],dp[i]+j.p);
                ++ind;
            }
            dp[i+1] = max(dp[i+1], dp[i]);
        }

        printf("%lld\n",dp[MAXN-3]);
    }
    
    return 0;
}
