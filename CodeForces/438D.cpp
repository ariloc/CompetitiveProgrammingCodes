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

/* pensaba que era con SQRT... batí fruta
       veamos que operaciones 1 y 3 son SegTree
       operación 2, ¿qué casos tengo?
       Si yo hago x mod b, tengo...
       x < b, x mod b = x, no actualizo nada
       x >= b, ¿peor caso?
       veamos que si hago mod b, x mod b < b
       Y si x >= b, entonces el caso para a y b los más chicos posible es a = 2*b-1
       Así puedo tener peor caso a = 1e9-1 y b = 5e8. Entonces a mod b = 5e8-1
       Si aumento más b, se me achica el resto. Si achico más b, aumenta el cociente y así vuelve
       a ir el resto desde 0 en adelante -> se me achica
       Conclusión: Por cada número, en el peor de los casos lo voy dividiendo aprox /2, hago sólo log2(x) ops.
       Así puede tener el SegTree el máximo en rango con el índice respectivo, y de por sí ir actualizando
       los números del más grande al más chico en el rango del update. Por c/número, hago las log2(x) ops,
       nomás se me agregan los costos de sacar los máximos y sumas, que serían nomás un par de logs que
       no me afectan mucho.
    */

const int MAXN = 1e5+5;
const int MAXST = (1<<(32-__builtin_clz(MAXN)));
const int INF = 2e9;

struct segT {
    int v,ind;

    segT operator+ (const segT &o) const {
        if (v > o.v) return (*this);
        return o;
    }
};

int arr[MAXN],N;
ll ST1[2*MAXST];
segT ST2[2*MAXST];

ll query (int i, int tl, int tr, int bl, int br) {
    if (tl >= br || tr <= bl) return 0;
    if (tl >= bl && tr <= br) return ST1[i];

    int mid = (tl+tr)/2;
    return query(2*i,tl,mid,bl,br) + query(2*i+1,mid,tr,bl,br);
}

void update (int p, int v) {
    p += N; ST1[p] = v; ST2[p].v = v;
    while (p > 1) {
        p /= 2;
        ST1[p] = ST1[2*p]+ST1[2*p+1];
        ST2[p] = ST2[2*p]+ST2[2*p+1];
    }
}

segT query_max (int i, int tl, int tr, int bl, int br) {
    if (tl >= br || tr <= bl) return {-INF,0};
    if (tl >= bl && tr <= br) return ST2[i];

    int mid = (tl+tr)/2;
    return query_max(2*i,tl,mid,bl,br) + query_max(2*i+1,mid,tr,bl,br);
}

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    N = (1<<(32-__builtin_clz(n)));
    forn(i,n) {
        int x; cin >> x;
        ST1[i+N] = x;
        ST2[i+N] = {x,i};
    }

    // build both
    dforsn(i,1,N) ST1[i] = ST1[2*i]+ST1[2*i+1], ST2[i] = ST2[2*i]+ST2[2*i+1];

    forn(i,m) {
        int typ; cin >> typ;
        if (typ == 1) {
            int l,r; cin >> l >> r; l--;
            cout << query(1,0,N,l,r) << '\n';
        }
        else if (typ == 2) {
            int l,r,x; cin >> l >> r >> x; l--;
            segT aux;
            while ((aux = query_max(1,0,N,l,r)).v >= x)
                update(aux.ind,aux.v%x);
        }
        else {
            int k,x; cin >> k >> x; k--;
            update(k,x);
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
