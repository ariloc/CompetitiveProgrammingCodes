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
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 1e4+5;
const int MAXM = 2e4+5;
const int MAXK = 8;
const int MAXE = 1e5+5;

struct edge {
    int v,w;
};

struct statDijk {
    int v,w;
    int mk; // mask of killed
    bool id; // 0-1 id impostor

    statDijk(){}
    statDijk(int v, int w, int mk, bool id) : v(v), w(w), mk(mk), id(id) {}
    
    bool operator< (const statDijk &o) const {
        return w > o.w;
    }
};

vector<edge> G[MAXN];
int D[MAXN][1<<MAXK][2];
vi events[MAXN][MAXK];
bool arrived[1<<MAXK][2];

int main() {
    int T; scanf("%d",&T);
    forn(_,T) {
        int n,m,k; scanf("%d %d %d",&n,&m,&k);

        // reset
        forn(i,n) {
            G[i].clear();
            forn(j,k) events[i][j].clear();
            forn(j,1<<k) D[i][j][0] = D[i][j][1] = -1;
        }
        forn(i,1<<k) arrived[i][0] = arrived[i][1] = false;

        forn(i,m) {
            int u,v,w; scanf("%d %d %d",&u,&v,&w);
            --u, --v;
            G[u].pb({v,w}), G[v].pb({u,w});
        }
        
        int E,tmax; scanf("%d %d",&E,&tmax);

        forn(i,E) {
            int p,x,t; scanf("%d %d %d",&p,&x,&t);
            --p, --x;
            events[x][p].pb(t);
        }

        forn(i,n) forn(j,k) sort(all(events[i][j]));

        int x,y; scanf("%d %d",&x,&y);
        --x, --y;

        priority_queue<statDijk> Q;
        Q.push(statDijk(x,0,0,0)), Q.push(statDijk(y,0,0,1));
        D[x][0][0] = D[y][0][1] = 0;

        int maxi = 0; bool posib = false;
        while (!Q.empty()) {
            auto e = Q.top(); Q.pop();

            if (e.w > tmax) break; // stop when no solution found
            if (e.w != D[e.v][e.mk][e.id]) continue;

            maxi = max(maxi, e.w);
            arrived[e.mk][e.id] = true;

            int all_mk = (1<<k) - 1;
            if (arrived[all_mk^e.mk][e.id^1]) {
                posib = true;
                break;
            }

            // busquemos si llega el crewmate j acá
            forn(j,k) {
                if (e.mk&(1<<j)) continue;
                int new_mk = e.mk | (1<<j);
                auto it = lower_bound(all(events[e.v][j]),e.w);
                if (it == events[e.v][j].end()) continue;

                int act_t = *it;
                if (D[e.v][new_mk][e.id] == -1 || D[e.v][new_mk][e.id] > act_t) {
                    D[e.v][new_mk][e.id] = act_t;
                    Q.push(statDijk(e.v,act_t,new_mk,e.id));
                }
            }

            // pasar
            for (auto &i : G[e.v]) {
                if (D[i.v][e.mk][e.id] == -1 || D[i.v][e.mk][e.id] > e.w + i.w) {
                    D[i.v][e.mk][e.id] = e.w + i.w;
                    Q.push(statDijk(i.v,D[i.v][e.mk][e.id],e.mk,e.id));
                }
            }
        }

        if (!posib) puts("-1");
        else printf("%d\n",maxi);
    }

    return 0;
}
