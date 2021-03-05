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

const int MAXN = 305;
const ld INF = 9e18;

struct pt {
    ll x,y;
    pt(){}
    pt(ll xx, ll yy) : x(xx), y(yy){}

    ll operator% (const pt &o) const {return x*o.y - y*o.x;} // cross
    ll operator* (const pt &o) const {return x*o.x + y*o.y;} // dot
    pt operator- (const pt &o) const {return pt(x-o.x,y-o.y);}
    pt operator+ (const pt &o) const {return pt(x+o.x,y-o.y);}
    bool operator< (const pt &o) const { // chull cmp
        if (x == o.x) return y < o.y;
        return x < o.x;
    }
    bool operator== (const pt &o) const {return (x == o.x && y == o.y);}
    bool cw (const pt &a, const pt &b) {return (b-a)%(*this-a) > 0;} // si es clockwise entre a, b y this
};

vector<pt> chull (pt p[], int n) {
    sort(p,p+n);
    vector<pt> r;
    forn(i,n) { // lower full
        while ((int)r.size() >= 2 && r.back().cw(r[(int)r.size()-2],p[i])) r.pop_back();
        r.pb(p[i]);
    }
    r.pop_back(); int k = r.size();
    dforn(i,n) { // lower full
        while ((int)r.size() >= k+2 && r.back().cw(r[(int)r.size()-2],p[i])) r.pop_back();
        r.pb(p[i]);
    }
    r.pop_back();
    return r;
}

pt poly[MAXN];

ld getArea (vector<pt> &p) { // Area of a Polygon, para el Edge Case
    ld r = 0;
    forn(i,p.size()) {
        int j = (i+1)%((int)p.size());
        r += ((p[j]-p[i])%(pt(0,0)-p[i]))/2.0;
    }
    return abs(r);
}

pair<ld,ld> dp[MAXN][MAXN]; // mini, maxi

ld solve (vector<pt> &chull) {
    int n = chull.size();
    forn(i,n) forsn(k,2,n) {
        pair<ld,ld> tmp = {INF,-INF}; // init
        forsn(j,1,k) { // si empiezo en i, saco el mayor y menor si termino en k, y paso por algún pto intermedio
            int i2 = (i+j)%((int)chull.size());
            int i3 = (i+k)%((int)chull.size());
            ld val = ((chull[i2]-chull[i])%(pt(0,0)-chull[i]))/2.0 + ((chull[i3]-chull[i2])%(pt(0,0)-chull[i2]))/2.0;
            tmp = {min(tmp.fst,val),max(tmp.snd,val)};
        }
        dp[i][(i+k)%n] = tmp; // hago min y max porque como uso productos cruces, para maximizar el valor absoluto me debe convenir alguno de los dos
    }
    forn(i,MAXN) forn(j,MAXN) { // para que valores no seteados no arruinen mi rta
        if (dp[i][j].fst == INF) dp[i][j].fst = 0;
        if (dp[i][j].snd == -INF) dp[i][j].snd = 0;
    }

    ld maxi = -1;
    forn(i,n) forsn(j,i+1,n) forsn(k,j+1,n) {
        ld acc = ((chull[j]-chull[i])%(pt(0,0)-chull[i]))/2.0 + ((chull[k]-chull[j])%(pt(0,0)-chull[j]))/2.0; // área que forman con los 3 puntos i,j,k fijos
        maxi = max({maxi,abs(acc+dp[k][i].fst),abs(acc+dp[k][i].snd)}); // uso la dp, probando tanto con min como max
    }
    return maxi;
}

ld edgeCase (vector<pt> &chull, pt a[], int n) {
    ld baseArea = getArea(chull);
    ld maxi = -1;
    forn(i,n) { // suponiendo que incluimos el punto i
        bool repeat = false;
        for (auto &j : chull) if (j == a[i]) {repeat = true; break;} // funciona sin ids porque se asegura que no hay dos puntos iguales (en mismo lugar)
        if (repeat) continue; // si ya está en la chull nos vamos

        forn(j,chull.size()) {
            int k = (j+1)%((int)chull.size());
            ld aux = ((a[i]-chull[j])%(chull[k]-a[i]))/2.0; // área triang que sacamos, si interponemos nuestro punto
            aux = abs(aux); // para no sumar lo que no debo por signo (el área no es negativa)
            maxi = max(maxi,baseArea-aux);
        }
    }

    return maxi;
}

int main() {
    FAST_IO;

    forn(i,MAXN) forn(j,MAXN) dp[i][j] = {INF,-INF}; // init

    int n; cin >> n;
    forn(i,n) cin >> poly[i].x >> poly[i].y;

    vector<pt> aux = chull(poly,n); // podemos ver que si lo hacemos con una chull, los puntos óptimos están sobre ella

    cout << fixed << setprecision(15); // aplicar propiedades
    if (aux.size() < 4) return cout << edgeCase(aux,poly,n),0; // si la chull me da justo de 3 puntos, podemos fuerza brutear el 4to
    cout << solve(aux); // resolvemos el caso general

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
