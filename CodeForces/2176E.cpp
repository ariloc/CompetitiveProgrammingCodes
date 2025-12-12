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

int const MAXN = 2e5+5;

int a[MAXN], c[MAXN], p[MAXN], vals[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        forn(i,n) cin >> a[i];
        forn(i,n) cin >> c[i];
        forn(i,n) cin >> p[i];

        forn(i,n) vals[i] = 0;

        ll ret = 0;

        vi ind;
        forn(i,n) ind.pb(i);
        sort(all(ind),[&](const int &lhs, const int &rhs){
            if (c[lhs] != c[rhs]) return c[lhs] < c[rhs];
            return a[lhs] > a[rhs];
        });


        set<int> reg,nd;
        forn(i,n) nd.insert(i);
        int offset = -1;
        forn(i,n) {
            int j = ind[i];
            auto it = nd.lower_bound(j);
            if (it != nd.end()) {
                if ((*it) != j) continue;
                vi toDel;
                while (it != nd.end() && a[*it] <= a[j]) {
                    ret += c[j];
                    vals[*it] = c[j];
                    reg.insert(*it);
                    toDel.pb(*it);
                    it = next(it);
                }
                for (auto &k : toDel) nd.erase(k);
            }
            it = nd.lower_bound(j);
            if (it != nd.begin()) {
                it = prev(it);
                vi toDel;
                while (a[*it] <= a[j]) {
                    ret += c[j];
                    vals[*it] = c[j];
                    reg.insert(*it);
                    toDel.pb(*it);
                    if (it == nd.begin())
                        break;
                    else it = prev(it);
                }
                for (auto &k : toDel) nd.erase(k);
            }
            if (nd.empty()) {
                nd.insert(j);
                //reg.erase(j);
                vals[j] = 0;
                offset = c[j];
                break;
            }
        }

        cout << ret-offset << ' ';

        forn(i,n) {
            int j = p[i]-1;
            auto it = reg.lower_bound(j);
            auto it2 = it;
            vi toDel;
            while (it != reg.end() && a[*it] <= a[j]) {
                toDel.pb(*it);
                ret -= vals[*it];
                it = next(it);
            }
            it = it2;
            if (it != reg.begin()) {
                it = prev(it);
                while (a[*it] <= a[j]) {
                    toDel.pb(*it);
                    ret -= vals[*it];
                    if (it == reg.begin())
                        break;
                    else it = prev(it);
                }
            }
            for (auto &k : toDel) reg.erase(k);

            cout << max(0LL,ret-offset) << ' ';
        }
        cout << '\n';
    }

    return 0;
}
