#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 1e5+2;

int gold[MAXN];
vi G[MAXN];
bitset<MAXN> done;

ll dfs (int st) {
    done[st] = true;

    ll val = gold[st];
    for (auto &i : G[st])
        if (!done[i])
            val = min(val,dfs(i));

    return val;
}

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;

    forn (i,n) cin >> gold[i];

    forn (i,m) {
        int a,b; cin >> a >> b; a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    ll tot = 0;
    forn (i,n) if (!done[i]) tot += dfs(i);

    cout << tot;

    return 0;
}