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

const int MAXN = 305;
int grid[MAXN][MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {

        int n,m; cin >> n >> m;

        bool valid = true;
        forn(j,n) forn(k,m) {
            int x; cin >> x;
            if (x > 4) valid = false;
            if (x > 3 and (!j or !k or k == m-1 or j == n-1)) valid = false;
            if (x > 2 and ((!j and !k) or (!j and k == m-1) or (j == n-1 and !k) or (j == n-1 and k == m-1)))
                valid = false;
        }

        if (!valid) cout << "NO\n";
        else{
            cout << "YES\n";
            forn(j,n) forn(k,m) grid[j][k] = 4;
            forn(k,m) grid[0][k] = grid[n-1][k] = 3;
            forn(j,n) grid[j][0] = grid[j][m-1] = 3;
            grid[0][0] = grid[0][m-1] = grid[n-1][0] = grid[n-1][m-1] = 2;

            forn(j,n) {forn(k,m) cout << grid[j][k] << ' '; cout << '\n';}
        }

    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!