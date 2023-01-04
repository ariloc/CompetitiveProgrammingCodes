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

const int MAXN = 5e5+5;
const ll INF = 9e18;
const int MAXST = (1<<(32-__builtin_clz(MAXN)));

struct mon {
    ll maxi; int ind;

    mon(){maxi = -INF, ind = -1;}
    mon(ll a, int b) : maxi(a), ind(b) {}

    mon operator+ (const mon &o) const {
        if (maxi > o.maxi) return *this;
        if (maxi < o.maxi) return o;
        return mon(maxi, o.ind);
    }
};

int N;
mon ST[2*MAXST];
ll arr[MAXN], arr2[MAXN], dp[MAXN];

mon query (int l, int r) {
    mon ret = mon();
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l&1) ret = ret + ST[l++];
        if (r&1) ret = ret + ST[--r];
    }
    return ret;
}


ll solve (int l, int r) {
    if (r-l == 1) return min(arr2[l],arr2[r]);

    int mid = query(l+1,r).ind;
    ll mini = min(arr2[l],arr2[r]);
    ll sum = dp[r-1]-dp[l];
    ll r1 = solve(l,mid), r2 = solve(mid,r);

    return max(min(r1,r2), mini - sum);
}

int main() {
    int n; scanf("%d",&n);
    forn(i,n) scanf("%lld",&arr[i]);

    ll maxi = -1; int ind = -1;
    forn(i,n) {
        if (arr[i] > maxi) maxi = arr[i], ind = i;
    }

    ll sum = 0;
    forn(i,n) arr2[i] = arr[(i+ind)%n], sum += arr[i];
    arr2[n] = maxi;

    dp[0] = arr2[0];
    forsn(i,1,n+1) dp[i] = dp[i-1] + arr2[i];

    N = (1<<(32-__builtin_clz(n+1)));
    forn(i,n+1) ST[i+N] = mon(arr2[i],i);
    dforsn(i,1,N) ST[i] = ST[2*i] + ST[2*i+1];

    printf("%lld",solve(0,n));

    return 0;
}


