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

const int MAXN = 1e5+2;
const ll INF = 9e18;

ll dpL[MAXN][5], dpR[MAXN][5]; // 0 -> cant ceros, 1 -> cant unos, 2 -> cant signos pregunta, 3 -> suma subseq si considero hasta acá 0, 4 -> ídem pero con 1s

int main() {
    FAST_IO;

    string s; cin >> s; s = " "+s;
    ll x,y; cin >> x >> y;

    /*
        Al reemplazar un signo '?', hacia un lado se me forman una cantidad de subsecuencias "01", hacia el otro "10".
        Ejemplo pongo un 1: Si lo pongo con un signo de '?' más al principio, hay más chance que se formen más "10".
        Si lo pongo más al final, se formarán más "01", porque aumento la chance que haya 0s atrás mío.
        Lógica inversa aplica para cuando pongo un 0. En consecuencia, la solución óptima tendrá que ser reemplazar
        todos los '?' con una cantidad de 1s, y luego con una cantidad de 0s. No son varias tandas de 0s y 1s
        porque también me generan subsecuencias atrás, y arruina el punto de dividir el string en dos.
    */

    int n = s.size(); s += '?'; // dummy al final
    forsn(j,1,n) dpL[j][(s[j] == '?' ? 2 : s[j]-'0')]++, dpR[j][(s[j] == '?' ? 2 : s[j]-'0')]++;
    forsn(i,1,n+1) forn(k,3) dpL[i][k] += dpL[i-1][k];
    dforn(i,n-1) forn(k,3) dpR[i][k] += dpR[i+1][k];
    forsn(i,1,n) dpL[i][3] = dpL[i-1][1]*y*(s[i] == '0' || s[i] == '?') + (dpL[i-1][0]+dpL[i-1][2])*x*(s[i] == '1'),
                 dpL[i][4] = dpL[i-1][0]*x*(s[i] == '1' || s[i] == '?') + (dpL[i-1][1]+dpL[i-1][2])*y*(s[i] == '0');
    dforn(i,n-1) dpR[i][3] = dpR[i+1][1]*x*(s[i] == '0' || s[i] == '?') + (dpR[i+1][0]+dpR[i+1][2])*y*(s[i] == '1'),
                 dpR[i][4] = dpR[i+1][0]*y*(s[i] == '1' || s[i] == '?') + (dpR[i+1][1]+dpR[i+1][2])*x*(s[i] == '0');
    forsn(i,1,n+1) forn(k,2) dpL[i][k+3] += dpL[i-1][k+3];
    dforn(i,n-1) forn(k,2) dpR[i][k+3] += dpR[i+1][k+3];

    ll sum = INF;
    forn(i,n+1)
        sum = min({sum, dpL[i][3] + dpR[i+1][4] + (dpL[i][0]+dpL[i][2])*(dpR[i+1][2]+dpR[i+1][1])*x + (dpL[i][1])*(dpR[i+1][0])*y,
                        dpL[i][4] + dpR[i+1][3] + (dpL[i][1]+dpL[i][2])*(dpR[i+1][2]+dpR[i+1][0])*y + (dpL[i][0])*(dpR[i+1][1])*x});
    cout << sum;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
