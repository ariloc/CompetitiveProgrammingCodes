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

const int MAXN = 1010;
const int MAXTM = 16; // máximos tipos de movimientos
const int MAXIMP = 13;
const int INF = 2e9+2;
const int M1 = 1e3, M2 = 1e4, M3 = 1e6, M4 = 1e7;

const int X[] = {2,-2,2,-2,1,-1,1,-1,   1,-1,1,-1,  0,1,0,-1,}; // X (Torre || Caballo || Alfil)
const int Y[] = {1,1,-1,-1,2,2,-2,-2,   1,-1,-1,1,  1,0,-1,0,}; // Y (Torre || Caballo || Alfil)
//const int op[] = {2,3,0,1,  7,6,5,4,11,10,9,8,    13,12,15,14}; // opuestos mov
const int typ[] = {1,1,1,1,1,1,1,1,     2,2,2,2,    3,3,3,3};

bool tablero[MAXN][MAXN]; int D[MAXN][MAXN][3][MAXIMP]; // distancia
int N;

struct nodo {
    int v,r2;

    nodo (int x, int y, int jug, int cnt, int mov) {
        v = x + M1*y + M3*cnt + M4*mov; // vertice, cantidad consec, mov específico
        r2 = jug; // puntaje y jugadas
    }
};

bool valid (int &x, int &y) {
    if (x < 0 or y < 0) return false;
    if (x >= N or y >= N) return false;
    return true;
}

ii bfs (int stX, int stY) {
    vector< nodo > Q[4];
    //forn (i,MAXTM) forn (j,4) D[stY][stX][j][i] = INF;
    D[stY][stX][0][0] = 0;
    Q[0].pb(nodo({stX,stY,0,0,0}));

    int look = 0, ptos = 0;
    while (!Q[0].empty() or !Q[1].empty() or !Q[2].empty() or !Q[3].empty()) {
        while (!Q[look].empty()) {
            auto e = Q[look].back(); Q[look].pop_back();

            int x = e.v%M1, y = (e.v/M1)%M1;
            int jugadas = e.r2;
            int cnt = (e.v/M3)%10, mov = e.v/M4;

            if (x == N-1 and y == N-1) return {jugadas,ptos};

            int tipo2 = typ[mov];
            if (ptos != D[y][x][cnt-1][(tipo2 == 1 ? 0 : mov-3)]) continue;

            forn (i,MAXTM) {
                int tX = x+X[i], tY = y+Y[i];
                if (!valid(tX,tY)) continue;
                if (tablero[tY][tX]) continue;

                int tipo = typ[i];
                bool toAdd = (mov != i or tipo == 1); // ¿NUEVA JUGADA?

                int add = -1;
                if (!toAdd) add = 0;
                else add = tipo;

                if ((tipo2 == tipo ? cnt+toAdd : 1) > 2) continue; // no más de dos mov. consec

                if ((ptos+add) >= D[tY][tX][(tipo2 == tipo ? cnt+toAdd : 1)-1][(tipo == 1 ? 0 : i-3)]) continue;
                D[tY][tX][(tipo2 == tipo ? cnt+toAdd : 1)-1][(tipo == 1 ? 0 : i-3)] = ptos+add;

                Q[(look+add)%4].pb(nodo({tX,tY, jugadas+toAdd,
                                   (tipo2 == tipo ? cnt+toAdd : 1),i}));
            }
        }

        ptos++;
        look = (look + 1) % 4;
    }
}


int main() {
    freopen("ajedrez.in","r",stdin);
    freopen("ajedrez.out","w",stdout);

    forn(i,MAXN) forn(j,MAXN) forn(k,3) forn(l,MAXIMP) D[i][j][k][l] = INF;

    int c;
    scanf("%d %d",&N,&c);

    forn(i,c) { // marco en el tablero los obstáculos
        int y1,x1,y2,x2;
        scanf("%d %d %d %d",&y1,&x1,&y2,&x2);
        x1--; y1--; x2--; y2--;

        if (abs(x1-x2) == abs(y1-y2)) { // diagonal;
            while (x1 != x2) {
                tablero[y1][x1] = true;
                if (x2 >= x1) x1++; else x1--;
                if (y2 >= y1) y1++; else y1--;
            }
            tablero[y1][x1] = true;
        }
        else {
            if (x1 >= x2 and y1 >= y2) {swap(x1,x2); swap(y1,y2);} // coords más altas en x2 e y2
            if (x1 == x2) { // vertical
                while (y1 <= y2) {
                    tablero[y1][x1] = true;
                    y1++;
                }
            }
            else { // horizontal
                while (x1 <= x2) {
                    tablero[y1][x1] = true;
                    x1++;
                }
            }
        }
    }

    /*forn (i,N) {
        forn(j,N) cout << tablero[i][j];
        cout << endl;
    }*/

    ii rta = bfs(0,0);

    /*forn (i,N) {
        forn(j,N) {
            int val = INF;
            forn (k,MAXTM) if (D[i][j][k] != -1) val = min(D[i][j][k],val);
            cout << (val == INF ? 0 : val);
        }
        cout << endl;
    }*/

    printf("%d %d",rta.fst,rta.snd);

    return 0;
}
