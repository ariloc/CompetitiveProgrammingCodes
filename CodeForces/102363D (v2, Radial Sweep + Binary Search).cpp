#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 2005;
double const EPS = 1e-8;

struct pt {  // for 3D add z coordinate
    int x,y;
    pt(int x, int y):x(x),y(y){}
    pt(){}
    bool operator==(pt p){return !abs(x-p.x)&&!abs(y-p.y);}
    pt operator+(pt p){return pt(x+p.x,y+p.y);}
    pt operator-(pt p)const{return pt(x-p.x,y-p.y);}
    pt operator*(int t){return pt(x*t,y*t);}
    int operator*(pt p){return x*p.x+y*p.y;}
    int operator%(pt p){return x*p.y-y*p.x;}
    bool left(pt p, pt q){ // is it to the left of directed line pq?
        return (q-p)%(*this-p)>EPS;}
};

struct Cmp {
    pt r;
    Cmp(){}
    Cmp(pt r):r(r){}
    int cuad(const pt &a)const {
        if(a.x>0&&a.y>=0)return 0;
        if(a.x<=0&&a.y>0)return 1;
        if(a.x<0&&a.y<=0)return 2;
        if(a.x>=0&&a.y<0)return 3;
        assert(a.x==0&&a.y==0);
        return -1;
    }
    bool cmp(const pt& p1, const pt& p2)const {
        int c1=cuad(p1),c2=cuad(p2);
        if(c1==c2)return p1.y*p2.x<p1.x*p2.y;
        return c1<c2;
    }
    bool operator()(const pt& p1, const pt& p2)const {
        return cmp(p1-r,p2-r);
    }
};

pt pts[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> pts[i].x >> pts[i].y;

    ll conc = 0;

    forn(i,n) {
        vector<pt> curp;
        forn(j,n) if (i != j) curp.pb(pts[j]);
        Cmp c(pts[i]);
        sort(all(curp),c);

        // triángulos que no me contienen.
        // sweep radial, lo tomo a cada uno por el "primero" que aparece en el orden.
        // es decir, considero todos los triangulos posibles a partir del nodo tal que el triańgulo
        // resultante se encuentra en un lado del semiplano definido por el punto actual y el extremo
        // dado del triángulo.
        // notar que si el punto está fuera, entonces tiene que existir una recta tal que el triángulo
        // esté a un lado de la recta.
        // como no hay triángulos degenerados, a lo sumo hay dos de esas que tocan algún vértice.
        // tomamos solo una, la que se obtiene al hacer un sweep cw.
        int m = n-1;
        ll cnt = 0;
        forn(j,m) {
            pt cur = curp[j]-pts[i];
            pt op = cur * (-1);
            int idx = (lower_bound(all(curp),pts[i]+op,c)-curp.begin())%m;

            int cntr;
            if (j >= idx) cntr = j-idx;
            else cntr = m-idx + j;
            int cntl = m-1-cntr;

            cnt += (ll)cntr * (cntr-1) / 2LL;
        }
        conc += (n-1) * (ll)(n-2) * (n-3) / 6LL - cnt;
    }

    cout << n * (ll)(n-1) * (n-2) * (n-3) / 24LL - conc << '\n';

    return 0;
}
