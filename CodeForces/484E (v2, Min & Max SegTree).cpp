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
int const INF = 2e9;

struct quer {
    int l,r,w,i;
    bool operator< (const quer &o) const { return w < o.w; }
};

struct range {
    int l,r,i;
    bool operator< (const range &o) const { return r-l < o.r-o.l; }
};

int ml[MAXN], mr[MAXN];
int arr[MAXN];
vector<quer> queries;
int rta[MAXN];
int STmax[2*MAXN], STmin[2*MAXN];
int N;

typedef int (*OpFunc)(int a, int b);
void update(int p, int v, int *ST, OpFunc op) {
    p += N; ST[p] = v;
    while (p > 1) p /= 2, ST[p] = op(ST[2*p],ST[2*p+1]);
}

int query(int l, int r, int *ST, OpFunc op, int NEUT) {
    int ret = NEUT;
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l&1) ret = op(ret,ST[l++]);
        if (r&1) ret = op(ret,ST[--r]);
    }
    return ret;
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> arr[i+1];

    N = n;
    ml[0] = mr[n+1] = -INF;

    forsn(i,1,n+1) {int j; for (j = i-1; arr[j] >= arr[i]; j = ml[j]); ml[i] = j;}
    dforsn(i,1,n+1) {int j; for(j = i+1; arr[j] >= arr[i]; j = mr[j]); mr[i] = j;}

    vector<range> rang;
    forsn(i,1,n+1) rang.pb({ml[i],mr[i],i});

    sort(all(rang));

    forn(i,n) STmin[i+N] = arr[i+1];
    dforsn(i,1,n) STmin[i] = min(STmin[2*i],STmin[2*i+1]); // build

    int q; cin >> q;
    forn(i,q) {
        int l,r,w; cin >> l >> r >> w; --l, --r;
        queries.pb({l,r,w,i});
        auto mini = [](int a, int b){return min(a,b);};
        rta[i] = query(l,l+w,STmin, mini, INF);
    }

    /* Tomamos intervalos más grandes para cada arr[i] que lo tienen como mínimo. Sea este rango [ml[i],mr[i]].
     * Entonces, la respuesta a una query está en alguno de estos rangos, queremos el del valor mínimo más grande.
     * Puede pasar que estos rangos [ml[i],mr[i]] tengan extremos fuera de [l,r] (uno o ambos).
     * Dividimos en dos casos:
     *
     * - El rango [ml[i],mr[i]] en el que se encuentra el de la respuesta de la query tiene su extremo izquierdo en [l,r]. 
     *   Luego, tiene que estar en [l,r-w+1], para que sea de al menos largo w. Calculamos ordenando cuidadosamente,
     *   para obtener mayor altura entre todos los intervalos tales en cada query.
     *
     * - El rango [ml[i],mr[i]] en el que se encuentra el de la respuesta de la query tiene su extremo izquierdo en [0,l). 
     *   En este caso, como el rango deseado en sí tiene que estar en [l,r), y cualquier segmento de longitud w en
     *   [ml[i],mr[i]] valdría, en particular vale [l,l+w-1]. En este caso, la máxima altura es simplemente el mínimo
     *   del intervalo. Observar que no podría pasar que exista un rango en este caso [l+delta,l+delta+w-1] donde
     *   la altura sea mayor, porque en ese caso, implicaría que el mínimo es mayor en ese rango, habiendo
     *   entonces un elemento menor a ese en [l,l+delta], y estaría cubierto por el primer caso analizado.
     */

    sort(all(queries));

    int idx = n-1;
    auto maxi = [](int a, int b){return max(a,b);};
    dforn(i,q) {
        while (idx >= 0 && rang[idx].r-rang[idx].l-1 >= queries[i].w) {
            update(rang[idx].l-1,arr[rang[idx].i],STmax,maxi);
            --idx;
        }
        rta[queries[i].i] = max(rta[queries[i].i],query(queries[i].l,queries[i].r-queries[i].w+1,STmax,maxi,-INF));
    }

    forn(i,q) cout << rta[i] << '\n';

    return 0;
}
