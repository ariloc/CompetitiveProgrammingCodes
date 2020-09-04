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
const ll INF = 1e18;

struct edges{
    int v; ll w;
};

bitset<MAXN> done,done2;
vector<edges> G[MAXN];
ll maxW = 0;


void dfs (int st, ll w){
    done[st] = true;
    maxW = max(maxW,w);

    for (auto &i : G[st])
        if (!done[i.v])
            dfs(i.v,i.w+w);
}

int main() {
    FAST_IO;

    int n; cin >> n;
    ll sum = 0;
    forn (i,n-1) {
        int a,b,w; cin >> a >> b >> w; a--; b--;
        sum += w;
        G[a].pb({b,w});
        G[b].pb({a,w});
    }

    dfs(0,0);

    cout << sum*2-maxW;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
