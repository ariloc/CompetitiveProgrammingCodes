// AC -> Aizu CGL 4A

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

const int INF = 1e9+5;

struct pt {
    double x,y;
    pt(double x, double y) : x(x),y(y){}
    pt(){}

    pt operator- (const pt &o) const {return pt(x-o.x, y-o.y);}
    double operator% (const pt &o) const {return x*o.y - y*o.x;} // cross product
    double operator* (const pt &o) const {return x*o.x + y*o.y;} // dot product
    bool operator< (const pt &o) const{ // chull sort cmp
        return (x < o.x || (x == o.x && y < o.y));
    }
    bool ccw (const pt &a, const pt &b) {return (b-a)%(*this-a) > 0;} // counter-clockwise
};

vector<pt> chull (vector<pt> p) {
    vector<pt> r;
    sort(all(p));
    forn (i,p.size()) { // lower hull
        while (r.size() >= 2 and r.back().ccw(r[r.size()-2],p[i])) r.pop_back();
        r.pb(p[i]);
    }
    r.pop_back(); int k = r.size();
    dforn (i,p.size()) { // upper hull
        while (r.size() >= k+2 and r.back().ccw(r[r.size()-2],p[i])) r.pop_back();
        r.pb(p[i]);
    }
    r.pop_back();
    return r;
}

int main() {
    FAST_IO;

    vector<pt> pts;
    int n; cin >> n;
    forn (i,n) {
        int x,y; cin >> x >> y;
        pts.pb(pt(x,y));
    }

    vector<pt> rta = chull(pts);
    int ind = -1; double mini = INF;
    forn (i,rta.size()) if (rta[i].y < mini) {mini = rta[i].y; ind = i;}

    cout << rta.size() << '\n';
    forn (i,rta.size()) {
        cout << rta[ind].x << ' ' << rta[ind].y << '\n';
        ind = (ind+1)%(int)(rta.size());
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
