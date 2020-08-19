#include <iostream>
#include <vector>
#include <math.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
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
typedef long double lld;
typedef pair<int,int> ii;

const int MOD = 1000000007;

ll expmod (ll a, ll k) {
    if (!k) return 1;
    ll result = expmod(a, k/2);
    if (!(k%2)) return (result * result) % MOD;
    return (a * ((result * result) % MOD));
}

ll factorial (ll n) {
    ll r = n;
    while (n--) {if (!n) break; r*=n; r%=MOD;}
    return r;
}

ll combinatoria (ll m, ll n) {
    return factorial(m+n-1) * expmod((factorial(m) * factorial(n-1)) % MOD, MOD-2) % MOD;
}

int main() {
    FAST_IO;

    ll n,m,result;
    cin >> n >> m;
    result = combinatoria(2*m,n);
    cout << (!result ? 1 : result);

    return 0;
}