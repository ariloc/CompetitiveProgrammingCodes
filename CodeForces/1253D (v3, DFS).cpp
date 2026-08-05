#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define fst first
#define snd second
#define pb push_back
#define sz(c) (int)c.size()
#define FAST_IO ios::sync_with_stdio(false);

using namespace std;
typedef long long ll;
typedef vector<int> vi;

const int MAXN=2e5+5;

vi G[MAXN];
bitset<MAXN> done;

int dfs(int st) {
    done[st] = true;

    int maxi = st;
    for (auto &i : G[st])
        if (!done[i]) maxi = max(maxi, dfs(i));

    return maxi;
}

int main(){
    FAST_IO;

    int n,m; cin >> n >> m;

    forn(i,m) {
        int u,v; cin >> u >> v;
        --u, --v;
        G[u].pb(v), G[v].pb(u);
    }

    int rta=0, nxt=0;
    while (nxt < n) {
        int cur = nxt;
        int maxi = dfs(cur);
        while (cur <= maxi) {
            if (!done[cur]) {
                maxi = max(maxi, dfs(cur));
                ++rta;
            }
            ++cur;
        }
        nxt = cur;
    }

    cout << rta << '\n';

    return 0;
}
