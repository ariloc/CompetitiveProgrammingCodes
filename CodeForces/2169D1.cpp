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

ll const MAXT = 1e12;

ll calc(ll mid, ll x, ll y) {
    ll bck = mid-1;
    forn(i,x) bck -= bck/y;
    return bck+1;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        ll x,y,k; cin >> x >> y >> k;

        ll lo = k, hi = MAXT+2;
        while(hi-lo > 1) {
            ll mid = (hi+lo)/2LL;
            if (calc(mid,x,y) > k) hi = mid;
            else lo = mid;
        }
        cout << (lo > MAXT ? -1 : lo) << '\n';
    }
   
    return 0;

}
