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

const int MAXN = 300;
const string typ = "WAKJSD"; // por orden de cant de agujeros
const int X[] = {0,1,0,-1};
const int Y[] = {1,0,-1,0};

bool img[MAXN][MAXN],done[MAXN][MAXN],done2[MAXN][MAXN];
int col[MAXN][MAXN], prox_libre[2]; /// recordar reset en -1
int holesById[MAXN*MAXN],touchEdge[MAXN*MAXN];

int parse (char x) {
    return (x <= '9' ? x : 10+x-'a');
}

void bfs (int y, int x, bool bw) { // pintaré de un mismo color áreas negras y blancas conexas
    prox_libre[bw]++;
    queue<ii> Q; Q.push({x,y}); done[y][x] = true; col[y][x] = prox_libre[bw];
    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        forn(k,4) {
            int tX = e.fst + X[k], tY = e.snd + Y[k];
            if (tX < 0 || tY < 0 || tY >= MAXN || tX >= MAXN)  {
                if (!bw) touchEdge[prox_libre[bw]] = true; // descalifico los blancos que tocan el borde del lienzo
                continue;
            }
            if (done[tY][tX] || img[tY][tX] != bw) continue;
            col[tY][tX] = prox_libre[bw];
            done[tY][tX] = true;
            Q.push({tX,tY});
        }
    }
}

void bfsFind (int y, int x) {
    queue<ii> Q; Q.push({x,y}); done2[y][x] = true;
    int myCol = col[y][x];
    set<int> idsFound;
    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        forn(k,4) {
            int tX = e.fst + X[k], tY = e.snd + Y[k];
            if (tX < 0 || tY < 0 || tY >= MAXN || tX >= MAXN) continue;
            //cerr << touchEdge[col[y][x]] << ' ' << col[y][x] << endl;
            if (done2[tY][tX]) continue;
            if (img[tY][tX]) {
                if (!touchEdge[myCol]) idsFound.insert(col[tY][tX]);
                continue;
            }
            done2[tY][tX] = true;
            Q.push({tX,tY});
        }
    }

    if (idsFound.size() == 1) holesById[*idsFound.begin()]++; // registro que soy agujero de este id
}

int main() {
    FAST_IO;

    //freopen("errss.txt","w",stderr);

    int h,w,t = 0;
    while (cin >> h >> w) {
        if (!h && !w) break;

        // MEGA RESET
        forn(i,MAXN) forn(j,MAXN) {
            img[i][j] = done[i][j] = done2[i][j] = (col[i][j] = 0);
        }
        forn(i,MAXN*MAXN) holesById[i] = touchEdge[i] = 0;
        prox_libre[0] = prox_libre[1] = -1;

        forn(i,h) {
            forn(j,w) {
                char c; cin >> c;
                int x = parse(c);
                img[i][4*j] = ((x&8) > 0);
                img[i][4*j+1] = ((x&4) > 0);
                img[i][4*j+2] = ((x&2) > 0);
                img[i][4*j+3] = ((x&1) > 0);
            }
        }

        forn(i,MAXN) forn(j,MAXN)
            if (!done[i][j]) bfs(i,j,img[i][j]);

        /*cerr<< endl;
        forn(i,h) {forn(j,w*4) cerr << img[i][j]; cerr << endl;}*/

        // para cada agujero fijémonos a qué negros tocan
        // caso que a solo uno, está enecerrado por ese y corresponde a la figura
        forn(i,MAXN) forn(j,MAXN)
            if (!done2[i][j] && !img[i][j]) bfsFind(i,j);

        string rta;
        forn(i,prox_libre[1]+1) rta.pb(typ[holesById[i]]);
        sort(all(rta));

        cout << "Case " << ++t << ": " << rta << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
