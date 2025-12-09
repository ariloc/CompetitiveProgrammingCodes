#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

ll const INFL = 9e18;

ll hypot2(ll x, ll y) { return x*x + y*y; }

ll llsqrt(__int128 x) {
    ll lo = 0, hi = INFL;
    while (hi-lo > 1) {
        ll mid = lo + (hi-lo)/2LL;
        if ((__int128)mid*mid <= x) lo = mid;
        else hi = mid;
    }
    return lo;
}

vector<int> ladron(int N, int M, vector<int> &x, vector<int> &y, vector<long long> &dCuad) {
    auto check = [&](int xi, int yi) {
        return hypot2(xi-x[0],yi-y[0]) == dCuad[0] && hypot2(xi-x[1],yi-y[1]) == dCuad[1] && hypot2(xi-x[2],yi-y[2]) == dCuad[2];
    };

    int offx = x[0], offy = y[0];
    forn(k,3) x[k] -= offx, y[k] -= offy;

    ll a = 2*x[1], b = 2*y[1], c = dCuad[1] - dCuad[0] - (x[1]*(ll)x[1]) - (y[1]*(ll)y[1]);

    __int128 auxi = (a*a + b*b) * (__int128)dCuad[0] - c*(__int128)c;
    ll rt = llsqrt(auxi);

    vector<ii> rta;

    auto test = [&](__int128 num) {
        if (!(num%(2LL*a*(__int128)a + 2LL*b*(__int128)b))) {
            ll yi1 = num / (2LL*a*(__int128)a + 2LL*b*(__int128)b);
            if (yi1+offy >= 0 && yi1+offy < M) {
                ll xi1 = llsqrt(dCuad[0] - yi1*yi1);
                forn(_,2) {
                    if (xi1+offx >= 0 && xi1+offx < N && check(xi1,yi1)) {
                        rta.pb({xi1+offx,yi1+offy});
                    }
                    xi1 = -xi1;
                }
            }
        }
    };

    __int128 disc = 2*a*(__int128)rt;
    test(-2*b*(__int128)c + disc);
    test(-2*b*(__int128)c - disc);

    sort(all(rta));
    rta.erase(unique(all(rta)),rta.end());

    vi r;
    for (auto &i : rta) { r.pb(i.fst); r.pb(i.snd); }

    return r;
}
