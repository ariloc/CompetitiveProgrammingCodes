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

int const MAXN = 5005;
int const MAXQ = 4000005;

struct pto{
    ll x, y;
    pto(ll x=0, ll y=0):x(x),y(y){}
    pto operator-(pto a){return pto(x-a.x, y-a.y);}
    ll operator^(pto a){return x*a.y-y*a.x;}
    pto operator+(pto a){return pto(x+a.x, y+a.y);}
    bool left(pto q, pto r){return ((q-*this)^(r-*this))>0;}
};

struct Cmp{//orden total de puntos alrededor de un punto r
    pto r;
    Cmp(pto r):r(r) {}
    int cuad(const pto &a) const{
        if(a.x > 0 && a.y >= 0)return 0;
        if(a.x <= 0 && a.y > 0)return 1;
        if(a.x < 0 && a.y <= 0)return 2;
        if(a.x >= 0 && a.y < 0)return 3;
        assert(a.x ==0 && a.y==0);
        return -1;
    }
    bool cmp(const pto&p1, const pto&p2)const{
        int c1 = cuad(p1), c2 = cuad(p2);
        if(c1==c2) return p1.y*p2.x<p1.x*p2.y;
        else return c1 < c2;
    }
    bool operator()(const pto&p1, const pto&p2) const{
    return cmp(pto(p1.x-r.x,p1.y-r.y),pto(p2.x-r.x,p2.y-r.y));
    }
};

pto pts[MAXN];
vector<pto> ords[MAXN];
int n,q; 

ii exts(int cen, pto a, pto b) {
    Cmp cmp = Cmp(pts[cen]);
    int i = lower_bound(all(ords[cen]), a, cmp)-ords[cen].begin();
    int j = lower_bound(all(ords[cen]), b, cmp)-ords[cen].begin();
    if (((a-pts[cen])^(b-pts[cen])) > 0)
        return {i,j};
    return {j,i};
}

int len(ii ex) {
    int i = ex.fst, j = ex.snd;
    if (i <= j) return j-i;
    return (n-1)-i + j;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        cin >> n >> q;
        forn(i,n) cin >> pts[i].x >> pts[i].y;

        forn(i,n) ords[i].clear();

        forn(i,n) {
            forn(j,n) if (j != i) ords[i].pb(pts[j]);
            sort(all(ords[i]), Cmp(pts[i]));
        }

        forn(i,q) {
            int a,b,c; cin >> a >> b >> c; --a, --b, --c;

            if (!pts[c].left(pts[a],pts[b])) swap(b,c);

            ii e1 = exts(a,pts[a]+(pts[a]-pts[c]),pts[b]), e2 = exts(b,pts[b]+(pts[b]-pts[a]),pts[c]), e3 = exts(c,pts[c]+(pts[c]-pts[b]),pts[a]);

            int ot = len(e1) + len(e2) + len(e3);
            cout << (ot == n-3 ? "YES" : "NO") << '\n';
        }
    }

    return 0;
}
