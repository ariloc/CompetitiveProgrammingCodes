#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= 0; i--)
#define forsn(i,s,n) for(int i = 0; i < int(n); i++)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int const MAXN = 5005;
int const INF = 1e9;

vi G[MAXN];
vector<ii> edges;
int cnt[MAXN];
bitset<MAXN> done;
vector<ii> posibedges;
int n,m;

bool go(int st, int mid) {
    done[st] = true;

    if (cnt[st]+1 <= mid) {
        cnt[st]++;
        return true;
    }

    int toswap = -1;
    forn(i,G[st].size()) {
        if (!done[G[st][i]]) {
            if(go(G[st][i],mid)) {
                toswap = i;
                break;
            }
        }
    }
    if (toswap != -1) {
        auto it = G[st].begin()+toswap;
        int elem = *it;
        G[st].erase(it);
        G[elem].pb(st);
        return true;
    }

    return false;
}

bool posib(int mid) {
    forn(i,n) cnt[i] = 0, G[i].clear();
    for (auto &e : edges) {
        G[e.fst].pb(e.snd);
        if (cnt[e.fst]+1 > mid) {
            done.reset();
            if (!go(e.fst, mid))
                return false;
        }
        else cnt[e.fst]++;
    }
    posibedges.clear();
    forn(i,n) for (auto &e : G[i]) posibedges.pb({i,e});
    return true;
}

int main() {
    FAST_IO;

    cin >> n >> m;
    forn(i,m) {
        int u,v; cin >> u >> v; --u, --v;
        edges.pb({u,v});
    }

    int low = -1, high = n;
    while (high - low > 1) {
        int mid = (high+low)/2;
        if (posib(mid)) high = mid;
        else low = mid;
    }

    posib(high);

    cout << high << '\n';
    for (auto &i : posibedges)
        cout << i.fst+1 << ' ' << i.snd+1 << '\n';
    
    return 0;
}
