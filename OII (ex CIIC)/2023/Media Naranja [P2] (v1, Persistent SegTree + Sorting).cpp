#include <algorithm>
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

int const MAXN = 2e5+5;
int const MAXL = 4*MAXN;
int const MAXBAG = 1e7+5;

struct range {
    int l,r,m;

    bool operator< (const range &o) const {
        return m < o.m;
    }
};

struct mon {
    int v,l,r;

    mon(){v = 0, l = r = -1;}
    mon(int a, int b, int c) : v(a), l(b), r(c){}

    mon operator+ (const mon &o) const {
        return mon(v+o.v,l,o.r);
    }
};

vi pts;
vector<range> ranges;
mon bag[MAXBAG];
int szbag = 0;

int newNode (int i) {
    if (i != -1) bag[szbag] = bag[i];
    return szbag++;
}

int update (int i, int p, int v, int tl = 0, int tr = MAXL) {
    i = newNode(i);

    if (tr-tl <= 1) {
        bag[i].v += v;
        return i;
    }

    int mid = (tl+tr)/2;
    if (p >= mid) bag[i].r = update(bag[i].r,p,v,mid,tr);
    else bag[i].l = update(bag[i].l,p,v,tl,mid);
    bag[i].v = (bag[i].l == -1 ? 0 : bag[bag[i].l].v) + (bag[i].r == -1 ? 0 : bag[bag[i].r].v);
    
    return i;
}

mon query (int i, int bl, int br, int tl = 0, int tr = MAXL) {
    if (i == -1 || tr <= bl || tl >= br) return mon();
    if (tl >= bl && tr <= br) return bag[i];

    int mid = (tl+tr)/2;
    return query(bag[i].l,bl,br,tl,mid) + query(bag[i].r,bl,br,mid,tr);
}

vi versions = {-1};

void update (int &x) {
    x = lower_bound(all(pts),x)-pts.begin();
}

int main() {
    int n; scanf("%d",&n);
    forn(i,n) {
        int l,r; scanf("%d %d",&l,&r);
        l *= 2, r *= 2;
        int mid = (l-r)/2 + r;
        ranges.pb({l,r,mid});
        pts.pb(l), pts.pb(r), pts.pb(mid);
    }

    sort(all(pts));
    pts.erase(unique(all(pts)),pts.end());
    for (auto &i : ranges) update(i.l), update(i.r), update(i.m);

    sort(all(ranges));

    for (auto &i : ranges) 
        versions.pb(update(versions.back(),i.r,1));

    ll cnt = 0;
    forn(i,ranges.size()) {
        range act = ranges[i];
        int indl = lower_bound(all(ranges),act.l,[](const range &lhs, const int &rhs){
            return lhs.m < rhs;
        })-ranges.begin();
        cnt += query(versions[i],act.m,MAXL).v - query(versions[indl],act.m,MAXL).v;
    }

    printf("%lld",cnt);
              
    return 0;
}
