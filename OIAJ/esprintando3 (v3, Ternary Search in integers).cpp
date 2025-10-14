#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define pb push_back
#define fst first
#define snd second
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

double const INF = 9e18;
int const MAXN = 2e5+5;
ld const EPS = 1e-9;

struct pt {
    ll x,y;
    pt(ll x, ll y) : x(x), y(y){};
    pt(){}

    pt operator- (const pt &o) const { return {x-o.x,y-o.y}; }
    ll operator* (const pt &o) const { return x*o.x + y*o.y; }
    ll norm1() {
        return abs(x) + abs(y);
    }
    double norm2() {
        return (double)sqrtl((ld)x*x + (ld)y*y);
    }
};

vector<pt> pts;
double lm,rm;
ll prefs[MAXN];
int n;
ll k;

ll dif (int i, int j) {
    return (pts[i]-pts[j]).norm1();
}

pt addv (pt cur, ll v, pt a, pt b) {
    if (a.x == b.x) { // dy
        int sign = b.y - a.y > 0 ? 1 : -1;
        cur.y += v * sign;
    }
    else { // dx
        int sign = b.x - a.x > 0 ? 1 : -1;
        cur.x += v * sign;
    }
    return cur;
}

double dist (pt a1, pt b1, pt a2, pt b2, ll mid) {
    pt e1 = addv(a1,mid,a1,a2), e2 = addv(b1,mid,b1,b2);
    return (e2-e1).norm2();
}

void ternary(pt a1, pt b1, pt a2, pt b2) {
    ll low = 0, high = min((a2-a1).norm1(), (b2-b1).norm1())-1;
    while (high-low > 1) {
        ll mid = (low+(ll)high)/2LL;
        if (dist(a1,b1,a2,b2,mid) - dist(a1,b1,a2,b2,mid+1) < EPS)
            high = mid;
        else low = mid;
    }
    double d = dist(a1,b1,a2,b2,high);
    lm = min(lm, d);
    rm = max(rm, d);
}

// i is start of segment, j is end
void compute_segs(int i, int j) {
    ll sob = prefs[(j-1+n)%n] - prefs[i];
    ll off = sob - k;
    if (off > dif((i+1)%n,i))
        return;
    if (abs(off) > dif(j,(j-1+n)%n))
        return;

    if (off > EPS) {
        pt st = addv(pts[i],off,pts[i],pts[(i+1)%n]);
        pt nd = pts[(j-1+n)%n];
        lm = min(lm, (st-nd).norm2());
        rm = max(rm, (st-nd).norm2());

        ll diff = min((pts[(i+1)%n] - st).norm1(), (pts[j]-nd).norm1());
        pt st2 = addv(st,diff,pts[i],pts[(i+1)%n]);
        pt nd2 = addv(nd,diff,pts[(j-1+n)%n],pts[j]);

        ternary(st,nd,st2,nd2);

        lm = min(lm, (st2-nd2).norm2());
        rm = max(rm, (st2-nd2).norm2());
    } else {
        off = abs(off);

        pt st = pts[i];
        pt nd = addv(pts[(j-1+n)%n],off,pts[(j-1+n)%n],pts[j]);
        lm = min(lm, (st-nd).norm2());
        rm = max(rm, (st-nd).norm2());

        ll diff = min((pts[(i+1)%n] - st).norm1(), (pts[j]-nd).norm1());
        pt st2 = addv(st,diff,pts[i],pts[(i+1)%n]);
        pt nd2 = addv(nd,diff,pts[(j-1+n)%n],pts[j]);
        
        ternary(st,nd,st2,nd2);
        
        lm = min(lm, (st2-nd2).norm2());
        rm = max(rm, (st2-nd2).norm2());
    }
}

vector<double> esprintando(int K, vector<int> &X, vector<int> &Y) {
    n = 2*(int)X.size();
    K *= 2;
    k = K;
    forn(_,2) forn(i,X.size()) pts.pb({2*X[i],2*Y[i]});

    forsn(i,1,n+1) prefs[i] = prefs[i-1] + dif(i-1,i%n);

    lm = INF, rm = -INF;

    int idx = 0; ll acc = 0;
    forsn(i,1,n) {
        acc += dif(i-1,i);
        while (idx < n && acc-dif(idx,(idx+1)%n) >= K) {
            compute_segs(idx,i);
            acc -= dif(idx,(idx+1)%n);
            idx++;
        }
        compute_segs(idx,i);
    }

    return {lm/(double)2,rm/(double)2};
}
