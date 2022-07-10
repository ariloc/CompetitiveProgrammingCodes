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

const int MAXN = 105;

vi G[MAXN];
int inDegree[MAXN];

int main() {
    FAST_IO;

    while (true) {
        int n,m; cin >> n >> m;
        if (!n and !m) break;
        forn (i,n) {G[i].clear(); inDegree[i] = 0;}

        forn (i,m) {
            int a,b; cin >> a >> b; a--; b--;
            G[a].pb(b);
            inDegree[b]++;
        }

        queue<int> Q;
        vi topSort;
        forn (i,n) if (!inDegree[i]) Q.push(i);

        while (not Q.empty()) {
            auto e = Q.front(); Q.pop();
            topSort.pb(e+1);

            for (auto &i : G[e]) if (!(--inDegree[i])) Q.push(i);
        }

        for (auto &i : topSort) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
