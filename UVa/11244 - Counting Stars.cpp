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

const int X[] = {0,1,0,-1,1,-1,1,-1};
const int Y[] = {1,0,-1,0,1,1,-1,-1};
const int MAXN = 105;

char sky[MAXN][MAXN];

int main() {
    FAST_IO;

    int a,b;
    while (cin >> a >> b) {
        if (a == b and !a) break;
        forn(i,a) cin >> sky[i];

        int cnt = 0;
        forn(i,a) forn(j,b) {
            if (sky[i][j] == '*') {
                bool posib = true;
                forn(k,8) {
                    int tY = i+Y[k], tX = j+X[k];
                    if (tY < 0 or tX < 0 or tY >= a or tX >= b) continue;
                    if (sky[tY][tX] == '*') {posib = false; break;}
                }
                if (posib) cnt++;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
