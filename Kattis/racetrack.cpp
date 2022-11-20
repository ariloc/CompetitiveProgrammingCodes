#include <bits/stdc++.h>
 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);
 
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int MAXN = 5005;

struct car {
    int lap_t;
    ll t_st;
    int cnt, id;

    bool operator< (const car &o) const {
        if (t_st != o.t_st) return t_st < o.t_st;
        if (lap_t != o.lap_t) return lap_t < o.lap_t;
        return id < o.id;
    }
};

set<car> rounds;
ll rta[MAXN];
int target[MAXN];

int main() {
    int n; scanf("%d", &n);

    forn(i,n) {
        int t,c; scanf("%d %d", &t, &c);
        target[i] = c;
        rounds.insert({t, 0, 0, i});
    }

    while (!rounds.empty()) {
        vector<car> toDel;

        auto e = *rounds.begin();
        ll arrival = e.t_st + e.lap_t;
        rounds.erase(rounds.begin());
        toDel.pb(e);

        while (!rounds.empty()) {
            auto e2 = *rounds.begin();
            ll act_arrival = e2.t_st + e2.lap_t;
            
            if (act_arrival > arrival) break;

            rounds.erase(rounds.begin());
            toDel.pb(e2);
        }

        while (!toDel.empty()) {
            auto e2 = toDel.back(); toDel.pop_back();
            e2.t_st = arrival; e2.cnt++;
            if (e2.cnt >= target[e2.id]) rta[e2.id] = e2.t_st;
            else rounds.insert(e2);
        }
    }

    forn(i,n) printf("%lld\n", rta[i]);
 
    return 0;
}
