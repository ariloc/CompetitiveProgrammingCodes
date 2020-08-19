#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 2e5+10;
const int INF = 1e9+20;

vi G[MAXN];
int cost[MAXN];
ll accum = 0;
bitset<MAXN> color,target,done;

ii dfs(int st, int minCost) {
    done[st] = true;

    // If I do it here, it's the same in any parent, so I get the minimum from here onwards
    minCost = min(minCost,cost[st]);
    cost[st] = minCost;

    ii need = {0,0}; // white | black
    for (auto &i : G[st]) {
        if (done[i]) continue;
        ii r = dfs(i,minCost);
        need.fst += r.fst; need.snd += r.snd; // adding yet to be shuffled
    }

    if (color[st] != target[st]) // count if I need to be changed
        if (target[st]) need.snd++;
        else need.fst++;

    // reset whenever I can, keeping vals minimal
    int toAcc = min(need.fst,need.snd);
    accum += (ll)toAcc*cost[st]*2;
    need.fst -= toAcc; need.snd -= toAcc;

    //cerr << need.fst << ' ' << need.snd <<' ' << st << endl;

    return need;
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn (i,n) {
        int b,c; cin >> cost[i] >> b >> c;
        color[i] = b; target[i] = c;
    }

    forn (i,n-1) {
        int a,b; cin >> a >> b;
        a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    ii got = dfs(0,INF);

    cout << (got.fst or got.snd ? -1 : accum);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!