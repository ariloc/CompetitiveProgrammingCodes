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

const int MAXN = 1e5+2;

struct nodo {
    int v;
    ll d;

    bool operator< (const nodo &o) const{
        return o.d < d;
    }
};

vector<nodo> G[MAXN];
int P[MAXN];
ll D[MAXN];

void dijkstra (int st) {
    priority_queue<nodo> Q;
    Q.push({st,1});
    D[st] = 1;
    P[st] = -1;

    while (not Q.empty()) {
        auto x = Q.top().v; Q.pop();

        for (auto &w : G[x]) {
            if (!D[w.v] or D[w.v] > D[x] + w.d) {
                P[w.v] = x;
                D[w.v] = D[x] + w.d;
                Q.push({w.v, D[w.v]});
            }
        }
    }
}

int dfs (int &st) {
    if (st == -1) return 0;
    dfs(P[st]);
    printf ("%d ",st+1);
}

int main() {
    int n,m;
    scanf ("%d %d",&n,&m);
    forn (i,m) {
        int a,b,d;
        scanf("%d %d %d",&a,&b,&d);
        a--; b--;
        G[a].push_back({b,d});
        G[b].push_back({a,d});
    }

    dijkstra(0);

    int nd = n-1;
    if (!D[nd]) puts("-1");
    else dfs(nd); // cout padres

    return 0;
}