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

/*ll calc (ll &mid, ll &c, ll &m, ll &x, ll &sinQueja) {
    return mid*c + (m-(sinQueja*(mid-1)))*x;
}*/

int main() {
    FAST_IO;

    ll n,m; cin >> n >> m;

    ll tot = 0;
    forn (i,n) {
        ll t,T,x,c; cin >> t >> T >> x >> c;

        if (t+m <= T) tot += c;
        else if (t >= T) tot += c+x*m;
        else {
            ll maxAdmit = T-t;
            tot += min({((m+maxAdmit-1)/maxAdmit)*c});
        }

        //cerr << tot << endl;
    }

    cout << tot;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!