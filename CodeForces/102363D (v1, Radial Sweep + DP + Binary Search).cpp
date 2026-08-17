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

    // comb triang + pto
    ll conc = n * (ll)(n-1) * (n-2) * (n-3) / 6LL;
    ll simp = 0;

    // restar triang + pto no contenido
    forn(i,n) {
        vector<pt> curp;
        forn(j,n) if (i != j) curp.pb(pts[j]);
        Cmp c(pts[i]);
        sort(all(curp),c);

        int m = n-1;
        forn(j,m) {
            pt cur = curp[j]-pts[i];
            pt op = cur * (-1);
            int idx = (lower_bound(all(curp),pts[i]+op,c)-curp.begin())%m;

            int cntr;
            if (j >= idx) cntr = j-idx;
            else cntr = m-idx + j;
            int cntl = m-1-cntr;

            conc -= cntl * (ll)cntr;
            simp += cntl * (ll)cntr;
        }
        
        // sumar lo restado doble
        vector<pt> op;
        forn(j,n) if (i != j) op.pb(pts[i] + ((pts[j]-pts[i])*(-1)));
        sort(all(op),c);

        vi acc;
        forn(j,m) {
            int idxr = (lower_bound(all(curp),op[j],c)-curp.begin())%m;
            int idxl = (lower_bound(all(curp),op[(j-1+m)%m],c)-curp.begin())%m;

            int auxi;
            if (idxl <= idxr) auxi = idxr-idxl;
            else auxi = m-idxl + idxr;

            acc.pb(auxi);
        }

        vi dp;
        forn(k,2) dp.pb(0); // dummy;
        for (auto &j : acc) dp.pb(j);
        for (auto &j : acc) dp.pb(j);
        forsn(j,1,sz(dp)) dp[j] += dp[j-1];

        vi dp2 = dp;
        forsn(j,1,sz(dp2)) dp2[j] += dp2[j-1];

        forn(j,m) {
            pt opcur = pts[i] + ((op[j]-pts[i]) * (-1));
            int idx = (lower_bound(all(op),opcur,c)-op.begin())%m;
            int auxi;
            if (j >= idx) auxi = j-idx;
            else auxi = m-idx + j;

            int r = 2+m+j, l = 2+m+j-auxi;
            int len = r-l;
            conc += len * (ll)dp[r] - (dp2[r-1] - dp2[l-1]);
        }
    }
    
    // conc tiene cant triang + pto donde pto está dentro
    // por c/u hay 3 polígonos cóncavos
    conc *= 3LL;
    
    // simp tiene todo duplicado, y cuadriplicado para convexos
    simp /= 2LL;

    // contamos todos los polígonos simples, restando tenemos los convexos
    // está duplicado simp para convexos, dividimos por dos
    cout << (simp - conc)/2LL << '\n';

    return 0;
}
