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

const int MAXN = 1e9;

ll calc (ll x) {
    return ((x*(x+1))/2);
}

int main() {
    FAST_IO;

    ll n,k; cin >> n >> k;
    if (n == 1) {cout << 0; return 0;}

    ll tot = ((k*(k-1))/2)+1;
    if (k >= n) cout << 1;
    else if (tot < n) cout << -1;
    else {

        ll low = 0;
        ll high = k-1;
        while (high-low > 1) {
            ll mid = (low+high)/2;
            if ((tot - calc(mid)) >= n) low = mid;
            else high = mid;
        }

        ll val = 0;
        if ((tot - calc(high)) >= n) val = high; else val = low;
        //cerr << val << ' ' << calc(val) << ' ' << low << ' ' << high << ' ' << tot << ' ' << n << endl;
        cout << (k-1)-val;

    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!