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

const int MAXN = 1e5+2;
const int INF = 1e9+2;

vi G[MAXN];
bitset<MAXN> done,done1,done2;
int P[MAXN], dist[MAXN];

int far = -1, maxi = -1;
void dfs(int st, int lvl) {
    done[st] = true;

    if (lvl > maxi) {maxi = lvl; far = st;}

    for (auto &i : G[st])
        if (!done[i]) dfs(i,lvl+1);
}

void dfs2(int st, int lvl) {
    done2[st] = true;

    for (auto &i : G[st])
        if (!done2[i]) dfs2(i,lvl+1);

    dist[st] = lvl;
}

int main() {
    FAST_IO;

    memset(P,-1,sizeof(P));

    int n,k; cin >> n >> k;

    forn (i,n-1) {
        int a,b; cin >> a >> b;
        a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    dfs(0,0);

    queue<ii> Q;
    Q.push({far,0});
    done[far] = true;

    int maxD = -1, extr = -1;
    while (not Q.empty()) {
        auto e = Q.front(); Q.pop();

        if (e.snd > maxD) {maxD = e.snd; extr = e.fst;}

        for (auto &i : G[e.fst]) {
            if (done1[i]) continue;
            done1[i] = true;
            P[i] = e.fst;
            Q.push({i,e.snd+1});
        }
    }

    bool posib = true;
    int half = maxD / 2, ctr = -1;
    for (int i = extr, cnt = 0; i != -1; i = P[i], cnt++) {
        if (cnt == half) {ctr = i; break;}
    }

    dfs2(ctr,0);

    forn (i,n) {
        if (dist[i] == k) {if(G[i].size() != 1) posib = false;}
        else if (!dist[i]) {if (G[i].size() < 3) posib = false;}
        else if (G[i].size() < 4) posib = false;
    }

    if (posib) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
