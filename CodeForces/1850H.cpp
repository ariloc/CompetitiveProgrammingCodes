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

int const MAXN = 2e5+5;

struct edge {
    int v,w;
};

vector<edge> G[MAXN];
bitset<MAXN> done;
map<int,ll> coords;
bool posib = true;

void dfs (int st) {
    done[st] = true;

    for (auto &i : G[st]) {
        ll newc = coords[st]+(ll)i.w;
        auto it = coords.find(i.v);
        if (it != coords.end() && (*it).snd != newc)
            posib = false;
        else coords[i.v] = newc;
    }
    for (auto &i : G[st])
        if (!done[i.v]) dfs(i.v);
}

int main() {
    int t; scanf("%d",&t);
    forn(_,t) {
        int n,m; scanf("%d %d",&n,&m);

        forn(i,n) G[i].clear(), done[i] = 0;
        coords.clear();
        posib = true;

        forn(i,m) {
            int a,b,d; scanf("%d %d %d",&a,&b,&d), a--, b--;
            G[a].pb({b,d}), G[b].pb({a,-d});
        }

        forn(i,n) {
            if (done[i]) continue;
            coords[i] = 0;
            dfs(i);
        }

        printf("%s\n",posib ? "YES" : "NO");
    }
          
    return 0;
}
