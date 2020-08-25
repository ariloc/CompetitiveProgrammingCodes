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

const int MAXN = 2e5+5;
// potencia de 2 más cercana, le pongo uno más del MSB
// (por comportamiendo del __builtin_clz y shiftear un 1, es como restar 1 y luego sumar 1)
const int MAXST = (1<<(32-__builtin_clz(MAXN)));

struct info {
    ll sum,l,r,ans; // long long por cota |x_i| <= 1e9

    info(ll x) : sum(x),l(max(0ll,x)),r(max(0ll,x)),ans(max(0ll,x)){} // declarador de init
    info(){}
};

info ST[2*MAXST];
int n,m,N;

void doMerge(int i) {
    /*
    3 CASOS:
      - LO MEJOR ES PREFIJO Y SUFIJO DE AMBOS LADOS (ESTOY EN MEDIO)
      - LO MEJOR ES DERECHA
      - LO MEJOR ES IZQUIERDA
    */

    int a = i<<1, b = (i<<1)+1; // hijos (2*i, 2*i+1)
    ST[i].sum = ST[a].sum + ST[b].sum; // suma en mi rango incondicionalmente
    ST[i].l = max(ST[a].l, ST[a].sum + ST[b].l); // si extiendo o no mi prefijo a la derecha
    ST[i].r = max(ST[b].r, ST[b].sum + ST[a].r); // si extiendo o no mi sufijo a la izquierda
    ST[i].ans = max({ST[b].l + ST[a].r, ST[a].ans, ST[b].ans});
    // [línea anterior] si agarro la respuesta de los lados o el de si estoy en medio, los mejores de c/u
}

void build() {dforsn(i,1,MAXST) doMerge(i);}

ll update(int k, int x) {
    int me = k+MAXST; // posic
    ST[me] = info(x); // init/replace
    while (me) {me>>=1; doMerge(me);} // update nodes connected | me>>=1 --> m/=2
    return ST[1].ans; // return main answer
}

int main() {
    scanf("%d %d",&n,&m);

    /// INPUT AND BUILD
    forn(i,n) {int x; scanf("%d",&x); ST[i+MAXST] = x;} // directamente al SegTree
    build();

    forn(i,m) {
        int k,x; scanf("%d %d",&k,&x);
        printf("%lld\n",update(k-1,x)); /// UPD AND OUTPUT
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
