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

const int X[] = {0,1,0,-1,1,-1,-1,1};
const int Y[] = {1,0,-1,0,1,1,-1,-1};

const int MAXN = 1005;

bool done[MAXN][MAXN];
int cx,cy,n;
bool posib = 0;

void dfs (int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= n) return;
    if (done[y][x]) return;
    done[y][x] = true;

    if (cy == y && cx == x)
        posib = true;

    forn(k,8) dfs(x+X[k], y+Y[k]);
}

int main() {
    scanf("%d",&n);

    int ax,ay; scanf("%d %d",&ax,&ay); ax--, ay--;
    int bx,by; scanf("%d %d",&bx,&by); bx--, by--;
    scanf("%d %d",&cx,&cy); cx--, cy--;

    forn(i,n) {
        done[ay][i] = done[i][ax] = true;
        if (ay-i >= 0 && ax-i >= 0) done[ay-i][ax-i] = true;
        if (ay+i < n && ax-i >= 0) done[ay+i][ax-i] = true;
        if (ay+i < n && ax+i < n) done[ay+i][ax+i] = true;
        if (ay-i >= 0 && ax+i < n) done[ay-i][ax+i] = true;
    }

    dfs(bx,by);

    printf("%s",posib ? "YES" : "NO");
    
    return 0;
}
