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

const int MAXN = 102;
char table[MAXN][MAXN];

void pregen() {
    forn (i,MAXN)
        forn (j,MAXN) {
            if (j & 1) table[i][j] = 'W';
            else table[i][j] = 'B';

            if (i & 1)
                if (table[i][j] == 'W') table[i][j] = 'B';
                else table[i][j] = 'W';
        }
}

int main() {
    FAST_IO;

    pregen();

    int t; cin >> t;

    forn (i,t) {
        int r,c; cin >> r >> c;

        if (!(r & 1) or !(c & 1)) table[0][1] = 'B';

        forn (j,r) {
            forn (k,c) cout << table[j][k];
            cout << '\n';
        }

        table[0][1] = 'W';
    }

    return 0;
}