#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
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

const int MAXN = 1005;
const int DIFH = 150;
const int X[] = {1,0,-1,0};
const int Y[] = {0,-1,0,1};

ll D[MAXN][MAXN];
int mapita[MAXN][MAXN];
int n,m;

struct dijk {
    ll w;
    int x,y;

    bool operator< (const dijk &o) const { // dijkstra
        return w > o.w;
    }
};

ll calc (int x1, int y1, int x2, int y2) {
    ll aux1 = mapita[y1][x1], aux2 = mapita[y2][x2];
    ll dif = aux1 - aux2;
    return dif * dif;
}

void dijkstra() {
    forn(i,n) forn(j,m) D[i][j] = -1;
    D[0][0] = 0;

    priority_queue<dijk> Q;
    Q.push({0,0,0});

    while (!Q.empty()) {
        auto e = Q.top(); Q.pop();

        forn(k,4) {
            int tX = e.x + X[k], tY = e.y + Y[k];
            if (tX < 0 || tY < 0 || tX >= m || tY >= n)
                continue;
            if (abs(mapita[e.y][e.x] - mapita[tY][tX]) > DIFH)
                continue;

            ll precalc = D[e.y][e.x] + calc(e.x,e.y,tX,tY);
            if (D[tY][tX] == -1 || D[tY][tX] > precalc) {
                D[tY][tX] = precalc;
                Q.push({D[tY][tX], tX, tY});
            }
        }
    }
}

long long trekking(vector<vector<int>> &mapa) {
    n = (int)mapa.size(), m = (int)mapa[0].size();
    forn(i,n) forn(j,m)
        mapita[i][j] = mapa[i][j];

    dijkstra();
    return D[n-1][m-1];
}
