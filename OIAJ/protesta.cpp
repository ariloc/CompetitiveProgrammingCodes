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

const int MAXN = 2e3+2;
const int INF = 1e9+2;
const int X[] = {0,1,0,-1}; /// N,E,S,O
const int Y[] = {1,0,-1,0};

struct data {
    int x,y;
    bool vert; // true -> vengo N o S, false -> vengo E u O
    int accum;
};

bool calles[MAXN][MAXN], done[MAXN][MAXN][2];
int N,x1,Y1,x2,y2,E,XA,YA;
ii P[MAXN][MAXN][2];

bool valid (int &x, int &y) {
    if (x < 0 or y < 0) return false;
    if (x >= XA or y >= YA) return false;
    return true;
}

int bfs() {
    queue< data > Q;
    done[x1][Y1][0] = true;
    done[x1][Y1][1] = true;
    P[x1][Y1][0] = {-1,-1};
    P[x1][Y1][1] = {-1,-1};
    Q.push({x1,Y1,true,0}); // kickstart
    Q.push({x1,Y1,false,0});

    int r = INF; bool side = 0;
    while (not Q.empty()) {
        auto e = Q.front(); Q.pop();

        if (e.x == x2 and e.y == y2) {
            if (e.accum < r) {
                r = e.accum;
                side = e.vert;
            }
            if (done[e.x][e.y][0] and done[e.x][e.y][1]) return side;
            continue;
        }

        int allowed = -1;
        if (e.vert) if (e.y & 1) allowed = 1; else allowed = 3;
        else if (e.x & 1) allowed = 0; else allowed = 2;

        for (int x = e.x+X[allowed], y = e.y+Y[allowed]; ;x += X[allowed], y += Y[allowed]) {
            if (!valid(x,y)) break;
            if (done[x][y][e.vert]) break;
            if (calles[x][y]) break;
            P[x][y][e.vert] = {e.x,e.y};
            done[x][y][e.vert] = true;
            Q.push({x,y,!e.vert,e.accum+1});
        }
    }
    return (r == INF ? -1 : side);
}

int main() {
    freopen("protesta.in","r",stdin);
    freopen("protesta.out","w",stdout);

    memset(P,-1,sizeof(P));

    scanf("%d",&N);
    if (!(N%2)) XA = YA = N/2;
    else {XA = N/2; YA = N/2+1;}

    scanf("%d %d %d %d",&x1,&Y1,&x2,&y2);
    if (x1 & 1) swap(x1,Y1); if (x2 & 1) swap(x2,y2);
    x1 /= 2; x2 /= 2; Y1 = (Y1+1)/2; y2 = (y2+1)/2;
    x1--; x2--; Y1--; y2--; // coords normales

    scanf("%d",&E);
    forn(i,E) {
        int x,y;
        scanf("%d %d",&x,&y);
        if (x % 2) swap(x,y);
        x /= 2; y = (y+1)/2; // coords normales
        x--; y--;
        calles[x][y] = true;
    }

    int win = bfs(); bool winS;
    if (win == -1) {printf("0"); return 0;}
    else winS = win;

    vi street;
    ii prev = {-1,-1};
    for (ii i = {x2,y2}; i.fst != -1; i = P[i.fst][i.snd][winS]) {
        if (prev.fst != -1) {
            if (i.snd == prev.snd) street.pb(((i.snd+1)*2)-1);
            else street.pb((i.fst+1)*2);
        }
        winS = !winS;
        prev = {i.fst,i.snd};
    }

    printf("1\n");
    printf("%d\n",(int)street.size());
    dforn (i,street.size()) printf("%d\n",street[i]);

    return 0;
}
