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

const int MAXN = 2005;
const int INF = 1e9;

vi G[MAXN];
bitset<MAXN> done;
bool paint[MAXN], requiresWhite[MAXN];
int n,m;

void bfs (int st, int d) {
    forn(i,n) done[i] = false;
    queue<ii> Q;
    done[st] = true;
    Q.push({st,0});

    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        if (e.snd == d) continue;

        requiresWhite[e.fst] = true;

        for (auto &i : G[e.fst]) {
            if (done[i]) continue;
            done[i] = true;
            Q.push({i,e.snd+1});
        }
    }
}

int dist (int st) {
    forn(i,n) done[i] = 0;
    queue<ii> Q;
    Q.push({st,0});
    done[st] = true;

    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        if (paint[e.fst] == 1) return e.snd;

        for (auto &i : G[e.fst])
            if (!done[i])
                done[i] = true, Q.push({i,e.snd+1});
    }

    return INF;
}

int main() {
    scanf("%d %d",&n,&m);

    forn(i,m) {
        int u,v; scanf("%d %d",&u,&v); u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    vector<ii> conditions;
    int k; scanf("%d",&k);
    forn(_,k) {
        int p,d; scanf("%d %d",&p,&d); p--;
        bfs(p,d);
        conditions.pb({p,d});
    }

    forn(i,n) if (!requiresWhite[i]) paint[i] = 1;

    bool posib = 1;
    for (auto &i : conditions) {
        if (dist(i.fst) != i.snd) {
            posib = false; break;
        }
    }

    if (!k) paint[0] = 1;

    if (posib) {
        printf("Yes\n");
        forn(i,n) printf("%d",paint[i]);
    }
    else printf("No\n");

    return 0;
}
