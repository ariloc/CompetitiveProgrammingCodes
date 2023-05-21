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

const int MAXN = 1e5+5;
const int MAXK = 18;
const int INF = 2e9;

vi G[MAXN];
vector<ii> queries[MAXN];
int P[MAXK][MAXN], rta[MAXN], D[MAXN];
bitset<MAXN> done;

set<ii> dfs (int st) {
    done[st] = true;

    set<ii> ret;
    ret.insert({D[st], 1});
    for (auto &i : G[st]) {
        if (!done[i]) {
            set<ii> aux = dfs(i);
            if ((int)aux.size() > (int)ret.size()) aux.swap(ret);
            for (auto &j : aux) {
                auto it = ret.lower_bound({j.fst, -INF});
                if (it != ret.end() && (*it).fst == j.fst) {
                    ii e = *it;
                    e.snd += j.snd;
                    ret.erase(it);
                    ret.insert(e);
                }
                else {
                    ret.insert(j);
                }
            }
        }
    }

    for (auto &i : queries[st]) {
        auto it = ret.lower_bound({i.fst, -INF});
        if (it == ret.end() || (*it).fst != i.fst) rta[i.snd] = 0;
        else rta[i.snd] = (*it).snd-1;
    }

    return ret;
}

void dfs2 (int st, int lvl = 0) {
    done[st] = true;
    D[st] = lvl;

    for (auto &i : G[st]) {
        if (!done[i]) dfs2(i,lvl+1);
    }
}

int main() {
    FAST_IO;

    int n; cin >> n;

    forn(i,n) {
        int x; cin >> x;
        if (!x) continue;
        G[x-1].pb(i);
        P[0][i+1] = x;
    }

    // 1-index to use 0 as -1
    forsn(k,1,MAXK) forn(i,n+1) P[k][i] = P[k-1][P[k-1][i]];

    forn(i,n) if (!done[i]) dfs2(i);

    int m; cin >> m;
    forn(i,m) {
        int v,p; cin >> v >> p;
        int aux = v;
        forn(j,MAXK) if (p&(1<<j)) aux = P[j][aux];
        if (!aux) continue;
        queries[aux-1].pb({D[v-1],i});
    }

    forn(i,n) done[i] = 0;
    forn(i,n) if (!done[i]) dfs(i);

    forn(i,m) cout << rta[i] << ' ';

    return 0;
}
