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

int const MOD = 998244353;
int const MAXN = 2e5+5;

ll arr[MAXN];
vector<pair<ll,ii>> edges;
map<ll,ll> sums[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n,m; cin >> n >> m;
        forn(i,n) cin >> arr[i];

        forn(i,n) sums[i].clear();
        edges.clear();

        forn(i,m) {
            int u,v; cin >> u >> v; --u, --v;
            if (u == v) continue;
            edges.pb({arr[v],{u,v}});
        }

        sort(all(edges));

        ll rta = 0;
        for (auto &i : edges) {
            int u = i.snd.fst, v = i.snd.snd;
            ll auxi = arr[u]+arr[v];
            auto it = sums[v].find(auxi);
            if (it == sums[v].end())
                sums[v][auxi] = 1;
            else (*it).snd++;
            rta++;
        }

        for (auto &i : edges) {
            int u = i.snd.fst, v = i.snd.snd;
            auto it = sums[u].find(arr[v]);
            if (it != sums[u].end()) {
                ll auxi = arr[u] + arr[v];
                auto it2 = sums[v].find(auxi);
                ll val = (*it).snd;
                if (it2 == sums[v].end())
                    sums[v][auxi] = val;
                else (*it2).snd = ((*it2).snd+val)%MOD;
                rta = (rta+val)%MOD;
            }
        }

        cout << rta << '\n';
    }

    return 0;
}
