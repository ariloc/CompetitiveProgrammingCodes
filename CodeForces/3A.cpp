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

const int MAXN = 8; const int MAXM = 8;
const int X[] = {0,1,0,-1,  1,1,-1,-1};
const int Y[] = {1,0,-1,0,  1,-1,1,-1};
const string PUSH[] = {"U","R","D","L", "RU","RD","LU","LD"};

ii P[MAXN][MAXN]; int prevMove[MAXN][MAXN];
bool done[MAXN][MAXN];

int main() {
    FAST_IO;

    forn(i,MAXN) forn(j,MAXN) P[i][j] = {-1,-1};

    string a,b; cin >> a >> b;
    int x = a[0]-'a', y = a[1]-'0'-1, x2 = b[0]-'a', y2 = b[1]-'0'-1;

    queue<ii> Q; Q.push({x,y}); done[y][x] = true;
    while (not Q.empty()) {
        auto e = Q.front(); Q.pop();

        if (e.fst == x2 and e.snd == y2) break;

        forn(i,MAXM) {
            int tX = e.fst+X[i], tY = e.snd+Y[i];
            if (tX < 0 or tY < 0 or tX >= MAXN or tY >= MAXN) continue;
            if (done[tY][tX]) continue;
            done[tY][tX] = true;
            P[tY][tX] = {e.fst,e.snd}; prevMove[tY][tX] = i;
            Q.push({tX,tY});
        }
    }

    vector<string> path;
    for (ii i = {x2,y2}; ; i = P[i.snd][i.fst]) {
        path.pb(PUSH[prevMove[i.snd][i.fst]]);
        if (i.fst == x and i.snd == y) break;
    }

    path.pop_back();
    cout << path.size() << '\n';
    dforn (i,path.size()) cout << path[i] << '\n';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!