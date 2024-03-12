#include<bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 2e5+5;

vi G[MAXN];
bitset<MAXN> done, col, done2;
int n;
ll rta = 0;

void bipart(int st, bool cur = 0) {
    done[st] = true;
    col[st] = cur;

    for (auto &i : G[st])
        if (!done[i])
            bipart(i,cur^1);
}

int dfs(int st) {
    done2[st] = true;
    
    int child = 0;
    for (auto &i : G[st])
        if (!done2[i]) {
            int act = dfs(i);
            child += act;
            rta += act * (ll)(n-act);
        }

    return child+1;
}

int main() {
    FAST_IO;
    cin >> n;

    forn(i,n-1) {
        int u,v; cin >> u >> v; --u, --v;
        G[u].pb(v), G[v].pb(u);
    }

    bipart(0);
    dfs(0);

    ll evcnt = 0;
    forn(i,n) if (col[i]) evcnt++;

    ll oddpath = evcnt * (ll)(n-evcnt);

    cout << (rta-oddpath)/2 + oddpath;
    
    return 0;
}
