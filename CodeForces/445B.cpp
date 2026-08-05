#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);


using namespace std;
typedef vector<int> vi;

int const MAXN = 55;

vi G[MAXN];
bitset<MAXN> done;

int dfs(int st) {
    done[st] = true;

    int acc = 1;
    for (auto &i : G[st])
        if (!done[i]) acc += dfs(i);

    return acc;
}

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,m) {
        int x,y; cin >> x >> y;
        --x, --y;
        G[x].pb(y), G[y].pb(x);
    }

    int maxi = 0;
    forn(i,n) if (!done[i]) maxi += dfs(i)-1;

    cout << (1LL<<maxi) << '\n';

    return 0;
}
