#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 200002;
const int MAXF = 21;

struct data {
    int wT; // width tablero
    int sup; // superficie cubierta
    ii padre; // predecesor que permite superficie
};

vector< vector<data> > dp;
int X,Y,C,frente;
int best = -1;
vi centros;

int main() {
    freopen("casas.in","r",stdin);
    freopen("casas.out","w",stdout);

    scanf ("%d %d %d",&Y,&X,&C);
    frente = Y/2;

    dp.resize(MAXN,vector<data>(MAXF,{0,0}));

    centros.push_back(-1); // margen para no overflow a la izq
    forn (i,C) {
        int x;
        scanf("%d",&x);
        centros.push_back(x); // enumerados 1-C
    }
    forn (i,frente+1) dp[C+1][i] = {X,0,{-1,-1}}; // margen para empezar DP a la derecha

    int best = -1;
    ii nd = {1,1};

    dforsn (i,1,C+1)
        forsn (j,1,frente+1) {
            if (!dp[i+1][j].padre.fst) continue;
            int actW = dp[i+1][j].wT; // ancho actual
            int frenteD = actW-centros[i]; // distancia limite a borde derecho del tablero
            int limite = min({frenteD,frente,centros[i]-centros[i-1]-1});
            // minimo de limites derecho, arriba/abajo e izquierda resp a otro centro
            forsn (k,1,limite+1) {
                dp[i][k].wT = centros[i]-k;
                int nuevaSup = dp[i+1][j].sup + (k*2)*(k*2);
                if (nuevaSup > dp[i][k].sup) {
                    dp[i][k].sup = nuevaSup;
                    dp[i][k].padre = {i+1,j};
                }
                if (dp[i][k].sup > best) {
                    best = dp[i][k].sup;
                    nd = {i,k};
                }
            }
        }

    printf("%d\n",best);
    for (ii i = nd; i.fst <= C ; i = dp[i.fst][i.snd].padre)
        printf("%d\n",i.snd*2);

    return 0;
}
