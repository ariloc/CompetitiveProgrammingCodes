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

const int MAXN = 4002;
const int X[] = {0,1,0,-1};
const int Y[] = {1,0,-1,0};

struct data{
    int x,y,steps;
};

bool restrict[MAXN][MAXN][4];
bool done[MAXN][MAXN];

bool valid (int &x, int &y, int &w, int &h) {
    if (x < 0 or y < 0) return false;
    if (x >= w or y >= h) return false;
    return true;
}

int bfs(int xSt, int ySt, int &width, int &height) {
    queue< data > Q;
    Q.push({xSt,ySt,0});
    done[ySt][xSt] = true;

    while (not Q.empty()) {
        auto e = Q.front(); Q.pop();

        if (e.x == width-1 and e.y == height-1)
            return e.steps;

        forn (i,4) {
            int tendX = e.x+X[i], tendY = e.y+Y[i];
            if (!valid(tendX,tendY,width,height)) continue;
            if (restrict[e.y][e.x][i]) continue;
            if (done[tendY][tendX]) continue;

            done[tendY][tendX] = true;

            Q.push({tendX,tendY,e.steps+1});
        }
    }

    return -1;
}

int main() {
    freopen("tabiques.in","r",stdin);
    freopen("tabiques.out","w",stdout);

    int a,b; scanf("%d %d",&a,&b);
    int t; scanf("%d",&t);

    forn (i,t) {
        int x,y,x2,y2; scanf("%d %d %d %d",&x,&y,&x2,&y2);
        if (x > x2) swap(x,x2);
        if (y > y2) swap(y,y2);
        if (x == x2)
            forsn (j,y,y2) {restrict[j][x][3] = true; restrict[j][x-1][1] = true;}
        if (y == y2)
            forsn(j,x,x2) {restrict[y][j][2] = true; restrict[y-1][j][0] = true;}
    }

    int v = bfs(0,0,a,b);
    if (v == -1) printf("imposible");
    else printf("%d",v);

    return 0;
}
