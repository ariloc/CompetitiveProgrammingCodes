#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,
    rb_tree_tag,tree_order_statistics_node_update> set_t;

int const MAXN = 5e5+5;
ll const INF = 9e18;

int histo[MAXN];
vector<pair<ll,int>> quer;
set_t merged;
int rta[MAXN];

int main() {
    FAST_IO;

    int n,m,q; cin >> n >> m >> q;
    forn(i,n) {
        int x; cin >> x; --x;
        histo[x]++;
    }

    set<ii> heis;

    forn(i,q) {
        ll x; cin >> x;
        quer.pb({x,i});
    }

    sort(all(quer));

    forn(i,m) heis.insert({histo[i],i});
    
    ll curh = (*heis.begin()).fst, acum = n;
    ll res = 0;

    auto upd_curh = [&](ll am){
        curh += am;
        while (!heis.empty() && (*heis.begin()).fst == curh) {
            merged.insert((*heis.begin()).snd);
            heis.erase(heis.begin());
        }
    };

    upd_curh(0);

    forn(i,q) {
        pair<ll,int> qq = quer[i]; qq.fst -= acum + 1;

        if (qq.fst >= (int)merged.size()-res) {
            ll tofill = (int)merged.size()-res;
            res = 0;
            acum += tofill;
            qq.fst -= tofill;
            upd_curh(1);

            while (qq.fst >= (int)merged.size()) {
                ll nxt = heis.empty() ? INF : (*heis.begin()).fst;
                ll toinc = min(nxt-curh, merged.empty() ? INF : qq.fst / (ll)merged.size());

                acum += toinc * (ll)merged.size();
                qq.fst -= toinc * (ll)merged.size();

                upd_curh(toinc);
            }
        }

        res += qq.fst;
        acum += qq.fst;
        rta[qq.snd] = *merged.find_by_order(res);
    }

    forn(i,q) cout << rta[i]+1 << '\n';

    return 0;
}
