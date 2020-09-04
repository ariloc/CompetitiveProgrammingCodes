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

const int MAXN = 205;

bool ady[MAXN][MAXN];
int col[MAXN];
int bl = 0, wh = 0, n;
bool bipart = true;

void dfs(int st, bool myCol) {
    if (col[st] != -1) {
        if (col[st] != myCol) bipart = false;
        return;
    }
    col[st] = myCol;

    if (myCol) bl++;
    else wh++;
    forn (i,n)
        if (ady[i][st]) dfs(i,!myCol);
}

int main() {
    FAST_IO;

    int m; cin >> m;

    forn(i,m) {
        cin >> n;
        forn(j,n) col[j] = -1;
        forn(j,n) forn(k,n) ady[j][k] = false;
        forn(j,n) {
            int e; cin >> e;
            forn(k,e) {int x; cin >> x; x--; ady[x][j] = ady[j][x] = true;}
        }

        ll rta = 0;
        forn(j,n) if (col[j] == -1) {
            bl = wh = 0; bipart = true; dfs(j,0);
            if (bipart) rta += max(bl,wh);
        }

        cout << rta << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
