#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 3e5+5;

vi G[MAXN];
bitset<MAXN> done, hasok;
vector<ii> edges;
int dep[MAXN], children[MAXN];

void match(vi &pend) {
    while ((int)pend.size() > 1) {
        int a = pend.back(); pend.pop_back();
        int b = pend.back(); pend.pop_back();
        edges.pb({a,b});
    }
}

int dfs(int st) {
    done[st] = true;

    int ret = -1;
    for (auto &i : G[st])
        if (!done[i]) ret = dfs(i);
    
    if (ret == -1) return st;
    return ret;
}

vi dfs2(int st, int d = 0) {
    done[st] = true;
    dep[st] = d;

    vi pend;
    bool ischi = true;
    for (auto &i : G[st])
        if (!done[i]) {
            vi auxi = dfs2(i,d+1);
            pend.insert(pend.end(),all(auxi));
            ischi = false;
        }

    if (!ischi) {
        match(pend);
        if (pend.empty()) pend.pb(st);
    }
    else pend.pb(st);

    return pend;
}

bool dfs3(int st) {
    done[st] = true;

    int cnt = 0;
    for (auto &i : G[st])
        if (!done[i]) {
            cnt++;
            if (dfs3(i)) hasok[st] = true;
        }
    
    children[st] = cnt;
    if (cnt&1) hasok[st] = true;
    return hasok[st];
}

void solve(int st, int p) {
    done[st] = true;
    vi ot;
    if (!(children[st]%2)) {
        int idx;
        for (auto &i : G[st]) if (!done[i] && hasok[i]) idx = i;
        for (auto &i : G[st]) if (!done[i] && i != idx) ot.pb(i);
        solve(idx,st);
    }
    else for (auto &i : G[st]) if (!done[i]) ot.pb(i);

    vi pend;
    for (auto &i : ot) if (!done[i]) {
        vi auxi = dfs2(i);
        pend.insert(pend.end(),all(auxi));
    }

    pend.pb(p);
    match(pend);
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;

        forn(i,n) G[i].clear(), done[i] = hasok[i] = false;
        edges.clear();

        forn(i,n-1) {
            int u,v; cin >> u >> v; --u, --v;
            G[u].pb(v), G[v].pb(u);
        }

        int child = dfs(0);
        int chi;
        for (auto &i : G[child]) chi = i;
        
        forn(i,n) done[i] = false;
        done[child] = true;
        if (!dfs3(chi)) {
            cout << "-1\n";
            continue;
        }

        forn(i,n) done[i] = false;
        done[child] = true;
        solve(chi, child);

        cout << (int)edges.size() << '\n';
        for (auto &i : edges) cout << i.fst+1 << ' ' << i.snd+1 << '\n';
    }

    return 0;
}
