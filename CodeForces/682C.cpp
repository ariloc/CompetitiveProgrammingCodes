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

struct edge {
    int v,w;
};

int dist[MAXN], hijos[MAXN];
vector<edge> G[MAXN];
bitset<MAXN> done,sad,done2;

int dfs (int st, ll acc) {
    done[st] = true;

    if (acc > dist[st]) sad[st] = true;

    int below = 0;
    for (auto &i : G[st])
        if (!done[i.v]) below += dfs(i.v,(acc+i.w < 0 ? 0 : acc+i.w));

    //cout << below << ' ' << hijos[st] << ' ' << st << endl;

    return hijos[st] = below+1;
}

int accum = 0;
void dfs2 (int st) {
    done2[st] = true;

    if (sad[st]) {accum += hijos[st]; return;}
    for (auto &i : G[st]) if (!done2[i.v]) dfs2(i.v);
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn (i,n) cin >> dist[i];
    forn (i,n-1) {
        int a,l; cin >> a >> l;
        G[i+1].pb({a-1,l});
        G[a-1].pb({i+1,l});
    }

    dfs(0,0);
    dfs2(0);

    cout << accum;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!