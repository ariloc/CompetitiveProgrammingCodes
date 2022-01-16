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

const int INF = 2e9;
const int MAXN = 1e5+5;

struct edge {
    int u,v;
    char c;
};

vi G[2*MAXN];
edge edges[MAXN];
int col[2*MAXN];
int n,m; vi cnt[2];
bool posib = true;

void dfs (int st, bool myCol = false) {
    col[st] = myCol;
    if (st < n) cnt[myCol].pb(st);

    for (auto &i : G[st]) {
        if (col[i] == -1) dfs(i,1^myCol);
        else if (myCol == col[i]) posib = false;
    }
}

int main() {
    scanf("%d %d",&n,&m);
    
    forn(i,m) {
        int u,v; char c;
        scanf("%d %d %c",&u,&v,&c); u--, v--;
        edges[i] = {u,v,c};
    }

    char COL[] = {'B','R'};
    int mini = INF; vi rta;
    forn(k,2) {
        forn(i,2*MAXN) G[i].clear(), col[i] = -1;
        posib = true;

        int dummies = MAXN;
        forn(i,m) {
            if (edges[i].c == COL[k]) {
                G[edges[i].u].pb(dummies);
                G[edges[i].v].pb(dummies);
                G[dummies].pb(edges[i].v);
                G[dummies].pb(edges[i].u);
                dummies++;
            }
            else {
                G[edges[i].u].pb(edges[i].v);
                G[edges[i].v].pb(edges[i].u);
            }
        }

        vi cnt_all[2];
        forn(i,n) if (col[i] == -1) {
            cnt[0].clear(), cnt[1].clear();
            dfs(i);
            if ((int)cnt[0].size() > (int)cnt[1].size())
                swap(cnt[0],cnt[1]);
            if ((int)cnt_all[0].size() > (int)cnt_all[1].size())
                swap(cnt_all[0],cnt_all[1]);
            for (auto &j : cnt[0]) cnt_all[0].pb(j);
            for (auto &j : cnt[1]) cnt_all[1].pb(j);
        }

        if (!posib) continue;

        if (mini == INF || (int)cnt_all[0].size() < mini)
            mini = (int)cnt_all[0].size(), rta = cnt_all[0];
        if ((int)cnt_all[1].size() < mini)
            mini = (int)cnt_all[1].size(), rta = cnt_all[1];
    }

    if (mini == INF) printf("-1");
    else {
        printf("%d\n",mini);
        for (auto &i : rta) printf("%d ",i+1);
    }

    return 0;
}