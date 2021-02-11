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

const int MAXS = 5e5+5;
const int MAXN = 1005;

ii shops[MAXS];
int dpDerIzq[MAXN][MAXN], dpIzqDer[MAXN][MAXN], dpTopBot[MAXN], dp[MAXN][MAXN];

bool valid (int v) {
    return (v >= 0 && v < MAXN);
}

int main() {
    int dx,dy,n,q,t = 0;
    while(scanf("%d %d %d %d",&dx,&dy,&n,&q) != EOF) {
        if (!dx && !dy && !n && !q) break;
        printf("Case %d:\n",++t);

        forn(i,n) scanf("%d %d",&shops[i].fst,&shops[i].snd);

        forn(i,q) {
            int m; scanf("%d",&m);

            // reset
            forn(j,MAXN) forn(k,MAXN) dpDerIzq[j][k] = dpIzqDer[j][k] = dp[j][k] = 0;
            forn(j,MAXN) dpTopBot[j] = 0;

            forn(j,n) {
                int x = shops[j].fst, y = shops[j].snd;
                int stY = y-m, ndY = y+m, stX = x-m, ndX = x+m; // extremos diamante que cubre
                int aux; ii st,nd;

                // vayamos cuadrante por cuadrante

                /// cuadrante IV

                /**
                OOOOOOOOOO
                OOOOIOOOOO
                OOOOOOOOOO
                -OOOOOOOOO
                O+OOXOOIOO
                OO+OOOOOOO
                OOO+OOOOOO
                OOOO+OOOOO
                OOOOOOOOOO
                **/

                st = {x,ndY}, nd = {stX-1,y-1};
                aux = max(0,ndY-MAXN+1);
                st.fst -= aux, st.snd -= aux;

                /// IMP!!!
                if (stX < 0) { // caso emergencia topbottom
                    dpTopBot[max(0,y+stX+1)]++;
                    if (y-stX < MAXN) dpTopBot[y-stX]--;
                }

                if (valid(st.snd) && valid(st.fst)) {
                    dpDerIzq[st.snd][st.fst]++;
                    if (valid(nd.snd) && valid(nd.fst)) dpDerIzq[nd.snd][nd.fst]--; // no corregimos el otro porque si estoy fuera, la cadena de + va hasta donde puede
                }

                /// cuadrante I

                /**
                OOOOO-OOOO
                OOOO+OOOOO
                OOO+OOOOOO
                OO+OOOOOOO
                OIOOXOOIOO
                OOOOOOOOOO
                OOOOOOOOOO
                OOOOIOOOOO
                OOOOOOOOOO
                **/

                st = {stX+1,y-1}, nd = {x+1,stY-1};
                aux = max(0,-(stX+1));
                st.fst += aux, st.snd -= aux;
                // para el resto la cadena sigue

                if (valid(st.snd) && valid(st.fst)) {
                    dpIzqDer[st.snd][st.fst]++;
                    if (valid(nd.snd) && valid(nd.fst)) dpIzqDer[nd.snd][nd.fst]--;
                }

                /// cuadrante III

                /**
                OOOOOOOOOO
                OOOOIOOOOO
                OOOOOOOOOO
                OOOOOOOOO+
                OIOOXOOI-O
                OOOOOOO-OO
                OOOOOO-OOO
                OOOOI-OOOO
                OOOOOOOOOO
                **/

                st = {x+1,ndY}, nd = {ndX+2,y-1};
                aux = max(0,ndY-MAXN+1);
                st.fst += aux, st.snd -= aux; // mientras la y baja, la x sube
                // no corrijo por si se pasa x+1 porque no solo el tablero es grande y no debería, pero también la cadena iría hasta donde puede
                // también por lo de las cadenas no hago nada si se pasa el nd

                if (valid(st.snd) && valid(st.fst)) {
                    dpIzqDer[st.snd][st.fst]--;
                    if (valid(nd.snd) && valid(nd.fst)) dpIzqDer[nd.snd][nd.fst]++;
                }

                /// cuadrante II

                /**
                OOOO+OOOOO
                OOOOI-OOOO
                OOOOOO-OOO
                OOOOOOO-OO
                OIOOXOOIOO
                OOOOOOOOOO
                OOOOOOOOOO
                OOOOIOOOOO
                OOOOOOOOOO
                **/

                st = {ndX,y-1}, nd = {x,stY-1};
                aux = max(0,ndX-MAXN+1);
                st.fst -= aux, st.snd -= aux;
                // el resto no me importa mover porque la cadena sigue

                if (valid(st.snd) && valid(st.fst)) {
                    dpDerIzq[st.snd][st.fst]--;
                    if (valid(nd.snd) && valid(nd.fst)) dpDerIzq[nd.snd][nd.fst]++;
                }

            }

            // hagamos las tablas aditivas

            // izqDer
            forn(j,MAXN) {
                int y = j-1, x = 1;
                while (valid(x) && valid(y)) dpIzqDer[y][x] += dpIzqDer[y+1][x-1], y--, x++;
            }
            forsn(j,1,MAXN) {
                int y = MAXN-2, x = j+1;
                while (valid(x) && valid(y)) dpIzqDer[y][x] += dpIzqDer[y+1][x-1], y--, x++;
            }

            // derIzq
            forn(j,MAXN) {
                int y = j-1, x = MAXN-2;
                while (valid(x) && valid(y)) dpDerIzq[y][x] += dpDerIzq[y+1][x+1], y--, x--;
            }

            dforn(j,MAXN-1) {
                int y = MAXN-2, x = j-1;
                while (valid(x) && valid(y)) dpDerIzq[y][x] += dpDerIzq[y+1][x+1], y--, x--;
            }

            // caso emergencia topBot
            forsn(j,1,MAXN) dpTopBot[j] += dpTopBot[j-1];
            // y lo paso de una dp
            forn(j,MAXN) dp[j][0] = dpTopBot[j];

            // formemos la tabla aditiva horizontal
            forn(j,MAXN) forn(k,MAXN)
                dp[j][k] = dp[j][k] + dpDerIzq[j][k] + dpIzqDer[j][k];

            // contruyamos la TAd horizontal
            forn(j,MAXN) forsn(k,1,MAXN)
                dp[j][k] += dp[j][k-1];


            // por fin ahora sí, busquemos
            int maxi = -1; ii found = {-1,-1};
            forsn(j,1,dy+1) forsn(k,1,dx+1) // devolver positivos, y por las dudas dentro de las dimensiones
                if (dp[j][k] > maxi || (dp[j][k] == maxi && (j < found.snd || (j == found.snd && k < found.fst))))
                    maxi = dp[j][k], found = {k,j};

            printf("%d (%d,%d)\n",maxi,found.fst,found.snd);
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
