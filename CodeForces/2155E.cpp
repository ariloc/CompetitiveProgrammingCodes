#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 2e5+5;

int cnt[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int n,m,k; cin >> n >> m >> k;

        vi cols;
        forn(i,k) {
            int x,y; cin >> x >> y;
            if (y > 1) {
                if (!cnt[y]) cols.pb(y);
                cnt[y]++;
            }
        }
        sort(all(cols));
        
        if (n == 1) {
            if (cnt[2]&1) cout << "Mimo\n";
            else cout << "Yuyu\n";
            for (auto &c : cols) cnt[c] = 0;
            continue;
        }

        /* Si hay una columna impar, se puede tomar la más a la derecha y tomar un token de ella.
         * Luego se puede planificar su movimiento tal que todas las que están a su izq tengan cantidad
         * par de tokens (se puede mover 1ud hacia arriba si se quiere sumar un nro par, posible con n > 1).
         * Con todas pares, cualquier movimiento de Yuyu forzará a crear una columna de cantidad de
         * tokens impar si o si, porque no puede controlar la paridad de la que saca, sabe que se volverá
         * impar. Luego Mimo tiene que elegir la columna impar más a la derecha generada por Yuyu (garantizado
         * al menos una, de la cual sacó) y repetir.
         * Esa columna que tome Mimo podría limpiar la columma de tokens.
         * Como siempre Mimo toma de columnas impares, y fuerza a Yuyu a tomar de pares, eventualmente 
         * tomará el último token (columna impar) y ganará.
         * Si en cambio el tablero arranca sin ninguna impar, Mimo está obligado a que una columna se vuelva
         * impar, y se cambian los roles, quedando siempre Yuyu en ventaja con al menos una impar.
         * El juego eventualmente termina porque no pueden poner tokens en la columna más a la derecha de
         * su recorrido (mueven y crean eventualmente tokens hacia la priemr columna, donde no pueden mover).
         */
        bool ok = false;
        forn (i,cols.size())
            if (cnt[cols[i]]&1) ok = true;
        if (ok) cout << "Mimo\n";
        else cout << "Yuyu\n";
        
        for (auto &c : cols) cnt[c] = 0;
    }

    return 0;
}
