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

const int X[] = {0,1,0,-1};
const int Y[] = {1,0,-1,0};
const int MAXN = 52;

char maze[MAXN][MAXN];
bool done[MAXN][MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        int n,m; cin >> n >> m;

        int reached = 0;
        forn(j,n) forn(k,m) done[j][k] = false;
        forn(j,n) forn(k,m) {cin >> maze[j][k]; if (maze[j][k] == 'G') reached++;}

        forn(j,n) forn(k,m)
            if (maze[j][k] == 'B')
                forn (o,4) {
                    int tX = k+X[o], tY = j+Y[o];
                    if (tX < 0 or tY < 0 or tX >= m or tY >= n) continue;
                    if (maze[tY][tX] != '.') continue;
                    maze[tY][tX] = '#';
                }

        //forn (j,n) {forn(k,m) cout << maze[j][k]; cout << endl;}

        bool posib = true;
        queue<ii> Q;
        if (maze[n-1][m-1] != '#') Q.push({m-1,n-1});
        done[n-1][m-1] = true;

        while (not Q.empty()) {
            auto e = Q.front(); Q.pop();

            forn (j,4) {
                int tX = e.fst+X[j], tY = e.snd+Y[j];
                if (tX < 0 or tY < 0 or tX >= m or tY >= n) continue;
                if (maze[tY][tX] == '#') continue;
                if (done[tY][tX]) continue;
                if (maze[tY][tX] == 'B') {posib = false; break;}
                if (maze[tY][tX] == 'G') reached--;
                done[tY][tX] = true;
                Q.push({tX,tY});
            }
        }

        if (reached or !posib) cout << "No\n";
        else cout << "Yes\n";
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!