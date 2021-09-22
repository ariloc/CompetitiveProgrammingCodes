#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define fst first
#define snd second

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

vector<ll> r;

ll binSrch(ll &k, ll &n, ll &a, ll &b) {
    ll high = n;
    ll low = -1;

    while (high-low > 1) {
        ll mid = (high+low)/2; // num vueltas solo jugar
        ll aux = n-mid;
        if ((k - ( mid*a + (aux < 0 ? 0 : aux) * b )) > 0) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    if ((k - ( high*a + (n-high < 0 ? 0 : n-high) * b )) > 0) return high;
    else if ((k - ( low*a + (n-low < 0 ? 0 : n-low) * b )) > 0) return low;
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;

    forn(i,N) {
        ll k,n,a,b;
        cin >> k >> n >> a >> b;
        r.push_back(binSrch(k,n,a,b));
    }

    for (auto &i : r)
        cout << i << '\n';

    return 0;
}