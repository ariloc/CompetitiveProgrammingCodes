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

const int MAXN = 250;
const int MAXE = 105;

vi G[MAXN];
bitset<MAXN> done;

void dfs(int st) {
    done[st] = true;

    for (auto &i : G[st])
        if (!done[i]) dfs(i);
}

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;

    bool existL = false;
    forn (i,n) {
        int k; cin >> k;
        if (k) existL = true;

        forn (j,k) {
            int x; cin >> x;
            x += MAXE;
            G[x].pb(i);
            G[i].pb(x);
        }
    }

    int cnt = 0;
    forn (i,n) if (!done[i]) {cnt++; dfs(i);}

    cout << cnt-existL;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!