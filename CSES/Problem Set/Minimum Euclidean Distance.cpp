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

void fs (int &x) {
    int c; x = 0; bool neg = false;
    c = getchar_unlocked(); neg |= (c == '-');
    if (c < '0' || c > '9') c = getchar_unlocked(), neg |= (c == '-');
    for (; c>='0' && c<='9'; c = getchar_unlocked())
        x = 10*x + c-'0';
    if (neg) x *= -1;
}

const int MAXN = 2e5+5;
const ll INF = 9e18;

struct pt {
    ll x,y;
};

pt plane[MAXN],aux[MAXN];
ll rta = INF;

bool comp_y (const pt &lhs, const pt &rhs) {
    return lhs.y < rhs.y;
}

bool comp_x (const pt &lhs, const pt &rhs) {
    if (lhs.x == rhs.x) return lhs.y < rhs.y;
    return lhs.x < rhs.x;
}

void upd (pt &a, pt &b) {
    rta = min(rta,(a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)); // hypot² y queda en enteros. Se le puede agregar ids para saber qué par cumple si lo pide el ejercicio
}

void divide (int l, int r) {
    if (r-l <= 3) { // si hay pocos puntos, directamente probamos todos los pares porque son pocas operaciones
        forsn(i,l,r) forsn(j,i+1,r) upd(plane[i],plane[j]);
        sort(plane+l,plane+r,comp_y); // en cada paso devolvemos el subconjunto de cada mitad ordenado por coord y
        return; // obviamente ya que procesamos, nos vamos
    }

    int mid = (l+r)/2; // índice de mediana
    int xmid = plane[mid].x; // establecemos una línea divisoria en los puntos ordenados por x
    divide(l,mid); divide(mid,r); // haremos el merge cuando ya estén ordenadas y procesadas las mitades

    merge(plane+l,plane+mid,plane+mid,plane+r,aux,comp_y); // con la línea divisoria intermedia establecida, ordenamos por Y para el merge y para estar ordenado en la instancia que me llamó a la func
    forn(i,r-l) plane[i+l] = aux[i]; // El copy no ahorra mucho, así que mejor un for. Usamos un auxiliar aux para evitar que las cosas se mezclen en la función merge, así que ahora copiamos back.

    int tsz = 0;
    forsn(i,l,r) if ((plane[i].x-xmid)*(plane[i].x-xmid) < rta) { // si siquiera la distancia a la divisoria minimiza la rta, entonces ni me fijo. Es abs porque puedo estar de cualquier lado de la línea
        for (int j = tsz-1; j >= 0 && (plane[i].y-aux[j].y)*(plane[i].y-aux[j].y) < rta; j--) // lo mismo con las y. Notar que no es abs, porque me fijo solo los que están abajo mío para no probar un par dos veces
            upd(plane[i],aux[j]);
        aux[tsz++] = plane[i]; // nos lo ponemos en un aux ya que queremos probar de a pares solo con los que antes también hayan cumplido lo de las x
        // notar que como ordenamos todo y vamos siempre tomando el mínimo de cada mitad, dividiendo a partes muy chicas, el espectro de búsqueda se reduce rápidamente haciendo que el for de adentro del anterior pruebe muy pocos puntos
    }
}

int main() {
    int n; fs(n);
    forn(i,n) {
        int x,y; fs(x), fs(y);
        plane[i] = {x,y};
    }

    sort(plane,plane+n,comp_x); // first by x, then by y coord
    divide(0,n);

    printf("%lld",rta);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
