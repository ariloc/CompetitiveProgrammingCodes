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

const int MAXN = 1e6+5;
const int MOD = 1e9+7;

void fs (int &x) {
    int c; x = 0;
    c = getchar_unlocked();
    if (c < '0' || c > '9') c = getchar_unlocked();
    for (; c>='0' && c<='9'; c = getchar_unlocked())
        x = 10*x + c-'0';
}

void fp (int x) {
    int i = 9;
    char buf[10];
    while (x) buf[i--] = (x%10)+'0', x /= 10;
    while ((++i) < 10) putchar_unlocked(buf[i]);
}

int dp[MAXN][1<<3]; // 0 es vertical arriba, 1 es vertical abajo, 2 es medio || bit prendido es que lo saco

int main() {
    // DP
    forn(j,1<<3) if (!(j&4) || (((j&2) > 0) == ((j&1) > 0))) dp[0][j] = 1; // si saco el del medio, solo válido si saco ambos verticales

    forsn(i,1,MAXN) forn(j,1<<3) forn(k,1<<3) {
        if ((j&4) && ((j&2) > 0) != ((j&1) > 0)) continue; // configs inválidas
        if ((k&4) && ((k&2) > 0) != ((k&1) > 0)) continue;

        // si saco el del medio en el k, no puedo ir con el j si es que algun vertical lo saqué y el otro no
        // o si los dos están iguales (saqué o no), no se puede cuando SAQUÉ ambos y el del medio no.
        if ((k&4) && ( (((j&2) > 0) != ((j&1) > 0)) || ( (j&1) && !(j&4)) ) ) continue;

        if (j == 7 && !(k&4)) continue; // si en el anterior saqué todos, solo puedo si saqué el del medio

        dp[i][k] = (dp[i][k] + dp[i-1][j])%MOD; // paso las posibilidades de uno a otro
    }

    int t; fs(t);
    forn(i,t) {
        int x; fs(x);
        // solo vale si no está abierto a la derecha
        fp( (dp[x-1][0]+dp[x-1][4])%MOD ); putchar_unlocked('\n');
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
