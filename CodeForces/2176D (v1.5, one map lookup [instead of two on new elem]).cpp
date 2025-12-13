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
vi G[MAXN];
map<ll,ll> sums[MAXN][2];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n,m; cin >> n >> m;
        forn(i,n) cin >> arr[i];

        forn(i,n) sums[i][0].clear(), sums[i][1].clear(),  G[i].clear();

        forn(i,m) {
            int u,v; cin >> u >> v; --u, --v;
            if (u == v) continue;
            G[v].pb(u); // rev
        }

        ll rta = 0;
        forn(i,n) for (auto &j : G[i]) {
            ll auxi = arr[i]+arr[j];
            sums[i][0][auxi]++;
            rta++;
        }

        bool toMove = true;
        int turn = 0;
        while (toMove) {
            toMove = false;

            forn(i,n) {
                sums[i][1-turn].clear();

                for (auto &j : G[i]) {
                    auto it = sums[j][turn].find(arr[i]);
                    if (it != sums[j][turn].end()) {
                        ll auxi = arr[i] + arr[j];
                        ll val = (*it).snd;
                        auto it2 = sums[i][1-turn].insert({auxi,val});
                        if (!it2.snd)
                            (*(it2.fst)).snd = ((*(it2.fst)).snd+val)%MOD;
                        rta = (rta+val)%MOD;
                        toMove = true;
                    }
                }
            }

            turn = 1-turn;
        }

        cout << rta << '\n';
    }

    return 0;
}
