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

int arr[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    int op = 0;
    forn(j,n) {cin >> arr[j]; op ^= arr[j];}

    if (op && (!(n&1))) return cout << "NO", 0;

    int top = n-(!(n&1));
    vector<tuple<int,int,int>> rta;
    for(int i = 2; i < top; i+=2) rta.pb({i-2,i-1,i}); // formo pares iguales, así luego se cancelan al elegirlos y quedan igual al tercero
    for(int i = 0; i < top-1; i+=2) rta.pb({i,i+1,top-1}); // hago todos iguales
    /* En caso par, si el xor del array es 0, implica que se puede pues en caso de hacerlos todos iguales, así sería,
       pues el xor de cantidad par de un mismo elemento es 0. Además, el xor cumple con la propiedad que al ir
       haciendo estas operaciones vemos que nunca cambia el de todo el array. Si aplicamos estrategia en n-1 números en caso par,
       como el xor tiene que ser cero, y como voy haciendo progresivamente el xor de todo el array hasta el final
       (agarro uno que es xor de tres anteriores, más dos más, y así hasta quedar xor de todos los n-1 números),
       el n-1-ésimo quedará igual al n-ésimo ya que se tienen que cancelar para dejar el xor final 0 como dijimos que tiene que ser.
       Así puedo ignorar el último y directamente aplicar la estrategia de los impares en los n-1 para el caso par. */

    cout << "YES\n";
    cout << rta.size() << '\n';
    for (auto &i : rta) cout << get<0>(i)+1 << ' ' << get<1>(i)+1 << ' ' << get<2>(i)+1 << '\n';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
