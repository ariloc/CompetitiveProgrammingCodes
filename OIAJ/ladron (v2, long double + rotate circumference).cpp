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

int const TOL = 5;
ld const EPS = 1e-6;

struct pt {
    ld x,y;
    pt (ld x, ld y) : x(x), y(y){};

    pt operator+ (const pt &o) const { return {x+o.x,y+o.y}; };
    pt operator- (const pt &o) const { return {x-o.x,y-o.y}; };
    pt operator* (const ld &o) const { return {x*o,y*o}; };
    pt operator/ (const ld &o) const { return {x/o,y/o}; };
    ld operator* (const pt &o) const { return x*o.x+y*o.y; };
    ld norm2() { return *this**this; }
    ld norm() { return sqrt(norm2()); }
    pt unit() { return *this/norm(); }
};

ll hypot2(ll x, ll y) { return x*x + y*y; }

vector<int> ladron(int N, int M, vector<int> &x, vector<int> &y, vector<long long> &dCuad) {
    auto check = [&](int xi, int yi) {
        return hypot2(xi-x[0],yi-y[0]) == dCuad[0] && hypot2(xi-x[1],yi-y[1]) == dCuad[1] && hypot2(xi-x[2],yi-y[2]) == dCuad[2];
    };

    int offx = x[0], offy = y[0];
    forn(k,3) x[k] -= offx, y[k] -= offy; // desfasammos el primero al origen
    
    pt c1 = pt(x[1],y[1]);
    ld x1 = 0, y1 = c1.norm(); // rotamos el segundo al eje de las x

    // intersecamos los primeros dos
    ld yiaux = (dCuad[1] - y1*y1 - dCuad[0]) / (-2*y1);
    ld xiaux = sqrt(abs(dCuad[0] - yiaux*yiaux)); // +-
    
    // AGREGAMOS TOLERANCIAS PARA xi y yi, SIGUE SIENDO POCOS PUNTOS A PROBAR (en especial por posible error numérico en yiaux cercano a 0)
    vector<pt> pts;
    pt off = pt(offx,offy);
    for (ld xi = xiaux-TOL; xi <= xiaux+TOL; xi += 1)
        for (ld yi = yiaux-TOL; yi <= yiaux+TOL; yi += 1) {
            // rotamos la solución de vuelta
            pt vec = c1.unit() * yi;

            if (vec.norm2() > EPS) {
                pt perp1 = pt(-vec.y,vec.x).unit() * xi;
                pt perp2 = perp1*(-1);

                pt s1 = vec+perp1, s2 = vec+perp2;
                pts.pb(s1+off), pts.pb(s2+off);
            }
            else pts.pb(vec+off);
        }

    // reestablecemos el offset
    forn(k,3) x[k] += offx, y[k] += offy; 

    vector<ii> rta;
    forn(k,pts.size())
        forsn(i,max(0,(int)pts[k].x-TOL),min(N,(int)pts[k].x+TOL))
            forsn(j,max(0,(int)pts[k].y-TOL),min(M,(int)pts[k].y+TOL))
                if (check(i,j)) rta.pb({i,j});

    sort(all(rta));
    rta.erase(unique(all(rta)),rta.end());

    vi r;
    for (auto &i : rta) { r.pb(i.fst); r.pb(i.snd); }

    return r;
}
