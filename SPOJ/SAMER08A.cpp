#include <algorithm>
#include <bits/stdc++.h>
#include <queue>

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

const int MAXN = 505;
const int MAXM = 1e4+5;

struct iedge {
    int u,v,w,id;
};

struct edge {
    int v;
    ll w;
    int id;

    bool operator< (const edge &o) const {
        return w > o.w;
    }
};

int n,m;
vector<iedge> inp;
vector<edge> G[MAXN];
vector<ii> P[MAXN];
bitset<MAXN> done;
bitset<MAXM> used;
ll D[MAXN];

void dijkstra (int st) {
    forn(i,n) D[i] = -1;
    priority_queue<edge> Q;
    Q.push({st,0,-1});
    D[st] = 0;

    while (!Q.empty()) {
        auto e = Q.top().v; Q.pop();

        for (auto &i : G[e]) {
            if (D[i.v] == -1 || D[i.v] > D[e] + i.w) {
                D[i.v] = D[e] + i.w;
                P[i.v].clear();
                Q.push({i.v,D[i.v],-1});
            }
            if (D[i.v] == D[e] + i.w) {
                P[i.v].pb({e,i.id});
            }
        }
    }
}

void dag (int st) {
    done[st] = true;

    for (auto &i : P[st]) {
        used[i.snd] = true;
        if (!done[i.fst]) dag(i.fst);
    }
}

int main() {
    FAST_IO;

    while (cin >> n >> m) {
        if (!n && !m) break;

        int s,d; cin >> s >> d;

        inp.clear();
        forn(i,n) G[i].clear(), P[i].clear(), done[i] = 0;
        forn(i,m) used[i] = 0;

        forn(i,m) {
            int u,v,w; cin >> u >> v >> w;
            G[u].pb({v,w,i});
            inp.pb({u,v,w,i});
        }

        dijkstra(s);

        dag(d);

        forn(i,n) G[i].clear();

        for (auto &i : inp) {
            if (used[i.id]) continue;
            G[i.u].pb({i.v,i.w,-1});
        }

        dijkstra(s);

        cout << D[d] << '\n';
    }

    return 0;
}
