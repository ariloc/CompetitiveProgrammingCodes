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

const double INF = 1e7;
const double EPS = 1e-6; // margin of error

struct pt {
    double x,y;
    pt(double xx, double yy) : x(xx),y(yy){}
    pt(){}

    double norm2() {return (*this) * (*this);} // modulo of vector, squared
    double norm() {return sqrt(norm2());}
    pt operator* (const double &t) const {return pt(x*t,y*t);}
    pt operator- (const pt &o) const {return pt(x-o.x, y-o.y);}
    pt operator+ (const pt &o) const {return pt(x+o.x, y+o.y);}
    double operator% (const pt &o) const {return x*o.y - y*o.x;} // cross product
    double operator* (const pt &o) const {return x*o.x + y*o.y;} // dot product
    bool operator< (const pt &o) const { // chull sort cmp
        return (x < o.x || (x == o.x && y < o.y));
    }
    bool left (const pt &a, const pt &b) {return (b-a)%(*this-a) > EPS;}
};

vector<pt> chull (vector<pt> &p) {
    vector<pt> r;
    sort(all(p));
    forn (i,p.size()) { // lower hull
        while (r.size() >= 2 and r.back().left(r[r.size()-2],p[i])) r.pop_back();
        r.pb(p[i]);
    }
    r.pop_back(); int k = r.size();
    dforn (i,p.size()) { // upper hull
        while ((int)r.size() >= k+2 and r.back().left(r[r.size()-2],p[i])) r.pop_back();
        r.pb(p[i]);
    }
    r.pop_back();
    return r;
}

vector<pt> p;

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(j,n) {
        double x,y; cin >> x >> y;
        p.pb({x,y});
    }

    p = chull(p);
    n = p.size();

    double mini = INF;
    forn(j,n) {
        pt me = p[(j+1)%n]-p[j];
        for (int k = (j+2)%n; k != j; k = (k+1)%n) {
            pt aux = p[k]+me;
            bool posib = true;
            forn(l,n) {
                double prod1 = (me%(p[l]-p[j])), prod2 = ((aux-p[k])%(p[l]-p[k]));
                if ((prod1 < EPS && prod1 > -EPS) || (prod2 < EPS && prod2 > -EPS)) continue;
                bool cond1 = p[l].left(p[j],p[(j+1)%n]), cond2 = p[l].left(p[k],aux);
                if (cond1 == cond2) {posib = false; break;}
            }
            //if (p[j].x == 220 && posib) cerr << p[j].x << ' ' << p[j].y << ' ' << p[(j+1)%n].x << ' ' << p[(j+1)%n].y << ' ' << p[k].x << ' ' << p[k].y << ' ' <<  aux.x << ' ' << aux.y << endl;
            if (posib) {
                pt perp = {-me.y,me.x}; // perpendicular
                pt ext_ext = (p[k]-p[j]);
                mini = min(mini,(perp*ext_ext)/perp.norm()); // la proyección a la normal
            }
        }
    }

    cout << setprecision(10) << fixed << mini;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
