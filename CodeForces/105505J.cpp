#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define sz(c) (int)(c).size()
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef long double ld;

ld const PI = acos(-1);

int main() {
    FAST_IO;

    int deg,n; cin >> deg >> n;

    ld rdeg = deg*PI/(ld)180;

    vector<pair<ld,bool>> seg;
    forn(i,n) {
        int x,h; cin >> x >> h;
        seg.pb({x,true});
        ld c2 = h / tan(rdeg);
        seg.pb({x+c2,false});
        cerr << x << ' ' << x+c2 << endl;
    }

    sort(all(seg));

    int cnt = 0;
    ld rta = 0, lastp;
    forn(i,sz(seg)) {
        if (cnt) rta += seg[i].first - lastp;

        if (seg[i].second) {
            cnt++;
        }
        else --cnt;

        if (cnt) lastp = seg[i].first;
    }

    cout << fixed << setprecision(10) << rta << '\n';

    return 0;
}
