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

const int MAXN = 1005;
const int INF = 1e9+5;

ii dp[MAXN][MAXN]; // si elegimos el i-ésimo elemento (valor Jan y el de Petra) en el j-ésimo movimiento
bitset<MAXN> nums[MAXN][2];
ii value[MAXN]; // P,J

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n; cin >> n;
        string s; cin >> s;
        forn(j,n) cin >> value[j].fst >> value[j].snd;

        sort(value,value+n,[](const ii &lhs, const ii &rhs)
                             {if (lhs.fst == rhs.fst) return lhs.snd < rhs.snd; return lhs.fst > rhs.fst;});

        ii maxi = {-1,-1}; int ind = -1;
        forn(j,n) {
            if (value[j].fst > maxi.fst || (value[j].fst == maxi.fst && value[j].snd < maxi.snd))
                maxi = value[j], ind = j;
        }

        forn(j,n+1) forn(k,n+1) dp[j][k] = {-INF,-INF};
        forn(j,n+1) dp[j][0] = {0,0};
        forn(j,n+1) nums[j][0].reset(), nums[j][1].reset();
        forn(j,n+1) forn(k,n) nums[j][0][k] = 1; // primero están todos los índices
        forn(k,n) nums[0][1][k] = 1;

        bool cond = (s == "Petra");
        if (cond) { // ya hice el primer movimiento entonces empiezo correspondientemente
            forn(j,n+1) dp[j][0].snd += maxi.fst;
            forn(j,n+1) nums[j][0][ind] = 0;
            nums[0][1][ind] = 0;
        }

        int lastMov = (cond ? n/2 : (n+1)/2); bool turn = 1;
        forsn(i,1,n+1) {
            forsn(j,1,lastMov+1){ // i-ésima persona, j-ésimo mov
                ii prv = dp[i-1][j];
                if (!nums[j-1][1^turn][i-1]) {  // solo lo puedo usar si está disponible (no lo usó Petra), i-1 por desfase
                    dp[i][j] = dp[i-1][j]; nums[j][turn] = nums[j][1^turn]; // pero al menos paso lo de antes
                    continue;
                }

                int calc1 = value[i-1].snd+dp[i-1][j-1].fst, calc2 = dp[i-1][j-1].snd, indCh = -1; // value[i-1] pos tengo todos desfasados
                if ((int)nums[j-1][1^turn].count() > 1) { // si no soy último turno, el count es <= 1 y no le sumaría nada
                    int indMax_it = nums[j-1][1^turn]._Find_first(); // índice menor pos está ordenador por los que más le valen a Petra
                    if (indMax_it == i-1) indMax_it = nums[j-1][1^turn]._Find_next(indMax_it); // si coincide conmigo, paso al prox mayor
                    int indMax = indMax_it; indCh = indMax;
                    calc2 += value[indMax].fst;
                }

                if (calc1 >= prv.fst || (calc1 == prv.fst && calc2 >= prv.snd)) {
                    dp[i][j] = {calc1,calc2};
                    nums[j][turn] = nums[j-1][1^turn];
                    if (indCh != -1) nums[j][turn][indCh] = 0; // elimino lo de petra
                    nums[j][turn][i-1] = 0; // elimino lo mío, i-1 por desfase
                } else dp[i][j] = prv, nums[j][turn] = nums[j][1^turn]; // si directamente lo paso
            }
            turn ^= 1;
        }


        cout << dp[n][lastMov].snd << ' ' << dp[n][lastMov].fst << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
