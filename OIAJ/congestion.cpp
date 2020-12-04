#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 1e3+2;
const int MAXM = 5e3+2;

struct nodo {
    int v,d,e;

    bool operator< (const nodo &o) const{
        return o.d < d;
    }
};

void fastscan (int &x) {
    int c; x = 0;
    c=getchar_unlocked();
    while (c<'0'||c>'9') c=getchar_unlocked();
    for(; (c>='0'&&c<='9'); c=getchar_unlocked())
        x = 10*x + c-'0';
}

vector<nodo> G[MAXN];
ii P[MAXN][MAXN];
int dp[MAXN][MAXN];
ii E[MAXM];

void dijkstra (int st) {
    vi D(MAXN,-1);
    priority_queue<nodo> Q;
    D[st] = 0;
    P[st][st] = {-1,-1};
    Q.push({st,0,0});

    while (not Q.empty()) {
        auto e = Q.top(); Q.pop();

        for (auto &w : G[e.v]) {
            if (D[w.v] == -1 or D[w.v] > e.d + w.d) {

                D[w.v] = e.d + w.d;
                P[st][w.v] = {e.v,w.e};

                Q.push({w.v,D[w.v],0});
            }
        }
    }
}

int dfs(int &lvl, int st) {
    if (dp[lvl][st]) return dp[lvl][st];
    dp[lvl][st] = -1;

    for (auto &i : G[st]) {
         if (!dp[lvl][i.v] and lvl != i.v and P[lvl][i.v].fst == st)
            dp[lvl][st] += dfs(lvl,i.v);
    }

    if (P[lvl][st].snd != -1) {
        E[P[lvl][st].snd].fst += dp[lvl][st]+2;
        if (!E[P[lvl][st].snd].snd) E[P[lvl][st].snd].snd = P[lvl][st].snd;
    }
    return dp[lvl][st]+2;
}

int main() {
    freopen("congestion.in","r",stdin);
    freopen("congestion.out","w",stdout);

    int N,M,prox_libre = 1;
    fastscan(N); fastscan(M);

    forn (i,M) {
        int a,b,d; fastscan(a); fastscan(b); fastscan(d);
        a--; b--;
        G[a].push_back({b,d,prox_libre++});
    }

    forn (i,N)
        dijkstra(i);

    forn (i,N)
        dfs(i,i);

    sort(E,E+MAXM,greater<ii>());

    int refer = E[0].fst; vi tramos;
    forn (i,M) {
        if (E[i].fst != refer) break;
        tramos.push_back(E[i].snd);
    }

    printf("%d %d\n",tramos.size(),refer);
    for (auto &i : tramos) printf("%d ",i);

    return 0;
}
