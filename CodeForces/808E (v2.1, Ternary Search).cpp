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

int const MAXN = 1e5+5;

vi nums[3];
ll pref[3][MAXN];

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,n) {
        int w,c; cin >> w >> c;
        nums[w-1].pb(c);
    }

    forn(k,3) sort(all(nums[k])), reverse(all(nums[k]));
    forn(k,3) nums[k].pb(0); // dummy

    forn(k,3) forn(i,nums[k].size()) pref[k][i+1] = pref[k][i] + nums[k][i];

    /*
     * Es importante para la ternary que la función sea toda creciente y luego toda decreciente, o viceversa.
     * Fijado una cantidad de un peso, los otros dos parecen dar una función tal.
     * Sin embargo, observamos en primer lugar que en el extremo puede haber varios casos que ambos sean iguales.
     * Esto no influye siempre y cuando llegar a un par iguales adyacentes (en enteros) ESTÉ en el máximo.
     * El problema sería si hay una "parte plana" en algún valor fuera del máximo (y no se pueda saber para qué lado
     * seguir buscando). 
     * La forma para hacer esto es SÍ O SÍ fijar por la cantidad de 3s y buscar en la canrtidad de 2s, o al revés,
     * siempre y cuando la que queda en el cálculo es la de 1s, ya que sino la función capaz no tiene partes planas,
     * pero NO es toda creciente y toda decreciente.
     * Como un ejemplo, si se fija la cantidad de 3s, en fuerza bruta se puede buscar la cantidad óptima de 1s empezando
     * por decir que son todos de peso 1s, y luego ir sacando y rellenando con 2s si es posible. Observar que si saco 1 sólo
     * de peso 1. puede NO liberar suficiente espacio para meter otro de peso 2. En ese caso, la función devuelve de hecho
     * un valor menor, incluso si luego al sacar otro de 1 se obtiene un mucho mejor resultado, haciendo creyer FALSAMENTE
     * a la ternary que hay que agregar 1s, cuando realmente conviene sacar.
     * De forma similar pasa si se fijan los de peso 2s y se busca en los de 1s, o también si se fijan los de 1s y se busca
     * en los de 3s o 2s, buscando el otro.
     * Si se fijan los de 2s o 3s y se busca el otro, al sacar el buscado siempre se libera SUFICIENTE ESPACIO para meter 1
     * o más de peso 1, implicando que aumente el costo por ese lado, mientras disminuye por el otro, dando lugar a que la 
     * función SÍ sea monótona hasta el máximo, y ESTRICTAMENTE de hecho. Luego en el máximo puede pasar, en todo caso,
     * que se sacan tantos del buscado como se rellenan del restante aportando mismo costo, pero en ese caso ya se está en el
     * máximo, y funciona igual.
     */

    ll maxi = 0;
    forn(i,nums[1].size()) { // with dummy
        int w3 = i*2;
        if (w3 > m) break;

        auto calc = [&](int j) {
            return pref[2][j]+pref[0][min(m-w3-j*3,(int)nums[0].size())];
        };

        int lo = -1, hi = min((m-w3)/3, (int)nums[2].size());
        while (hi-lo > 1) {
            int mid = (hi+lo)/2;
            if (calc(mid) < calc(mid+1)) lo = mid;
            else hi = mid;
        }
        maxi = max(maxi,calc(hi)+pref[1][i]);
    }

    cout << maxi << '\n';

    return 0;

}
