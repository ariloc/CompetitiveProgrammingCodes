#include<bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 9;
int const comb[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};

bool res[MAXN][MAXN];

// 0 -> no, 1 -> yes
int finished (vi &tablero) {
    forn(i,8) {
        if (tablero[comb[i][0]] == tablero[comb[i][1]] && tablero[comb[i][1]] == tablero[comb[i][2]] && tablero[comb[i][0]])
            return true;
    }
    return false;
}

// 1 -> X, 2 -> O, -1 -> tie
int solve(vi &tablero, bool turn) {
    if (finished(tablero))
        return (1^turn) + 1;

    bool moved = false;
    int ret = 1 + (1^turn);
    forn(i,9) {
        if (tablero[i]) continue;
        bool skip = false;
        forn(j,9) if (!tablero[j] && res[i][j]) skip = true;
        if (skip) continue;

        moved = true;

        tablero[i] = turn+1;
        int act = solve(tablero, 1^turn);
        tablero[i] = 0;

        if (act == (1 + turn))
            ret = 1 + turn;
        if (ret == 1 + (1^turn) && act == -1)
            ret = -1;
    }

    if (!moved)
        return -1;

    return ret;
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) {
        int a,b; cin >> a >> b;
        --a, --b;
        res[b][a] = true;
    }

    vi auxi = vi(9,0);
    int rta = solve(auxi,0);

    if (rta == -1) cout << "E\n";
    else if (rta == 1) cout << "X\n";
    else cout << "O\n";

    return 0;
}
