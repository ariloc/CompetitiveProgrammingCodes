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

int const MAXN = 2505;
int const INF = 1e9;

vi G[MAXN];
int n,m;
bitset<MAXN> done,old;
ii bst[MAXN];

int rta = INF;
int bfs (int st) {
    forn(i,n) done[i] = old[i] = 0, bst[i] = {INF, INF};
    queue<ii> Q;
    Q.push({st,0});
    done[st] = true;

    vi backlog;
    int last = 0;

    int ret = INF;
    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        if (e.snd > rta) break;

        if (e.snd != last) {
            last = e.snd;
            for (auto &i : backlog) old[i] = true;
            backlog.clear();
        }
        backlog.pb(e.fst);

        for (auto &i : G[e.fst]) {
            if (old[i]) continue;

            if (e.snd+1 <= bst[i].fst) {
                swap(bst[i].fst,bst[i].snd);
                bst[i].fst = e.snd+1;
            }
            else if (e.snd+1 < bst[i].snd) {
                bst[i].snd = e.snd+1;
            }

            if (bst[i].fst != INF && bst[i].snd != INF)
                ret = min(ret,bst[i].fst+bst[i].snd);

            if (done[i]) continue;
            done[i] = true;
            Q.push({i,e.snd+1});
        }
    }
    return ret;
}

int main() {
    FAST_IO;

    cin >> n >> m;
    forn(i,m) {
        int u,v; cin >> u >> v; u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    vi tofind;
    forn(i,n) tofind.pb(i);
    srand(time(NULL));
    random_shuffle(all(tofind));
    forn(i,n) rta = min(rta, bfs(tofind[i]));

    cout << (rta == INF ? -1 : rta) << '\n';

    return 0;
}
