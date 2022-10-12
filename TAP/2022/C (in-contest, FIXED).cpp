
#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define pb push_back
#define fst first
#define snd second
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int MAXN = 1e3+5;
const int X[] = {-1,0,1,0};
const int Y[] = {0,1,0,-1};

struct pt {
    int x,y;
    pt(int x, int y) : x(x), y(y) {}
};

bool blocked[MAXN][MAXN][4];
bool done[MAXN][MAXN];
int color[MAXN][MAXN], cantColor[MAXN*MAXN];
int prox_libre = 0;
vector<pt> pts;

void block(int x, int y, int a, int b){
    if(x==a){
        if(b<y){
            swap(b, y);
        }
        for(int j=y; j<b; ++j){
            //(i-1, j)  (i, j)
            blocked[x-1][j][2] = true;
            blocked[x][j][0] = true;
        }
    }
    else{
        if(a<x){
            swap(a, x);
        }
        for(int j=x; j<a; ++j){
            //cerr << j << ' ' << y-1 << ' ' << "!!!!" << endl;
            //(y-1, j), (y, j)
            blocked[j][y-1][1] = true;
            blocked[j][y][3] = true;
        }  
    }
}

void bfs (int x, int y) {
    queue<pt> Q;
    Q.push({x,y});
    done[x][y] = true;

    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        color[e.x][e.y] = prox_libre;

        forn(k,4) {
            int tX = e.x + X[k], tY = e.y + Y[k];
            if (tX < 0 || tY < 0 || tX >= MAXN || tY >= MAXN)
                continue;
            if (done[tX][tY])
                continue;
            if (blocked[e.x][e.y][k])
                continue;
            Q.push({tX,tY});
            done[tX][tY] = true;
        }
    }
}

int main() {
    FAST_IO;

    int n; cin >> n;
    
    forn(i,n+1) {
        int x,y; cin >> x >> y;
        pts.pb({x,y});
    }

    forsn(i,1,n+1) {
        pt a = pts[i-1], b = pts[i];
        block(a.x,a.y,b.x,b.y);
    }

    forn(i,MAXN) forn(j,MAXN)
        if (!done[i][j]) {
            bfs(i,j);
            prox_libre++;
        }

    //cerr << blocked[1][0][1] << "!!" << endl;


    forn(i,MAXN) forn(j,MAXN) {
        cantColor[color[i][j]]++;
    }

    /*
    forn(i,10) {
        forn(j,10) cerr << color[i][j] << ' ';
        cerr << endl;
    }
    */

    int maxi = 0;
    forn(i,prox_libre) {
        if (i == color[0][0]) continue;
        maxi = max(maxi,cantColor[i]);
    }

    cout << maxi;

    return 0;
}
