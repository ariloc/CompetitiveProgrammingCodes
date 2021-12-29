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
const ll INF = 9e18;

void divide (vi arr, vector<ll> &sums) {
    if (arr.empty()) return;
    ll maxi = -INF, mini = INF, s = 0;
    for (auto &i : arr)
        maxi = max(maxi,(ll)i), mini = min(mini,(ll)i), s += i;
    sums.pb(s);

    vi l_arr, r_arr;
    ll mid = (maxi+mini)/2;
    for (auto &i : arr)
        if (i <= mid) l_arr.pb(i);
        else r_arr.pb(i);

    if (!l_arr.empty() && !r_arr.empty()) {
        divide(l_arr, sums);
        divide(r_arr, sums);
    }
}

int main() {
    int t; scanf("%d",&t);
    forn(o,t) {
        int n,q; scanf("%d %d",&n,&q);

        vi arr;
        vector<ll> sums;
        forn(i,n) {int x; scanf("%d",&x); arr.pb(x);}
        divide(arr,sums);

        sort(all(sums));
        
        forn(i,q) {
            ll s; scanf("%lld",&s);
            auto ind = lower_bound(all(sums),s) - sums.begin();
            if (ind >= 0 && ind < (int)sums.size() && sums[ind] == s)
                printf("Yes\n");
            else printf("No\n");
        }
    }

    return 0;
}