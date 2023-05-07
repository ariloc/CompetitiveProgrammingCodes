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

const int MAXN = 205;

bitset<MAXN> done, leaves;
int cnt[MAXN];
vi G[MAXN];

int dfs1(int st) {
    done[st] = true;

    for (auto &i : G[st]) {
        if (!done[i]) return dfs1(i);
    }

    return st;
}

void dfs2(int st) {
    done[st] = true;

    int child = 0;
    for (auto &i : G[st]) {
        if (!done[i]) dfs2(i), ++child;
    }

    if (!child) leaves[st] = true;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n,m; cin >> n >> m;

        forn(i,n) done[i] = 0, cnt[i] = 0, leaves[i] = 0, G[i].clear();

        forn(i,m) {
            int u,v; cin >> u >> v; u--, v--;
            G[u].pb(v), G[v].pb(u);
        }

        int leaf = dfs1(0);
        leaves[leaf] = true;

        forn(i,n) done[i] = 0;

        dfs2(leaf);

        forn(i,n) if (leaves[i]) {
            for (auto &j : G[i]) {
                ++cnt[j];
            }
        }

        int y = -1;
        forn(i,n) if (cnt[i]) {
            y = cnt[i]; break;
        }

        int root = -1;
        forn(i,n) if (!leaves[i] && !cnt[i]) root = i;

        int x = 0;
        for (auto &i : G[root]) x++;

        cout << x << ' ' << y << '\n';
    }
    
    return 0;
}
