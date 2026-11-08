#include <bits/stdc++.h>
#include <cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(c) (int)c.size()
#define FAST_IO ios::sync_with_stdio(false);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

int const MAXN = 1e6+5;

map<ll,int> pref;
map<ii,ll> mapita;

int main() {
    FAST_IO;

    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<ll> dis(0,1e18);

    int n,k; cin >> n >> k;

    vi func(k);
    iota(all(func),0);

    ll r = 0;
    ll hsh = 0;
    pref[hsh]++;
    forn(i,n) {
        int a,b; cin >> a >> b; --a, --b;
        
        int v1 = func[a], v2 = func[b];
        if (v1 != a) {
            auto it = mapita.find({a,v1});
            hsh ^= (*it).snd;
        }
        if (v2 != b) {
            auto it = mapita.find({b,v2});
            hsh ^= (*it).snd;
        }
        ii oa = {b,v1}, ob = {a,v2};
        if (b != v1) {
            auto it = mapita.find(oa);
            if (it == mapita.end()) {
                mapita[oa] = dis(rng);
                it = mapita.find(oa);
            }
            hsh ^= (*it).snd;
        }
        
        if (a != v2) {
            auto it = mapita.find(ob);
            if (it == mapita.end()) {
                mapita[ob] = dis(rng);
                it = mapita.find(ob);
            }
            hsh ^= (*it).snd;
        }

        swap(func[a],func[b]);
        
        auto it2 = pref.find(hsh);
        if (it2 != pref.end())
            r += (*it2).snd;

        pref[hsh]++;
    }

    cout << r << '\n';
   
    return 0;
}
