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

const int MAXN = 2005;

vi G[MAXN];
bitset<MAXN> mark;

int maxi = 1;
void dfs(int st, int lvl) {
    maxi = max(maxi,lvl);

    for (auto &i : G[st])
        dfs(i,lvl+1);
}

int main() {
    FAST_IO;

    int n; cin >> n;

    forn (i,n) {
        int x; cin >> x;
        if (x == -1) {mark[i] = true; continue;}
        G[x-1].pb(i);
    }

    forn (i,n) if (mark[i]) dfs(i,1);

    cout << maxi;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!