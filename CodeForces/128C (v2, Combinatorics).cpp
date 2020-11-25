#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MOD = 1e9+7;

ll expmod (ll n, ll k) {
    ll r = 1;
    while (k) {
        if (k & 1) r = (r*n)%MOD;
        n = (n*n)%MOD; k >>= 1;
    }
    return r;
}

ll fact (ll a) {
    ll r = 1;
    forsn (i,1,a+1) {r*=i; r %= MOD;}
    return r;
}

ll comb(ll n, ll p) {
    if (p > n) return 0;
    return (fact(n) * expmod( (fact(p) * fact((n-p+MOD) % MOD)) % MOD, MOD-2)) % MOD;
}

int main() {
    FAST_IO;

    ll n,m,k; cin >> n >> m >> k;

    ll a = (comb(n-2,2*k) + comb(n-2,2*k-1)) % MOD;
    ll b = (comb(m-2,2*k) + comb(m-2,2*k-1)) % MOD;
    //cerr << a << ' ' << b << endl;
    cout << ((a*b)+MOD)%MOD;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
