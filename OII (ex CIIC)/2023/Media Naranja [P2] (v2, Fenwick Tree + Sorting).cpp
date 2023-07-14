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

struct range {
    int l,r,m,sz;

    bool operator< (const range &o) const {
        return sz < o.sz;
    }
};

vi pts;
vector<range> ranges;
int FT[MAXL];

void update (int &x) {
    x = lower_bound(all(pts),x)-pts.begin();
}

void setFT (int p, int v) {
    p += 3;
    for (int i = p; i < MAXL; i += i & -i)
        FT[i] += v;
}

int getFT (int p) {
    p += 3;
    int r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

int main() {
    int n; scanf("%d",&n);
    forn(i,n) {
        int l,r; scanf("%d %d",&l,&r);
        l *= 2, r *= 2;
        int mid = (l-r)/2 + r;
        ranges.pb({l,r,mid,(r-l)});
        pts.pb(l), pts.pb(r), pts.pb(mid);
    }

    sort(all(pts));
    pts.erase(unique(all(pts)),pts.end());
    for (auto &i : ranges) update(i.l), update(i.r), update(i.m);

    sort(all(ranges));

    ll cnt = 0;
    dforn(i,ranges.size()) {
        cnt += getFT(ranges[i].r) - getFT(ranges[i].l-1);
        setFT(ranges[i].m,1);
    }

    printf("%lld",cnt);
                  
    return 0;
}
