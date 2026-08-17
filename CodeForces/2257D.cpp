#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 5e4+5;
ll const INF = 9e18;

ll dp[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        ll S; cin >> S;

        vector<pair<ll,ll>> rect;
        for (int i = 1; (ll)i*i <= S; i++) {
            if (!(S%i)) {
                rect.pb({i,S/i});
                if (i != S/i) rect.pb({S/i,i});
            }
        }
        rect.pb({0,INF});
        rect.pb({INF,0});
        sort(all(rect));

        dp[0] = 0;
        forsn(i,1,sz(rect)) dp[i] = dp[i-1] + (rect[i].fst-rect[i-1].fst)*(ll)rect[i].snd;

        vector<ll> byfst, bysnd;
        for (auto &i : rect) byfst.pb(i.fst), bysnd.pb(i.snd);

        int q; cin >> q;
        forn(_,q) {
            ll x,y; cin >> x >> y;

            int l = lower_bound(all(bysnd),y,greater<ll>())-bysnd.begin()-1;
            int r = lower_bound(all(byfst),x)-byfst.begin();

            ll rta;
            if (l < r) {
                rta = rect[l].fst * (ll)y;
                rta += rect[r].snd * (ll)x;
                rta -= rect[l].fst * (ll)rect[r].snd;
                rta += dp[r-1] - dp[l] - (byfst[r-1]-byfst[l]) * (ll)rect[r].snd;
            }
            else {
                rta = x*y;
            }

            cout << rta << '\n';
        }
    }

    return 0;
}
