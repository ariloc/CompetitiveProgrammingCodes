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

const int MAXN = 1002;
const ll INF = 1e18;

ll num[MAXN];
vector<ii> G[MAXN];

int main() {
    FAST_IO;

    int m,n,k; cin >> m >> n >> k;
    ll maxi = 0;
    forn(i,n) {cin >> num[i]; maxi = max(maxi,num[i]);}
    forn(i,k) {
        int mx,nx,d; cin >> mx >> nx >> d; mx--; nx--;
        G[mx].pb({nx,d});
    }

    ll st = 2;
    forn(discover,m) { // descubriendo los primos uno por uno
        ll e = num[G[discover][0].fst], newP = -1; // elijo uno al que multiplique
        for(ll i = st; i*i <= maxi; i++) { // partiendo del anterior st para que no se rompa
            bool used = false;
            if(!(e%i)) { // si encuentro un número que lo divide
                ll v = 1;
                forn (j,G[discover][0].snd) v *= i; // la cantidad de vueltas es la cantidad de aristas (veces que multiplico)
                used = true; e /= v; // le saco el factor primero en cuestión
            }
            if (used) {st = i+1; newP = i; cout << newP << ' '; break;} // al ser el más chico, dicho factor es que el que corresp. en la posic.
        }
        if (newP == -1) {newP = e; st = e+1; cout << e << ' ';} // si no lo encontré antes, es que quedó un numero primo, y ese es el de mi posic.
        // tengo que sacarle los factores más chicos antes de pasar al siguiente paso,
        // pues si bien yo salto después y no sacarlos no implica que no sean divisibles por los
        // factores más altos, si me pueden quedar al dividir números compuestos que me rompen todo.
        for (auto &i : G[discover]) if(!(num[i.fst]%newP)) {
            ll v = 1;
            forn (j,i.snd) v *= newP; // la cantidad de vueltas es la cantidad de aristas (veces que multiplico)
            num[i.fst] /= v; // le saco a todos los conectados, el factor en cuestión
        }
    }

    forn(i,n) if (num[i] > 1) cout << num[i] << ' '; // muestro los restantes primos que no hayan sido cancelados

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
