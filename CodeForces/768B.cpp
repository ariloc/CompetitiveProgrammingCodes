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

int solve (ll n, ll act, ll pot, ll l, ll r) {
    int ret = 0;
    if (act >= l && act <= r) ret += (n % 2);
    
    if (n <= 1) return ret;

    if (l < act) ret += solve(n >> 1, act - (pot+1)/2, pot >> 1, l, r);
    if (r > act) ret += solve(n >> 1, act + (pot+1)/2, pot >> 1, l, r);
    return ret;
}

int main() {
    ll n,l,r; scanf("%lld %lld %lld",&n,&l,&r); r--, l--;

    ll cnt = 1, active = 1, aux = n;
    while (aux > 1) {
        active *= 2LL;
        cnt += active;
        aux >>= 1;
    }

    printf("%d",solve(n, cnt >> 1, cnt >> 1, l, r));

    return 0;
}