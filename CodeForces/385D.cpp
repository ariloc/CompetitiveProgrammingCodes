#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= 0; i--)
#define forsn(i,s,n) for(int i = 0; i < int(n); i++)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);

#define PI acos(-1)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

struct light {
    int x,y,a;
};

int const MAXN = 21;
double const INF = 1e9;

double dp[1<<MAXN];
light ls[MAXN];

const double EPS=1e-9;
struct pto{
	double x, y;
	pto(double x=0, double y=0):x(x),y(y){}
	pto operator+(pto a){return pto(x+a.x, y+a.y);}
	pto operator-(pto a){return pto(x-a.x, y-a.y);}
	pto operator+(double a){return pto(x+a, y+a);}
	pto operator*(double a){return pto(x*a, y*a);}
	pto operator/(double a){return pto(x/a, y/a);}
	//dot product, producto interno:
	double operator*(pto a){return x*a.x+y*a.y;}
	//module of the cross product or vectorial product:
	//if a is less than 180 clockwise from b, a^b>0
	double operator^(pto a){return x*a.y-y*a.x;}
	//returns true if this is at the left side of line qr
	bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
	bool operator<(const pto &a) const{return x<a.x-EPS || (abs(x-a.x)<EPS && y<a.y-EPS);}
    bool operator==(pto a){return abs(x-a.x)<EPS && abs(y-a.y)<EPS;}
	double norm(){return sqrt(x*x+y*y);}
	double norm_sq(){return x*x+y*y;}
};

//rotate p by theta rads CCW w.r.t. origin (0,0)
pto rotate(pto p, double theta){
	return pto(p.x*cos(theta)-p.y*sin(theta),
     p.x*sin(theta)+p.y*cos(theta));
}

int sgn(ll x){return x<0? -1 : !!x;}
struct line{
	line() {}
	double a,b,c;//Ax+By=C
//pto MUST store float coordinates!
	line(double a, double b, double c):a(a),b(b),c(c){}
	line(pto p, pto q): a(q.y-p.y), b(p.x-q.x), c(a*p.x+b*p.y) {}
	int side(pto p){return sgn(ll(a) * p.x + ll(b) * p.y - c);}
};

pto inter(line l1, line l2){//intersection
	double det=l1.a*l2.b-l2.a*l1.b;
	if(abs(det)<EPS) return pto(INF, INF);//parallels
	return pto(l2.b*l1.c-l1.b*l2.c, l1.a*l2.c-l2.a*l1.c)/det;
}

int main() {
    int n,l,r; cin >> n >> l >> r;
    forn(i,n) {
        int x,y,a; cin >> x >> y >> a;
        ls[i] = {x,y,a};
    }
    
    forn(i,1<<n) dp[i] = -INF;

    dp[0] = l;
    forn(mk,1<<n) {
        forn(j,n) if (mk&(1<<j)) {
            int ant = mk ^ (1<<j);
            double pval = dp[ant];
            pto li = pto(ls[j].x,ls[j].y);
            pto p = pto(pval,0)-li;
            pto rot = rotate(p,ls[j].a*PI/(double)180);
            line ln = line(li,li+rot);
            line ln2 = line(pto(0,0),pto(1,0));
            pto it = inter(ln,ln2);
            
            if (it.x - pval < EPS) {
                dp[mk] = r;
                continue;
            }
            
            dp[mk] = max(dp[mk], it.x);
        }
    }

    double maxi = -INF;
    forn(i,1<<n) maxi = max(maxi,dp[i]);

    cout << fixed << setprecision(8) << min(maxi-l, (double)r-l);

    return 0;
}
