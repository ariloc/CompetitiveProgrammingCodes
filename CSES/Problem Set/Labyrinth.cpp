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
const char MOV[] = {'D','R','U','L'};

char grid[MAXN][MAXN];
bool done[MAXN][MAXN];
int P[MAXN][MAXN];

int main() {
    FAST_IO;

    memset(P,-1,sizeof(P));

    int n,m; cin >> n >> m;
    forn(i,n) cin >> grid[i];
    ii st = {-1,-1}, nd = {-1,-1};
    forn(i,n) forn(j,m) if (grid[i][j] == 'A') {st = {i,j}; break;}
    forn(i,n) forn(j,m) if (grid[i][j] == 'B') {nd = {i,j}; break;}

    queue<ii> Q;
    Q.push(st); done[st.fst][st.snd] = true; P[st.fst][st.snd] = -1;
    while (not Q.empty()) {
        auto e = Q.front(); Q.pop();
        forn(k,4) {
            int tX = e.snd+X[k], tY = e.fst+Y[k];
            if (tX < 0 or tY < 0 or tX >= m or tY >= n) continue;
            if (done[tY][tX]) continue;
            done[tY][tX] = true;
            if (grid[tY][tX] == '#') continue;
            P[tY][tX] = (k+2)%4; // movimiento para ir
            Q.push({tY,tX});
        }
    }

    if (P[nd.fst][nd.snd] == -1) {cout << "NO"; return 0;}

    int x = nd.snd, y = nd.fst;
    vector<char> path;
    for (; P[y][x] != -1; ) {
        path.pb(MOV[(P[y][x]+2)%4]);
        int mymov = P[y][x];
        y += Y[mymov]; x += X[mymov];
    }

    cout << "YES\n" << path.size() << '\n';
    dforn(i,path.size()) cout << path[i];

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
