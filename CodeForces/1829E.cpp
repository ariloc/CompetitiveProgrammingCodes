#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int MAXN = 1005;

const int X[] = {0,1,0,-1};
const int Y[] = {1,0,-1,0};

int grid[MAXN][MAXN];
bool done[MAXN][MAXN];
int n,m;

int bfs (int y, int x) {
    queue<ii> Q;
    Q.push({y,x});
    int acc = 0;
    done[y][x] = true;

    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        acc +=  grid[e.fst][e.snd];

        forn(k,4) {
            int tY = e.fst + Y[k], tX = e.snd + X[k];
            if (tY > n || tY < 0 || tX > m || tX < 0) continue;
            if (grid[tY][tX] == 0) continue;
            if (done[tY][tX]) continue;
            done[tY][tX] = true;
            Q.push({tY,tX});
        }
    }
    return acc;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        cin >> n >> m;
        forn(i,n) forn(j,m) cin >> grid[i][j];

        forn(i,n) forn(j,m) done[i][j] = 0;

        int maxi = 0;
        forn(i,n) forn(j,m) if (grid[i][j] != 0 && !done[i][j]) maxi = max(maxi,bfs(i,j));

        cout << maxi << '\n';
    }
    
    return 0;
}
