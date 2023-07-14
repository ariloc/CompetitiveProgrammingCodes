// Idea de desdoblar la DP de Lautaro
#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define pb push_back
#define fst first
#define snd second
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const int MAXN = 30;
const int TOP = 1<<24;

int val[MAXN][MAXN],n;
unordered_map<int,int> dp1;
int dp2[TOP];

int solve (int mk) {
    int *rta_ptr;
    if (mk < TOP) rta_ptr = &dp2[mk]; // Fundamental usar el puntero, me acorta los accesos
    else rta_ptr = &dp1[mk];

    int rta = *rta_ptr;
    if (rta) return rta;

    int lsb1 = mk & -mk;
    int act, auxmk; act = auxmk = (mk ^ lsb1); // saco el primero sin usar
    int lsb2 = act & -act;
    int found = __builtin_ctz(lsb1);
    if (!(act^lsb2))  // si me quedan dos bits, stop it
        return val[found][__builtin_ctz(lsb2)];

    int maxi = 0;
    while (auxmk) {
        int lsb = (auxmk & -auxmk);
        maxi = max(maxi,solve(act^lsb)+val[found][__builtin_ctz(lsb)]); // ctz cuenta los trailing 0s -> exponente de elevar 2 para obtener lsb que saqué
        auxmk ^= lsb;
    }

    return *rta_ptr = maxi;
}

int main() {
    scanf("%d",&n);

    forn(i,n) forn(j,n) scanf("%d",&val[i][j]);

    printf("%d",solve((1<<n)-1)); // prendido es sin usar, apagado es usado

    return 0;
}