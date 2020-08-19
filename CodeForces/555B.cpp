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

const int MAXN = 2e5+5;
const int INF = 1e9+5;

struct space {
    ll l; int id;

    bool operator< (const space &o) const{
        return o.l > l;
    }
};

struct space2 {
    ll l,lM; int id;

    bool operator< (const space2 &o) const{
        if (o.lM == lM) return o.l > l;

        return o.lM > lM;
    }
};

multiset<space> bridges;
space2 spaces[MAXN];
int rta[MAXN];

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;

    ll lastR = -1, lastL = -1;
    forn (i,n) {
        ll a,b; cin >> a >> b;
        if (a > b) swap(a,b);

        if (i) spaces[i-1] = {a-lastR,b-lastL,i-1};
        lastR = b; lastL = a;
    }

    forn (i,m) {
        ll x; cin >> x;
        bridges.insert({x,i});
    }

    sort(spaces,spaces+n-1);

    bool posib = true;
    forn (i,n-1) {
        auto it = bridges.lower_bound({spaces[i].l,-INF});
        if ((*it).l > spaces[i].lM or it == bridges.end()) {posib = false; break;}

        rta[spaces[i].id] = (*it).id; bridges.erase(it);
    }

    if (posib) {cout << "Yes\n"; forn (i,n-1) cout << rta[i]+1 << ' ';}
    else cout << "No";

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!