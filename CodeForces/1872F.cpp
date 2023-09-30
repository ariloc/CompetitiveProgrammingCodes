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

int const MAXN = 1e5+5;
int const INF = 2e9;

int afraid[MAXN], cost[MAXN], indeg[MAXN];
bitset<MAXN> done;

int main() {
    int t; scanf("%d",&t);
    forn(_,t) {
        int n; scanf("%d",&n);

        forn(i,n) indeg[i] = 0, done[i] = false;

        forn(i,n) {
            int x; scanf("%d",&x); --x;
            indeg[x]++;
            afraid[i] = x;
        }

        forn(i,n) scanf("%d",&cost[i]);

        queue<int> Q;
        forn(i,n) if (!indeg[i]) Q.push(i);

        vi rta;
        while (!Q.empty()) {
            auto e = Q.front(); Q.pop();
            
            rta.pb(e);
            done[e] = true;

            --indeg[afraid[e]];
            if (!indeg[afraid[e]]) Q.push(afraid[e]);
        }

        forn(i,n) {
            if (done[i]) continue;
            int act = i;
            int mini = INF, ind = -1;
            vi cycle;
            while (!done[act]) {
                if (cost[act] < mini) mini = cost[act], ind = act;
                cycle.pb(act);
                done[act] = true;
                act = afraid[act];
            }

            act = afraid[ind];
            for (auto &j : cycle) done[j] = false;
            while (!done[act]) {
                done[act] = true;
                rta.pb(act);
                act = afraid[act];
            }
        }

        for (auto &i : rta) printf("%d ",i+1);
        puts("");
    }
    
    return 0;
}
