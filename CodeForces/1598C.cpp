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

const int MAXN = 2e5+5;

int arr[MAXN];

int main() {
    int t; scanf("%d",&t);

    forn(_,t) {
        int n; scanf("%d",&n);

        ll sum = 0;
        map<ll, int> nums;
        forn(i,n) {
            int x; scanf("%d",&x);
            sum += x;
            nums[x]++;
            arr[i] = x;
        }

        if (((sum%n) * (ll)(n-2))%n) {
            puts("0");
            continue;
        }
        
        ll rta = 0;
        forn(i,n) {
            ll tg = sum - arr[i] - (sum / (ld)n) * (n-2);

            nums[arr[i]]--;
            if (!nums[arr[i]]) nums.erase(arr[i]);

            rta += nums[tg];
        }

        printf("%lld\n",rta);
    }

    return 0;
}
