
#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const ll INF = 1e18+5;
const int MAXN = 1e5+5;

set<int> num;
multiset<int> dists;
int arr[MAXN];

ll getDist() {
    if (num.empty() or dists.empty()) return 0;
    return ((*prev(num.end()))-(*num.begin()))-*(prev(dists.end()));
}

int main() {
    FAST_IO;

    int n,q; cin >> n >> q;
    forn(i,n) {
        int x; cin >> x;
        num.insert(x); arr[i] = x;
    }

    sort(arr,arr+n);
    forn(i,n-1) dists.insert(arr[i+1]-arr[i]);

    cout << getDist() << '\n';

    forn (i,q) {
        int typ,x; cin >> typ >> x;
        if (typ == 0) {
            auto it = num.lower_bound(x);
            int me = *it;
            if (it != prev(num.end()) and it != num.end()) {
                int nxt = *next(it);
                dists.erase(dists.lower_bound(nxt-me));
            }
            if (it != num.begin()) {
                int prv = *prev(it);
                dists.erase(dists.lower_bound(me-prv));
            }
            if (it != num.begin() and it != prev(num.end()) and it != num.end()) {
                int nxt = *next(it);
                int prv = *prev(it);
                dists.insert(nxt-prv);
            }
            num.erase(it);
        }
        else {
            auto it = num.lower_bound(x);
            if (it != num.end() and it != num.begin()) {
                int nxt = (*it), prv = *prev(it);
                dists.erase(dists.lower_bound(nxt-prv));
            }
            if (it != num.end()) {
                int nxt = (*it);
                dists.insert(nxt-x);
            }
            if (it != num.begin()) {
                int prv = *prev(it);
                dists.insert(x-prv);
            }
            num.insert(x);
        }
        cout << getDist() << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
