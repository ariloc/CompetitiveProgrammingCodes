#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 1e3+2;
const int X[] = {1,0,-1,0};
const int Y[] = {0,-1,0,1};
const char dirInv[] = {'L','D','R','U'}; // direction inverted from movement to where I came
const char dir[] = {'R','U','L','D'}; // normal direction

ii input[MAXN][MAXN];
char rta[MAXN][MAXN];

bool valid(int &x, int &y) {
    if (x < 0 or y < 0) return false;
    if (x >= MAXN or y >= MAXN) return false;
    return true;
}

bool pairwiseConnect(int &y, int &x) {
    bool done = false;
    forn (i,4) {
        int tendX = x+X[i], tendY = y+Y[i];
        if (!valid(tendX,tendY)) continue;
        if (input[y][x] != input[tendY][tendX]) continue;
        rta[tendY][tendX] = dirInv[i];
        rta[y][x] = dir[i];
        done = true; break;
    }
    return done;
}

void bfs(int &stY, int &stX) {
    queue<ii> Q;
    rta[stY][stX] = 'X';
    Q.push({stX,stY});

    while (not Q.empty()) {
        auto e = Q.front(); Q.pop();

        forn (i,4) {
            int tendX = e.fst+X[i], tendY = e.snd+Y[i];
            if (!valid(tendX,tendY)) continue;
            if (rta[tendY][tendX]) continue;
            if (input[e.snd][e.fst] != input[tendY][tendX]) continue;
            rta[tendY][tendX] = dirInv[i];
            Q.push({tendX,tendY});
        }
    }
}

int main() {
    FAST_IO;

    int N;
    cin >> N;
    forn (i,N) {
        forn (j,N) {
            ii x;
            cin >> x.fst >> x.snd;
            input[i][j] = x;
        }
    }

    forn (i,N) {
        forn (j,N) {
            if (rta[i][j]) continue;
            if (input[i][j].fst != -1)
                {if (input[i][j] == (ii){i+1,j+1}) bfs(i,j);}
            else if (!pairwiseConnect(i,j)) {cout << "INVALID"; return 0;}
        }
    }

    forn (i,N)
        forn (j,N)
            if (!rta[i][j])
                {cout << "INVALID"; return 0;}

    cout << "VALID\n";
    forn (i,N) {
        forn (j,N)
            cout << rta[i][j];
        cout << '\n';
    }

    return 0;
}