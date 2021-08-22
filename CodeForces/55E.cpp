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

const int MAXN = 1e5+5;

struct pt {
    double x,y;
    pt(double x, double y) : x(x),y(y){}
    pt(){}

    pt operator- (const pt &o) const {return pt(x-o.x, y-o.y);}
    double operator% (const pt &o) const {return x*o.y - y*o.x;} // cross product
    double operator* (const pt &o) const {return x*o.x + y*o.y;} // dot product
    bool left (const pt &a, const pt &b) {return (b-a)%(*this-a) > 0;} // left of directed line ab?
};


pt poly[MAXN];
/*
ll srch (int j, int k, int n, pt me) {
    bool myDir = poly[k].left(poly[j],me);
    bool otMyDir = poly[j].left(poly[k],me);

    int low = k, high = n+k;
    while (high-low > 1) {
        int mid = (high+low)/2;
        if (poly[mid%n].left(poly[j],me) == myDir) low = mid;
        else high = mid;
    }

    if (poly[high%n].left(poly[j],me) == myDir) low = high;
    low %= n;

    int lw = low+1, hgh = n+low;
    //if (poly[(low+1)%n].left(poly[k],me) != otMyDir) {
    while (hgh-lw > 1) {
        int mid = (lw+hgh)/2;
        if (poly[mid%n].left(poly[k],me) == otMyDir) hgh = mid;
        else lw = mid;
    }
    //} else hgh = lw;
    if (poly[lw%n].left(poly[k],me) == otMyDir) hgh = lw;

    return (hgh-low-1);
}*/


/*
    La idea original era sacar las combinaciones posibles
    de triángulos a medida que avanzan los punteros, según qué puntos hay en el área opuesta,
    pues se puede observar que todos aquellos sirven como 3er vértice (los otros dos los pteros)
    para un triángulo que contiene el punto a ver. Los punteros son tales para encontrar el
    segmento maximal que uno traza entre ellos tal que el punto siempre se mantenga "hacia
    afuera". Después de estar como más de 14hs lidiando con la Binary Search arriba comentada,
    funciona para encontrar el rango de puntos de ese área opuesta, pero estaba ahora lidiando
    como ese rango se reducía o aumentaba según iba corriendo los punteros, y lograr al resultado
    final esperado.

    En un punto dije...¿cómo puede ser que varios de avanzado los hicieron en lo que parece ser
    código exaustivamente largo? (lo miraba pero no los pensaba, nomás para ver si mi longitud
    de código era realmente realista y posible de solución). Entonces me puse después de horas a
    ver lo que hizo alguien. Efectivamente mi idea de los punteros estaba bien :D
    Peero con un pequeño detalle, y es que no veía por ningún lugar como encontraban el tercer pto.
    Y resulta se podía descartar observando que bueno, la cantidad total de triángulos que
    se puede formar a partir de un conjunto de vértices, y luego que los únicos que tengo
    descartar (acá donde me quedé estupefacto) es solo entre los que formo del rango maximo (entre punteros).
    De hecho lo había pensado, pero a medida que iba con los punteros (que pensando
    está terriblemente mal), y no me funcionaba mucho. Pero por supuesto,
    en vez de pensarlo a partir de "estas bases de dos vértices no pueden con este tercero"
    me vi el upsolving del video de Avanzado para entender la cuenta y resulta pues,
    como dado que agarro un punto vértice de mi triángulo, la forma (un poco intuitiva)
    de descartar es que si los puntos están todos de un lado, no voy a poder incluir a mi punto,
    y de ahí sale la respuesta.

    Con esa obserrvación...seh la implementación es una papa.
*/

int main() {
    FAST_IO;

    // seh, y poner el n en long long así después la cuenta de total triángulos funca
    ll n; cin >> n;
    forn (i,n) cin >> poly[i].x >> poly[i].y;

    int t; cin >> t;
    forn (i,t) {
        int x,y; cin >> x >> y;
        pt me = pt(x,y);

        ll tot = n*(n-1)*(n-2)/6; // total posibles --> viene de (n!/(3!(n-3)!))

        bool posSeg = me.left(poly[0],poly[1]); // signo "norma"
        int k = 1;

        // verifico si el punto está afuera, y evito loops o problemas
        bool posib = true;
        bool otNorma = me.left(poly[0],poly[1]); // si distinta orientación en algún punto
        forsn (j,1,n-1) if (me.left(poly[j],poly[j+1]) != otNorma) {cout << "0\n"; posib = false; break;}
        if (!posib) continue;

        forn (j,n) { // two pointers
            while (me.left(poly[j],poly[k]) == posSeg) k=((k+1)%n);
            ll rest = (k > j ? k-j-1 : (n+k)-j-1);
            tot -= rest*(rest-1)/2;
        }

        cout << tot << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!