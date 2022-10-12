
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
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef long double ld;

const int MAXN = 1005;
const int X[] = {0,-1,0,1};
const int Y[] = {1,0,-1,0};

struct pt {
    int x,y;
    pt(int x, int y) : x(x), y(y) {}
};

bool blocked[MAXN][MAXN][4];
bool done[MAXN][MAXN];
int cnt[MAXN*MAXN];
int prox_libre = 0;

void bfs (int x, int y) {
    queue<pt> Q;
    Q.push(pt(x,y));
    done[y][x] = true;
    
    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        cnt[prox_libre]++;
        
        forn(k,4) {
            int tX = e.x + X[k], tY = e.y + Y[k];
            if (tX < 0 || tY < 0 || tX >= MAXN || tY >= MAXN)
                continue;
            if (done[tY][tX])
                continue;
            if (blocked[e.y][e.x][k])
                continue;

            done[tY][tX] = true;
            Q.push(pt(tX,tY));
        }
    }

    prox_libre++;
}

void block (pt a, pt b) {
    if (a.x == b.x) {
        if (a.y > b.y) swap(a.y, b.y);
        while (a.y != b.y) {
            blocked[a.y][a.x-1][3] = true;
            blocked[a.y][a.x][1] = true;
            a.y++;
        }
    }
    else {
        if (a.x > b.x) swap(a.x, b.x);
        while (a.x != b.x) {
            blocked[a.y-1][a.x][0] = true;
            blocked[a.y][a.x][2] = true;
            a.x++;
        }
    }
}

int main() {
    int n; scanf("%d",&n);

    pt prv = {-1,-1};
    forn(i,n+1) {
        int x,y; scanf("%d %d",&x,&y);
        if (prv.x != -1) 
            block(prv, pt(x,y));
        prv = pt(x,y);
    }

    forn(i,MAXN) forn(j,MAXN)
        if (!done[j][i])
            bfs(i,j);

    int maxi = 0;
    forsn(i,1,prox_libre)
        maxi = max(maxi,cnt[i]);

    printf("%d", maxi);
    
    return 0;
}
