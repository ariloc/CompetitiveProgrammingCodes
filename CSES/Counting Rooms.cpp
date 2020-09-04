#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const int MAXN = 1005;
const int X[] = {0,1,0,-1};
const int Y[] = {1,0,-1,0};

char grid[MAXN][MAXN];
bool done[MAXN][MAXN];

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,n) cin >> grid[i];

    int cnt = 0;
    forn(i,n) forn(j,m) if (!done[i][j] and grid[i][j] != '#') {
        cnt++;
        queue<ii> Q;
        Q.push({j,i});
        while (not Q.empty()) {
            auto e = Q.front(); Q.pop();
            forn(k,4) {
                int tX = e.fst+X[k], tY = e.snd+Y[k];
                if (tX < 0 or tY < 0 or tX >= m or tY >= n) continue;
                if (done[tY][tX]) continue;
                done[tY][tX] = true;
                if (grid[tY][tX] == '#') continue;
                Q.push({tX,tY});
            }
        }
    }

    cout << cnt;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
