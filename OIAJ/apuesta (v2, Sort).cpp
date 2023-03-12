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
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const double EPS = 1e-3;
const int INF = 1e9;

struct pt {
    double x,y;
    pt(double x, double y) : x(x), y(y) {}
    pt(){}

    pt operator+ (const pt &o) const { return pt(x+o.x, y+o.y); }
    pt operator- (const pt &o) const { return pt(x-o.x, y-o.y); }
    double operator% (const pt &o) const { return x*o.y - y*o.x; } // cross
    double  operator* (const pt &o) const { return x*o.x + y*o.y; } // dot
    pt operator* (const double &o) const { return pt(x*o, y*o); } // product by scalar
    double norm2() { return *this**this; }
    double norm() { return sqrt(norm2()); }
    
    bool operator< (const pt &o) const { // cmp x,y
        return (x < o.x || (x == o.x && y < o.y));
    }

    // Is the current point counter-clockwise of the vector defined by (b-a) ?
    bool ccw (const pt &a, const pt &b) const {
        return (b-a)%(*this-a) >= 0;
    }

    bool operator== (const pt &o) const {
        return x == o.x && y == o.y;
    }
};

struct ln {
    pt x,xy;
    ln(pt x, pt xy) : x(x), xy(xy){}
    ln(){}

    bool isInline (const pt &p) const {
        return abs(xy % (x-p)) <= EPS;
    }

    pt intersect (const ln &o) const {
        double micro = ( xy % (x-o.x) ) / (double)(xy % o.xy);
        return o.x + (o.xy * micro);
    }
};

double calc (ln l, pt p) {
    pt aux = p - l.x;
    return (aux * l.xy) / aux.norm();
}

bool check (vector<pt> cities, pt sol) {
    ln aux = ln(sol, pt(0,1)); // vertical line
    
    vector<pt> left, right, inLine;
    for (auto &i : cities) {
        if (aux.isInline(i)) inLine.pb(i);
        else if (i.ccw(aux.x,aux.x+aux.xy)) left.pb(i);
        else right.pb(i);
    }

    int cnt1 = 0, cnt2 = 0;
    for (auto &i : inLine) {
        if (abs(sol.x-i.x) <= EPS && abs(sol.y-i.y) <= EPS) continue;
        if (calc(aux, i) < 0) cnt1++;
        else cnt2++;
    }

    if (cnt1 != cnt2) return false;

    auto cmp = [&](const pt &lhs, const pt &rhs){
        return calc(aux, lhs) < calc(aux, rhs);
    };

    sort(all(left),cmp);
    sort(all(right),cmp);
    reverse(all(right));

    if ((int)left.size() != (int)right.size()) return false;

    forn(i,left.size()) {
        pt ot = right[i];
        pt me = left[i];

        ln aux2 = ln(me, ot - me);

        if (!aux2.isInline(sol)) return false;
    }

    return true;
}

vector<double> apuesta(vector<int> &x, vector<int> &y) {
    vector<pt> cities;
    forn(i,x.size()) cities.pb(pt(x[i],y[i]));

    int n = (int)cities.size();
    if (n&1) {
        sort(all(cities));

        pt rta = cities[n/2];
        if (!check(cities,rta)) return {};
        return {(double)rta.x, (double)rta.y};
    }

    bool linedPoints = true;
    ln inlineLn = ln(cities[0], cities[0]-cities[1]);
    for (auto &i : cities) {
        if (!inlineLn.isInline(i)) {
            linedPoints = false; break;
        }
    }

    // all points are aligned...
    if (linedPoints) {
        sort(all(cities));
        pt a = cities[n/2-1], b = cities[n/2];
        return {(a.x+b.x)/2.0, (a.y+b.y)/2.0};
    }

    vector<ln> toIntersect;

    sort(all(cities));
    pt chosen = cities[0], chosen2 = cities[0]+pt(0,1);
    forsn(i,1,n) {
        if (cities[i].ccw(chosen2, chosen))
            chosen2 = cities[i];
    }
    
    ln chosenln = ln(chosen, chosen-chosen2);

    cities.erase(cities.begin());
    n = (int)cities.size();

    sort(all(cities), [&](const pt &lhs, const pt &rhs) {
        return calc(chosenln,lhs) < calc(chosenln,rhs);
    });
    toIntersect.pb( ln(chosen, cities[n/2]-chosen) );

    cities.pb(chosen); // reinsert deleted
    n = (int)cities.size();

    chosenln = ln( chosen2, chosen-chosen2 );
    chosen = chosen2;

    if (toIntersect[0].isInline(chosen))
        return {};

    cities.erase(find(all(cities),chosen));
    n = (int)cities.size();

    sort(all(cities), [&](const pt &lhs, const pt &rhs) {
        return calc(chosenln,lhs) < calc(chosenln,rhs);
    });
    toIntersect.pb( ln(chosen, cities[n/2]-chosen ));

    pt rta = toIntersect[0].intersect(toIntersect[1]);

    cities.pb(chosen); // reinsert deleted

    if (check(cities,rta))
        return {(double)rta.x, (double)rta.y};
    return {};
}

