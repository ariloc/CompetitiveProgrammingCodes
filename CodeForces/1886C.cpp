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

int const MAXN = 1e6+5;

struct elem {
    char c;
    int pos;

    bool operator< (const elem &o) const {
        return pos < o.pos;
    }
};

set<elem> car,tod;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        string s; cin >> s;
        ll pos; cin >> pos; --pos;

        car.clear();
        tod.clear();

        forn(i,s.size()-1) if (s[i] > s[i+1]) car.insert({s[i],i});
        forn(i,s.size()) tod.insert({s[i],i});
        ll auxp = 0;
        int sz = (int)s.size();
        while (auxp + sz - 1 < pos) {
            if (car.empty()) break;  
            auxp += sz; --sz;
            elem aux = *car.begin();
            car.erase(car.begin());
            auto it = tod.lower_bound(aux);
            if (it != tod.begin() && next(it) != tod.end()) {
                if ((*prev(it)).c > (*next(it)).c) car.insert(*prev(it));
            }
            tod.erase(aux);
        }
        string reb;
        while (!tod.empty()) {
            auto aux = *tod.begin();
            reb.pb(aux.c);
            tod.erase(tod.begin());
        }
        while (auxp + sz - 1 < pos) {
            auxp += sz; --sz;
            reb.pop_back();
        }
        cout << reb[pos-auxp];
    }
    cout << '\n';

    return 0;
}
