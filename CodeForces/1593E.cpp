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
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 4e5+5;

vi G[MAXN];
int deg[MAXN];
bitset<MAXN> done;

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n,k; cin >> n >> k;

        forn(i,n) deg[i] = 0, G[i].clear(); // init

        forn(i,n-1) {
            int u,v; cin >> u >> v; u--, v--;
            G[u].pb(v), G[v].pb(u);
            deg[u]++, deg[v]++;
        }
        vi Q[2];
        forn(i,n) if (deg[i] <= 1) Q[0].pb(i);

        bool act = 0;
        int actN = n;
        while ((k--) && actN) {
            while (!Q[act].empty()) {
                auto e = Q[act].back(); Q[act].pop_back();

                for (auto &i : G[e])
                    if ((--deg[i]) == 1)
                        Q[1^act].pb(i);
                
                actN--;
            }
            act ^= 1;
        }

        cout << actN << '\n';
    }

    return 0;
}