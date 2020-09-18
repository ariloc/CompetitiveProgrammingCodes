
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

int main() {
    FAST_IO;

    int n; cin >> n;
    forn (i,n) {
        ll a,b; cin >> a >> b;
        // a*b es la multiplicación de los puntajes. Como siempre tienen k y k², es el resultado de ḿult. de números al cubo, por lo que cbrts debe dar entero
        // Peeero además (y tuve que ver el tutorial :'v) puede suceder que todo bien con esto pero por casualidad no existen unos números a y b tal que
        // puedo sacar de la multiplicación de todo esto, una cantidad de veces que le acertó cada uno certera, por lo que también chequeo eso.
        // Es decir, el cbrt() me saca la multiplicación de los k usados. Si divido "a" o "b" por el resultado de cbrt() se cancelan los k normales (de no haber acertado)
        // y queda la multiplicación de los que estaban al cuadrado. Si algún número no fuese a cancelarse, significa que los resultados del test case
        // son imposibles dadas las reglas del juego, y quedaría un resto, que es lo que chequeo.
        ll val = round(cbrt(a*b));
        cout << ((val*val*val) == (a*b) and !(a%val) and !(b%val) ? "Yes" : "No") << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
