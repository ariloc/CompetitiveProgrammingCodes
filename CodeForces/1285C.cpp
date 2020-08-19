#include <bits/stdc++.h>

#define forn(i,n) for(ll i = 0; i < ll(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const ll INF = 10e9+2;

int main() {
    FAST_IO;

    ll n,r;
    cin >> n;

    for (ll i = 1; i*i <= n; i++) {
        ll div = n/i;
        if (!(n%i) and ((i*div)/__gcd(i,div)) == n)
            r = i;
    }
    cout << r << ' ' << n/r;

    return 0;
}