#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define sz(c) (c).size()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

#define PI acos(-1)

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

double const EPS = 1e-8;

struct pt {
    double x,y;
    pt(double xx, double yy) : x(xx), y(yy) {}
    double operator*(const pt &o) const {
        return x*o.x+y*o.y;
    }
    double operator%(const pt &o) const{
        return x*o.y-y*o.x;
    }
    pt operator*(const double &o) const{
        return pt(o*x,o*y);
    }
    pt operator+(const pt &o) const {
        return pt(x+o.x,y+o.y);
    }
    pt operator-(const pt &o) const {
        return pt(x-o.x,y-o.y);
    }
    pt operator/(const double &o) const {
        return pt(x/o,y/o);
    }
    double angle(pt o) {
        return acos((*this*o)/(norm()*o.norm()));
    }
    double norm2(){return *this**this;}
    double norm(){return sqrt(norm2());}
    pt rot(pt r){return pt(*this%r,*this*r);}
    pt rot(double a){return rot(pt(sin(a),cos(a)));}
    
};
pt ccw90(1,0); pt cw90(-1,0); 

struct circle {
    pt o; double r;
    circle(pt o, double r):o(o),r(r){}
    vector<pt> operator^(circle c) {
        vector<pt> s;
        double d=(o-c.o).norm();
        if(d>r+c.r+EPS||d+min(r,c.r)+EPS<max(r,c.r))return s;
        double x=(d*d-c.r*c.r+r*r)/(2*d);
        double y=sqrt(r*r-x*x);
        pt v=(c.o-o)/d;
        s.pb(o+v*x-v.rot(ccw90)*y);
        if(y>EPS)s.pb(o+v*x+v.rot(ccw90)*y);
        return s;
    }
    bool in(const circle &c) {
        return ((o-c.o).norm()+r)-c.r < EPS;
    }
};

struct Cmp {
    pt r;
    Cmp(pt r):r(r){}
    int cuad(const pt &a)const {
        if(a.x>0&&a.y>=0)return 0;
        if(a.x<=0&&a.y>0)return 1;
        if(a.x<0&&a.y<=0)return 2;
        if(a.x>=0&&a.y<0)return 3;
        assert(a.x==0&&a.y==0);
        return -1;
    }
    bool cmp(const pt &p1, const pt &p2) const {
        int c1=cuad(p1),c2=cuad(p2);
        if(c1==c2)return p1.y*p2.x<p1.x*p2.y;
        return c1<c2;
    }
    bool operator()(const pt &p1, const pt &p2) const {
        return cmp(p1-r,p2-r);
    }
};

vector<double> intercircles(vector<circle> c) {
    vector<double> r(sz(c)+1);
    forn(i,sz(c)) {
        int k=1;Cmp s(c[i].o);
        vector<pair<pt,int>> p={
            {c[i].o+pt(1,0)*c[i].r,0},
            {c[i].o-pt(1,0)*c[i].r,0}
        };
        forn(j,sz(c))if(j!=i){
            bool b0=c[i].in(c[j]),b1=c[j].in(c[i]);
            if(b0&&(!b1||i<j))k++;
            else if(!b0&&!b1){
                auto v=c[i]^c[j];
                if(sz(v)==2){
                    p.pb({v[0],1});p.pb({v[1],-1});
                    if(s(v[1],v[0]))k++;
                }
            }
        }
        sort(p.begin(),p.end(),
            [&](pair<pt,int> a, pair<pt,int> b){return s(a.fst,b.fst);});
        forn(j,sz(p)){
            pt p0=p[j?j-1:sz(p)-1].fst,p1=p[j].fst;
            double a=(p0-c[i].o).angle(p1-c[i].o);
            r[k]+=(p0.x-p1.x)*(p0.y+p1.y)/2+c[i].r*c[i].r*(a-sin(a))/2;
            k+=p[j].snd;
        }
    }
    return r;
}

int main() {
    FAST_IO;
    
    double xa,ya,ra; cin >> xa >> ya >> ra;
    double xb,yb,rb; cin >> xb >> yb >> rb;
    
    circle a = circle(pt(xa,ya),ra), b = circle(pt(xb,yb),rb);
    
    vector<double> auxi = intercircles({a,b});
    
    cout << fixed << setprecision(10) << auxi[1] << '\n';
    
    return 0;
}
