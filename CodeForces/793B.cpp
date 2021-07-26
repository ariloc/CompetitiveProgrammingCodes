#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int X[] = {1,0,-1,0};
const int Y[] = {0,-1,0,1};
const int MAXN = 1005;

struct estado {
    ii pt;
    int direct;
    int turns;
};

char mat[MAXN][MAXN];
bool reach[MAXN][MAXN][4][3]; // partiendo de la casilla, habiendo llegado con un mov, y habiendo usado una cantidad de turns

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,n) cin >> mat[i];

    queue<estado> Q;
    ii nd = {-1,-1};
    forn(i,n) forn(j,m) {
        if (mat[i][j] == 'S') 
            forn(k,4) Q.push({{i,j},k,0}), reach[i][j][k][0] = true;
        if (mat[i][j] == 'T') nd = {i,j};
    }

    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        forn(k,4) {
            int tY = e.pt.fst + X[k], tX = e.pt.snd + Y[k];
            int newT = e.turns + (k != e.direct);

            if (newT > 2) continue;
            if (tY >= n || tX >= m || tY < 0 || tX < 0) continue;
            if (reach[tY][tX][k][newT]) continue;
            if (mat[tY][tX] == '*') continue;
            
            reach[tY][tX][k][newT] = true;
            Q.push({{tY,tX},k,newT});
        }
    }

    bool posib = false;
    forn(i,4) forn(j,3) posib |= reach[nd.fst][nd.snd][i][j];

    cout << (posib ? "YES" : "NO");

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!