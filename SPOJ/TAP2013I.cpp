#include <bits/stdc++.h>
 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) err << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int X[] = {0,-1,0,1};
const int Y[] = {1,0,-1,0};
const int MAXN = 505;
const int INF = 2e9;

struct stat {
    int x,y,t;
    stat(){}
    stat(int a, int b, int c) : x(a), y(b), t(c) {}

    bool operator< (const stat &o) const {
        return t < o.t;
    }
};

int grid[MAXN][MAXN];
int D[MAXN][MAXN];

int main() {
    int r,c; scanf("%d %d",&r,&c);
    
    forn(i,r) forn(j,c)
        D[i][j] = -INF;
    
    forn(i,r) forn(j,c)
        scanf("%d",&grid[i][j]);

    priority_queue<stat> Q;
    Q.push(stat(c-1,r-1,grid[r-1][c-1]-1));
    D[r-1][c-1] = grid[r-1][c-1]-1;

    while (!Q.empty()) {
        auto e = Q.top(); Q.pop();

        if (e.t != D[e.y][e.x]) continue;
        
        forn(k,4) {
            int tY = e.y + Y[k], tX = e.x + X[k];
            if (tY < 0 || tX < 0 || tY >= r || tX >= c)
                continue;

            int arrive = min(D[e.y][e.x]-1, grid[tY][tX]-1);
            if (arrive <= D[tY][tX]) continue;

            D[tY][tX] = arrive;
            Q.push(stat(tX,tY,arrive));
        }
    }

    printf("%d", max(D[0][0],-1));

    return 0;
}
