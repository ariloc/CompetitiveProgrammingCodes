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

const int MAXN = 2e5+5;
const int MAXST = (1<<(32-__builtin_clz(MAXN)));

struct mon {
    ll v;
    mon(){v = 0;}
    mon(ll v) : v(v){}

    mon operator+ (const mon &o) const {
        return mon(__gcd(v,o.v));
    }
};

mon ST[2*MAXST];
ll arr[MAXN];
int N;

ll query (int l, int r) {
    mon ret;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l&1) ret = (ret + ST[l++]);
        if (r&1) ret = (ret + ST[--r]);
    }
    return ret.v;
}

int main() {
    int t; scanf("%d",&t);
    forn(o,t) {
        int n; scanf("%d",&n);
        
        N = (1<<(32-__builtin_clz(n)));
        
        forn(i,n) scanf("%lld",&arr[i]);

        forn(i,n-1) arr[i] = abs(arr[i+1] - arr[i]);
        n--;

        forn(i,n) ST[i+N].v = arr[i];
        dforsn(i,1,N) ST[i] = ST[2*i] + ST[2*i+1];

        int r = 0, maxi = 1;
        forn(l,n) {
            while (r < n && query(l,r+1) != 1) r++;
            if (query(l,r) != 1) maxi = max(maxi,r-l+1);
        }

        printf("%d\n",maxi);
    }

    return 0;
}