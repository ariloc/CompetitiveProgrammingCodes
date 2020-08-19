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

const int MAXN = 1005;
const int MOD = 1e9+7;

ll arr[MAXN];

ll binexp (ll a, ll k) {
    ll r = 1;
    while (k) {
        if (k & 1) r = (r*a)%MOD;
        a = (a*a)%MOD; k >>= 1;
    }
    return r;
}

ll fact(ll x) {
    ll r = 1;
    forsn (i,1,x+1) r = (r*i)%MOD;
    return r;
}

int main() {
    FAST_IO;

    ll rta = 1;
    int n; cin >> n;
    forn (i,n) cin >> arr[i];

    ll sum = arr[0];
    forsn (i,1,n) {
        sum += arr[i];
        rta = ((rta * (((fact(sum-1) % MOD) * binexp( (fact(arr[i]-1) * fact((sum-1)-(arr[i]-1))) % MOD , MOD-2)) % MOD)) + MOD) % MOD;
    }

    cout << rta;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!