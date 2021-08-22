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
const int INF = 1e9+5;

vi G[MAXN];
int val[MAXN];
bitset<MAXN> done,done2;

bool posib = true;
ll rta = 0;

void dfs (int st, int maxi) {
    done[st] = true;

    if (val[st] != -1) if (val[st] < maxi) {posib = false; return;}

    int antM = maxi;
    maxi = max(maxi,val[st]);

    int mini = INF;
    for (auto &i : G[st])
        if (!done[i]) {
            dfs(i,maxi);
            mini = min(mini,val[i]);
        }

    if (val[st] == -1) val[st] = (mini == INF ? antM : mini);
}

void dfs2 (int st, int maxi) {
    done2[st] = true;

    rta += val[st]-maxi;

    maxi = max(maxi,val[st]);

    for (auto &i : G[st]) if (!done2[i]) dfs2(i,maxi);
}

int main() {
    FAST_IO;

    int N; cin >> N;

    forn (i,N-1) {
        int x; cin >> x; x--;
        G[x].pb(i+1);
        G[i+1].pb(x);
    }

    forn (i,N) cin >> val[i];

    dfs(0,0); if (!posib) {cout << -1; return 0;}
    dfs2(0,0);

    cout << rta;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!