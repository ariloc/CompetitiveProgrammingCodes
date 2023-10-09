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
 
int const MAXN = 1e5+5;
 
vi G[MAXN];
bitset<MAXN> done;
map<vi,int> paths;
int prox_libre = 0;
bool posib = true;
vi cent;
int n;
 
int dfs (int st, bool check = 0) {
    done[st] = true;
 
    vi ids;
    for (auto &i : G[st])
        if (!done[i]) ids.pb(dfs(i, check));
 
    sort(all(ids));
    auto it = paths.find(ids);
    if (it == paths.end()) {
        if (check) {
            posib = false;
            return -1;
        }
        paths[ids] = prox_libre;
        return prox_libre++;
    }
    return (*it).snd;
}
 
int findcent (int st) {
    done[st] = true;
 
    bool iscent = true;
    int s = 0;
    for (auto &i : G[st]) 
        if (!done[i]) {
            int child = findcent(i);
            if (child > n/2) iscent = false;
            s += child;
        }
 
    if (n-s-1 > n/2) iscent = false;
 
    if (iscent) cent.pb(st);
 
    return s+1;
}
 
int main() {
    FAST_IO;
 
    int t; cin >> t;
    forn(o,t) {
        cin >> n;
        forn(i,n) G[i].clear(), done[i] = false;
        paths.clear(), cent.clear();
        prox_libre = 0;
 
        forn(i,n-1) {
            int u,v; cin >> u >> v; --u, --v;
            G[u].pb(v), G[v].pb(u);
        }
        findcent(0);
        forn(i,n) done[i] = false;
        dfs(cent[0]);
 
        forn(i,n) G[i].clear(), done[i] = false;
        cent.clear();
 
        forn(i,n-1) {
            int u,v; cin >> u >> v; --u, --v;
            G[u].pb(v), G[v].pb(u);
        }
 
        bool rta = false;
        findcent(0);
        forn(i,cent.size()) {
            forn(j,n) done[j] = false;
            posib = true;
            dfs(cent[i],1);
            rta |= posib;
        }
 
        cout << (rta ? "YES" : "NO") << '\n';
    }
 
    return 0;
}
