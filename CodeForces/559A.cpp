#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

double const PI = acos(-1);
double const ANG = 60*PI/180;
double const AREAT = (sqrt(.75)*.5);

struct pt {
    double x,y;
    pt (double x, double y):x(x),y(y){}
    pt(){}
    double norm2(){return *this**this;}
    double norm(){return sqrt(norm2());}
    pt operator+(pt p){return pt(x+p.x,y+p.y);}
    pt operator-(pt p){return pt(x-p.x,y-p.y);}
    pt operator*(double t){return pt(x*t,y*t);}
    pt operator/(double t){return pt(x/t,y/t);}
    double operator*(pt p){return x*p.x+y*p.y;}
    double operator%(pt p){return x*p.y-y*p.x;}
    pt rot(pt r){return pt(*this%r,*this*r);}
    pt rot(double a){return rot(pt(sin(a),cos(a)));}
};

struct pol{
    int n;vector<pt> p;
    pol(){}
    pol(vector<pt> _p){p=_p;n=p.size();}
    double area(){
        double r=0.;
        forsn(i,0,n)r+=p[i]%p[(i+1)%n];
        return abs(r)/2;
    }
};

int main() {
    FAST_IO;

    vi vec;
    forn(i,6) {
        int x; cin >> x;
        vec.pb(x);
    }
    
    pt cur={-vec[0],0};
    vector<pt> poly;
    poly.pb(cur);
    forsn(i,1,6) {
        cur = (cur/cur.norm())*vec[i];
        cur = cur.rot(ANG);
        poly.pb(poly.back()+cur);
    }

    pol p = pol(poly);

    int cnt = p.area()/AREAT;

    cout << cnt << '\n';

    return 0;
}
