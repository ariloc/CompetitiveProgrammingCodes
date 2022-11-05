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

int main() {
    int t; scanf("%d",&t);

    forn(_,t) {
        int n; scanf("%d",&n);

        vi nums, lookup;
        forn(i,n) {
            int x; scanf("%d",&x);
            if (x < i+1) nums.pb(i+1), lookup.pb(x);
        }

        sort(all(lookup));

        ll rta = 0;
        for (auto &i : nums) {
            int ind = upper_bound(all(lookup), i)-lookup.begin();
            rta += (int)lookup.size()-ind;
        }

        printf("%lld\n",rta);
    }

    return 0;
}
