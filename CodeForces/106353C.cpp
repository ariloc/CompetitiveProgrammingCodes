#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < n; i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define sz(c) (int)(c).size()
#define pb push_back
#define fst first
#define snd second
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long long ll;

int const MAXN = 1e5+5;

struct edge {
    int v,w;
};

vector<edge> G[MAXN];
int deg[MAXN];
bitset<MAXN> done;

pair<ll,bool> dfs(int st) {
    done[st] = true;

    ll acc = 0;
    int cnt = deg[st]&1;
    for (auto &i : G[st])
        if (!done[i.v]) {
            auto r = dfs(i.v);
            if (r.snd) acc += i.w, ++cnt;
            acc += r.fst;
        }
    
    return {acc,cnt&1};
}

int main() {
    int n; cin >> n;
    
    forn(i,n-1) {
        int a,b,w; cin >> a >> b >> w; --a, --b;
        G[a].pb({b,w}), G[b].pb({a,w});
    }

    int m; cin >> m;
    forn(i,m) {
        int a,b; cin >> a >> b; --a, --b;
        deg[a]++, deg[b]++;
    }

    vi od;
    forn(i,n) if (deg[i]&1) od.pb(i);

    if (od.empty()) return cout << "0\n", 0;

    cout << dfs(od.back()).fst << '\n';

    return 0;
}
