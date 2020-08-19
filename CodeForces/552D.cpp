#include <bits/stdc++.h>

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

const int MAXN = 2002;

struct point {
    int x,y;

    point operator-(point o) {return {x - o.x, y - o.y};} // obtiene un vector que va en la dirección que le digo a partir de los ptos
    bool operator< (const point &o) const {return (x == o.x ? y < o.y : x < o.x);} // para ordenar en map, requiero un orden establecido. Lo hago como si fuesen ii

    void normalize(){ // normalizar un vector o obtener el vector de componentes enteras más corto, conservando dirección y sentido
        ll d = __gcd(abs(x), abs(y));
        x /= d; y /= d;
        if(y < 0 or (!y and x < 0)) // se reduce a una dirección
            {x = -x; y = -y;}
    }
};

point plano[MAXN];
map<point,int> M; // cantidad de vectores de cierta dirección

int main() {
    FAST_IO;

    ll toRest = 0, rta = 0;
    ll N; cin >> N;

    forn (i,N) cin >> plano[i].x >> plano[i].y;

    forn(i,N) {
        M.clear();
        forsn(j,i+1,N) {
            point c = plano[j] - plano[i]; // obtengo vector representativo
            c.normalize(); // normalizo vector
            M[c]++; //cuento cantidad de puntos cuyo vector normalizado resultante es el mismo
        }

        int n = N - (i + 1);
        rta += (n*(n-1))/2; // triangulos que puedo formar tomando como un punto a i

        for (auto &k : M) {
            ll v = k.snd; // cantidad de vectores resultantes iguales
            rta -= (v*(v-1))/2;
            // posibilidades a descartar, la cantidad de combinaciones de puntos alineados posibles
        }
    }
    cout << rta;

    return 0;
}