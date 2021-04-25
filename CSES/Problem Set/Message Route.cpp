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

vi G[MAXN];
int P[MAXN];
bitset<MAXN> done;

int main() {
    FAST_IO;

    memset(P,-1,sizeof(P));

    int n,m; cin >> n >> m;

    forn (i,m) {
        int a,b; cin >> a >> b; a--; b--;
        G[a].pb(b);
        G[b].pb(a);
    }

    queue<ii> Q;
    Q.push({0,0});
    done[0] = true;
    while (not Q.empty()) {
        auto e = Q.front(); Q.pop();

        if (e.fst == n-1) break;

        for (auto &i : G[e.fst]) {
            if (done[i]) continue;
            done[i] = true;
            P[i] = e.fst;
            Q.push({i,e.snd+1});
        }
    }

    vi path;
    for (int i = n-1; i != -1; i = P[i]) path.pb(i+1);

    if (path.size() < 2) {cout << "IMPOSSIBLE"; return 0;}
    cout << path.size() << '\n';
    dforn (i,path.size()) cout << path[i] << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
