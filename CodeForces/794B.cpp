#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef long double ld;
typedef vector<int> vi;

int main() {
    FAST_IO;

    int n,h; cin >> n >> h;

    ld area = h/(ld)2;
    ld split = area/n;

    ld phi = h*2;

    vector<ld> rta;
    ld acc = 0;
    ld oldside = 0;
    forn(i,n-1) {
        ld lo = oldside, hi = 1;
        forn(_,1000) {
            ld mid = (hi+lo)/2;
            ld newh = phi * mid / 2;
            if ((mid*newh/2 - acc) - split > 0) hi = mid;
            else lo = mid;
        }
        oldside = lo;
        rta.pb(phi*lo/2);
        acc = lo*(phi * lo / 2)/2;
    }

    cout << fixed << setprecision(8);
    for (auto &i : rta) cout << i << ' ';
    cout << '\n';

    return 0;
}
