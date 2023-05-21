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

const int MAXN = 1e5+5;

bitset<MAXN> cat,done;
vi G[MAXN];
int n,m;

int dfs(int st, int cnt) {
    done[st] = true;

    if (cnt > m) return 0;

    int sum = 0; bool hasChildren = false;
    for (auto &i : G[st])
        if (!done[i]) {
            hasChildren = true;
            sum += dfs(i,(cat[i] ? cnt+(int)cat[i] : 0));
        }

    return sum + (int)(!hasChildren);
}

int main() {
    FAST_IO;

    cin >> n >> m;

    forn(i,n) {int x; cin >> x; cat[i] = x;}
    forn(i,n-1) {
        int a,b; cin >> a >> b; a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    cout << dfs(0,(int)cat[0]);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
