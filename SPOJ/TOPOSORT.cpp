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

const int MAXN = 10005;

vi G[MAXN];
int inDegree[MAXN];

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;

    forn (i,m) {
        int a,b; cin >> a >> b; a--; b--;
        G[a].pb(b);
        inDegree[b]++;
    }

    priority_queue<int> Q;
    vi topSort;
    forn (i,n) if (!inDegree[i]) Q.push(-i);

    while (not Q.empty()) {
        auto e = Q.top(); Q.pop(); e = abs(e);
        topSort.pb(e);

        for (auto &i : G[e])
            if(!(--inDegree[i])) Q.push(-i);
    }

    if ((int)topSort.size() != n) cout << "Sandro fails.";
    else for (auto &i : topSort) cout << i+1 << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
