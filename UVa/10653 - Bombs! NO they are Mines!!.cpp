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

const int MAXN = 1005;
const int X[] = {0,1,0,-1};
const int Y[] = {1,0,-1,0};

bool land[MAXN][MAXN];

int main() {
    FAST_IO;

    int r,c;
    while (cin >> r >> c) {
        if (!r and !c) break;
        memset(land,0,sizeof(land));
        int R; cin >> R;
        forn(i,R) {
            int rn,bmb; cin >> rn >> bmb;
            forn (j,bmb) {
                int cn; cin >> cn;
                land[rn][cn] = true;
            }
        }

        int ir,ic; cin >> ir >> ic;
        int dr,dc; cin >> dr >> dc;

        queue<pair<ii,int>> Q; Q.push({{ir,ic},0}); land[ir][ic] = true;
        int v = -1;
        while (not Q.empty()) {
            auto e = Q.front(); Q.pop();

            if (e.fst.fst == dr and e.fst.snd == dc) {v = e.snd; break;}
            forn(k,4) {
                int tY = Y[k]+e.fst.fst, tX = X[k]+e.fst.snd;
                if (tY < 0 or tX < 0 or tY >= r or tX >= c) continue;
                if (land[tY][tX]) continue;
                land[tY][tX] = true;
                Q.push({{tY,tX},e.snd+1});
            }
        }

        cout << v << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
