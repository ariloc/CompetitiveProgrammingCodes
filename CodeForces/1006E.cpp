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

const int MAXN = 2e5+5;

vi G[MAXN];
int tout[MAXN],posic[MAXN],seq[MAXN],ind = 0,timeV = 0;

void dfs(int st) {
    posic[st] = ind;
    seq[ind++] = st;
    for(auto &i : G[st]) dfs(i);
    tout[st] = timeV++;
}

int main() {
    FAST_IO;

    int n,q; cin >> n >> q;
    forn(i,n-1) {
        int x; cin >> x;
        G[x-1].pb(i+1);
    }

    forn(i,n) sort(all(G[i]));

    dfs(0);

    forn(i,q) {
        int u,k; cin >> u >> k; u--; k--;
        if (posic[u]+k >= ind or tout[seq[posic[u]+k]] > tout[u]) cout << "-1\n";
        else cout << seq[posic[u]+k]+1 << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
