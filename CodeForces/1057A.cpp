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

const int MAXN = 200005;

vi G[MAXN];
bitset<MAXN> done;
vi path; int n;

bool dfs(int st) {
    done[st] = true;

    bool me = false;
    for (auto &i : G[st])
        if (!done[i]) me |= dfs(i);

    if (st == n-1 or me) {
        path.pb(st+1);
        return true;
    }
    return false;
}

int main() {
    FAST_IO;

    cin >> n;

    forn(i,n-1) {
        int x; cin >> x; x--;
        G[x].pb(i+1);
    }

    dfs(0);
    dforn(i,path.size()) cout << path[i] << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!