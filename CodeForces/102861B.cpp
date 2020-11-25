#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const int MAXN = 10;

bool board[MAXN][MAXN];

int main() {
    FAST_IO;

    int N; cin >> N;
    bool posib = true;
    forn(i,N) {
        int D,L,R,C; cin >> D >> L >> R >> C;
        if (D) {
            if (R+L-1 > MAXN) {posib = false; continue;}
            forsn(j,R,R+L)
                if (!board[j-1][C-1]) board[j-1][C-1] = true;
                else posib = false;
        }
        else {
            if (C+L-1 > MAXN) {posib = false; continue;}
            forsn(j,C,C+L)
                if (!board[R-1][j-1]) board[R-1][j-1] = true;
                else posib = false;
        }
    }

    cout << (posib ? 'Y' : 'N');

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
