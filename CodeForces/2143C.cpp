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

int const MAXN = 2e5+5;

struct edge {
    int v,x,y;
};

vector<edge> G[MAXN];
bitset<MAXN> done;
vi l,r;
ll acc;
int perm[MAXN];

void dfs(int st, int p = -1, int x = -1, int y = -1) {
    done[st] = true;

    for (auto &i : G[st]) {
        if (!done[i.v])
            dfs(i.v,st,i.x,i.y);
    }

    if (p != -1) {
        if (st < p) {
            if (x > y) r.pb(st), acc += x;
            else l.pb(st), acc += y;
        }
        else {
            if (x > y) l.pb(st), acc += x;
            else r.pb(st), acc += y;
        }
    }
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;

        forn(i,n) G[i].clear(), done[i] = false, perm[i] = 0;
        l.clear();
        r.clear();
        acc = 0;

        forn(i,n-1) {
            int u,v,x,y; cin >> u >> v >> x >> y; u--, v--;
            G[u].pb({v,x,y}), G[v].pb({u,x,y});
        }

        dfs(0);
        l.pb(0);

        reverse(all(r));
        forn(i,l.size())
            perm[l[i]] = i+1;
        forn(i,r.size())
            perm[r[i]] = (int)l.size()+i+1;

        forn(i,n) cout << perm[i] << ' ';
        cout << '\n';
    }

    return 0;
}

