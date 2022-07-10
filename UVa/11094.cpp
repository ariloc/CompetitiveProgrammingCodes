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

const int X[] = {0,1,0,-1};
const int Y[] = {1,0,-1,0};
const int MAXN = 50;

char land[MAXN][MAXN];
bool done[MAXN][MAXN];

int n,m;
char LANDCHAR;
int bfs(int y, int x) {
    int cnt = 0;
    queue<ii> Q; Q.push({y,x});
    done[y][x] = true;

    while (not Q.empty()) {
        auto e = Q.front(); Q.pop(); cnt++;

        forn(i,4) {
            int tY = e.fst+Y[i], tX = e.snd+X[i];
            tX %= n; tX = (tX+n)%n; // wrap around
            if (tY >= m or tY < 0) continue;
            if (done[tY][tX]) continue;
            if (land[tY][tX] != LANDCHAR) continue;
            done[tY][tX] = true;
            Q.push({tY,tX});
        }
    }
    return cnt;
}

int main() {
    FAST_IO;

    while (cin >> m >> n) {
        memset(done,0,sizeof(done));
        forn(i,m) cin >> land[i];
        ii me; cin >> me.fst >> me.snd;
        LANDCHAR = land[me.fst][me.snd];
        bfs(me.fst,me.snd);
        int maxi = 0;
        forn(i,m) forn(j,n) if (!done[i][j] and land[i][j] == LANDCHAR) maxi = max(maxi,bfs(i,j));
        cout << maxi << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
