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

    double norm2() {return (*this) * (*this);} // modulo of vector, squared
    double norm() {return sqrt(norm2());}
    pt operator* (const double &t) const {return pt(x*t,y*t);}
    pt operator- (const pt &o) const {return pt(x-o.x, y-o.y);}
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
        while (r.size() >= k+2 and r.back().left(r[r.size()-2],p[i])) r.pop_back();
        r.pb(p[i]);
    }
    r.pop_back();
    return r;
}

struct poly {
    int n; vector<pt> p;
    poly(){}
    poly(vector<pt> _p) {p=_p; n=p.size();}

    double callipers() { // returns square of max dist
        double r = 0;
        int j = (n >= 2); // doesn't exist if there's no such pair of points
        forn (i,j) {
            for(;;j=(j+1)%n) {
                r = max(r,(p[i]-p[j]).norm2());
                if ( ((p[(i+1)%n] - p[i]) % (p[(j+1)%n] - p[j])) < -EPS) break;
            }
        }
        return r;
    }
};

vector<pt> p;

int main() {
    FAST_IO;

    int n; cin >> n;

    forn (i,n) {
        double x,y; cin >> x >> y;
        p.pb({x,y});
    }

    cout << setprecision(10) << sqrt(poly(chull(p)).callipers());

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
