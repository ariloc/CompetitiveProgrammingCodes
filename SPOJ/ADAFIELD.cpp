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

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n,m,q; cin >> n >> m >> q;

        multiset<int> maxx, maxy;
        set<int> lx, ly;

        lx.insert(0); lx.insert(n);
        ly.insert(0); ly.insert(m);
        maxx.insert(n);
        maxy.insert(m);

        forn(i,q) {
            int typ,co; cin >> typ >> co;

            multiset<int> *maxc = &maxx;
            set<int> *lc = &lx;
            if (typ) {
                lc = &ly;
                maxc = &maxy;
            }

            if (!lc->count(co)) {
                auto it = lc->upper_bound(co);
                auto it2 = prev(lc->lower_bound(co));

                int l = *it2, r = *it;
                maxc->erase(maxc->lower_bound(r-l));
                maxc->insert(r-co);
                maxc->insert(co-l);

                lc->insert(co);
            }

            cout << *maxx.rbegin() * (ll)*maxy.rbegin() << '\n';
        }
    }

    return 0;
}
