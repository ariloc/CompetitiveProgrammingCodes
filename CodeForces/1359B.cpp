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

const int MAXN = 1000;

char pave[MAXN][MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        int n,m,x,y; cin >> n >> m >> x >> y;
        forn(j,n) forn(k,m) cin >> pave[j][k];

        int sum = 0;
        forn(j,n) forn(k,m) {
            if (pave[j][k] == '*') continue;
            if (k+1 >= m) {pave[j][k] = '*'; sum += x; continue;}
            if (y < (x*2))
                if (pave[j][k+1] == '.') {pave[j][k] = pave[j][k+1] = '*'; sum += y; continue;}
            pave[j][k] = '*'; sum += x;
        }

        cout << sum << '\n';
    }



    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!