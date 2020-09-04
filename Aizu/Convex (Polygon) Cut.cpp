// AC -> Aizu CGL 4B

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

const double EPS = 1e-6; // margin of error

struct pt {
    double x,y;
    pt(double x, double y) : x(x),y(y){}
    pt(){}

    double norm2() {return (*this) * (*this);} // se demuestra que devuelve el cuadrado del módulo
    double norm() {return sqrt(norm2());} // entonces este devuelve el módulo
    pt operator+ (const pt &o) const {return pt(x+o.x,y+o.y);}
    pt operator- (const pt &o) const {return pt(x-o.x,y-o.y);}
    pt operator* (const double &t) const {return pt(x*t,y*t);}
    pt operator/ (const double &t) const {return pt(x/t,y/t);}
    double operator* (const pt &o) const {return x*o.x + y*o.y;} // dot
    double operator% (const pt &o) const {return x*o.y - y*o.x;} // cross
    bool operator< (const pt &o) const { // comp chull
        return (x < o.x || (x == o.x && y < o.y));
    }
    bool operator== (const pt &o) const {return (abs(o.x-x) < EPS and abs(o.y-y) < EPS);}
    bool left (const pt &a, const pt &b) {return (b-a)%(*this-a) > EPS;} // left of directed line ab?
    pt unit(){return (*this/norm());} // devuelve el vector unitario, al dividir por el módulo
};

struct ln {
    pt p,pq; // [lambda]v + p || v is pq and p is...well p
    ln(pt p, pt q) : p(p),pq(q-p){} // start point and direction
    ln(){}

    bool operator/ (ln o) {return (abs(pq.unit()%o.pq.unit()) < EPS);} // recordar que pq preserva la dirección, lo trato como vector libre
    pt operator^ (const ln &o) const { // intersection (need to intersect)
        double div = (pq%o.pq);
        return (o.p+o.pq*((pq%(p-o.p))/div)); // "Agustín trick" :v
    }
};

struct poly {
    int n; vector<pt> p;
    poly(vector<pt> _p){p=_p; n = p.size();}
    poly(){}

    double area() {
        double r = 0;
        forn (i,n) r += p[i]%p[(i+1)%n];
        return abs(r)/2;
    }

    poly cut (pt a, pt b) {
        vector<pt> r;
        forn (i,n) {
            bool k = p[i].left(a,b), l = p[(i+1)%n].left(a,b);
            if (k) r.pb(p[i]);
            ln m(p[i],p[(i+1)%n]);
            if (k != l) r.pb(ln(a,b)^m);
        }
        return poly(r);
    }
};

vector<pt> p;
poly mePol;

int main() {
    FAST_IO;

    //freopen("tmp.txt","w",stdout);

    int n; cin >> n;
    forn (i,n) {
        double a,b; cin >> a >> b;
        p.pb({a,b});
    }
    mePol = poly(p);

    int q; cin >> q;
    forn (i,q) {
        double x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        pt A = {x1,y1}, B = {x2,y2};

        cout << setprecision(13) << (mePol.cut(A,B)).area() << '\n';

    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
