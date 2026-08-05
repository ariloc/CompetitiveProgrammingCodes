#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

int const MAXN = 1505;
int const SHIFT = 10000;
int const X[] = {0,1,0,-1};
int const Y[] = {1,0,-1,0};

struct cas {
    int q,i,j;

    bool operator< (const cas &o) const {
        if (q != o.q) return q < o.q;
        if (i != o.i) return i < o.i;
        return j < o.j;
    }
};

char maze[MAXN][MAXN];
int done[MAXN][MAXN];
int n,m;

int main() {
    FAST_IO;

    cin >> n >> m;
    forn(i,n) forn(j,m) cin >> maze[i][j];

    ii pos;
    forn(i,n) forn(j,m) if (maze[i][j] == 'S') pos = {i,j};
    maze[pos.fst][pos.snd] = '.';

    forn(i,n) forn(j,m) done[i][j] = -1;
 
    bool posib = false;
    queue<cas> Q;
    Q.push({SHIFT*SHIFT + SHIFT/2, pos.fst, pos.snd});
    done[pos.fst][pos.snd] = SHIFT*SHIFT + SHIFT/2;

    while (!Q.empty() && !posib) {
        auto e = Q.front(); Q.pop();

        //cerr << e.q << ' ' << e.i << ' ' << e.j << endl;

        forn(k,4) {
            int ti = e.i + X[k], tj = e.j + Y[k], tq = e.q;

            if (ti < 0) {tq -= SHIFT; ti=(ti+n)%n;}
            if (tj < 0) {tq--; tj=(tj+m)%m;}
            if (ti >= n) {tq += SHIFT; ti %= n;}
            if (tj >= m) {tq++; tj %= m;}
            if (maze[ti][tj] == '#') continue;
            cas cur = {tq,ti,tj};
            if (done[ti][tj] != -1) {
                if (done[ti][tj] == tq) continue;
                posib = true; break;
            }
            done[ti][tj] = tq;
            Q.push(cur);
        }
    }

    cout << (posib ? "Yes" : "No") << '\n';

    return 0;
}
