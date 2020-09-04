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
const int MAXN = 1005;

struct monster {
    int x,y,acc;
};

string lab[MAXN];
bool doneM[MAXN][MAXN];
bool doneP[MAXN][MAXN];
int moment[MAXN][MAXN];
ii P[MAXN][MAXN];
int N,M;

bool valid(int &x, int &y) {
    if (x < 0 or y < 0) return false;
    if (x >= M or y >= N) return false;
    return true;
}

int main() {
    FAST_IO;

    cin >> N >> M;
    int x,y;

    forn (i,N) cin >> lab[i];

    // Mejor distancia de un monstruo
    queue<monster> Q;
    forn (i,N)
        forn (j,M) {
            if (lab[i][j] == 'M') Q.push({j,i,0});
            if (lab[i][j] == 'A') {x = j; y = i;}
        }

    while (not Q.empty()) {
        monster e = Q.front(); Q.pop();

        moment[e.y][e.x] = e.acc;

        forn (i,4) {
            int tendX = e.x+X[i], tendY = e.y+Y[i];
            if (!valid(tendX,tendY)) continue;
            if (doneM[tendY][tendX]) continue;
            if (lab[tendY][tendX] == '#') continue;
            doneM[tendY][tendX] = true;

            Q.push({tendX,tendY,e.acc+1});
        }
    }

    // Mejor distancia de persona
    queue<monster> QA;
    QA.push({x,y});

    ii posib = {-1,-1};
    while (not QA.empty()) {
        monster e = QA.front(); QA.pop();

        forn (i,4) {
            int tendX = e.x+X[i], tendY = e.y+Y[i];
            if (!valid(tendX,tendY)) {posib = {e.x,e.y}; break;}
            if (doneP[tendY][tendX]) continue;
            if (lab[tendY][tendX] != '.') continue;
            if (moment[tendY][tendX] <= e.acc+1)
                if (doneM[tendY][tendX]) continue;
            doneP[tendY][tendX] = true;
            P[tendX][tendY] = {e.x,e.y};

            QA.push({tendX,tendY,e.acc+1});
        }
    }
    P[x][y] = {-1,-1};

    if (posib.fst == -1) cout << "NO";
    else {
        string way;

        for (ii o = posib; o.fst != -1; o = P[o.fst][o.snd]) {
            ii prev = P[o.fst][o.snd];
            if (prev.fst == -1) break;
            if (prev.fst > o.fst) way.pb('L');
            else if (prev.fst < o.fst) way.pb('R');
            else if (prev.snd > o.snd) way.pb('U');
            else way.pb('D');
        }

        cout << "YES\n" << way.size() << '\n';
        dforn(i,way.size()) cout << way[i];
    }

    return 0;
}
