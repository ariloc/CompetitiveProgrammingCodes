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
    ld x,y;
    pt(ld x, ld y) : x(x), y(y){};
    pt(){}

    pt operator- (const pt &o) const { return {x-o.x,y-o.y}; }
    ll operator* (const pt &o) const { return x*o.x + y*o.y; }
    ld norm1() {
        return abs(x) + abs(y);
    }
    ld norm2() {
        return (double)sqrtl((ld)x*x + (ld)y*y);
    }
};

vector<pt> pts;
ld lm,rm;
ld prefs[MAXN];
int n,k;

ld dif (int i, int j) {
    return (pts[i]-pts[j]).norm1();
}

pt addv (pt cur, ld v, pt a, pt b) {
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

void compute_midpoint(pt a1, pt a2, pt b1, pt b2) {
    if (b2.x == b1.x && a1.x == a2.x && (b1.y-b2.y != 0) && (a1.y-a2.y != 0) && (b1.y-b2.y > 0) != (a1.y-a2.y > 0)) { // misma dir dy, sentido op
        bool ok = false;
        if (a1.y > a2.y) swap(a1,a2);
        if (b1.y > b2.y) swap(b1,b2);
        if (a1.y <= b1.y && b1.y <= a2.y) ok = true;
        if (a1.y <= b2.y && b2.y <= a2.y) ok = true;
        if (b1.y <= a1.y && a1.y <= b2.y) ok = true;
        if (b1.y <= a2.y && a2.y <= b2.y) ok = true;
        if (ok) {
            lm = min(lm,(ld)abs(a1.x-b1.x));
            rm = max(rm,(ld)abs(a1.x-b1.x));
        }
    }
    else if (b2.y == b1.y && a1.y == a2.y && (b1.x-b2.x != 0) && (a1.x-a2.x != 0) && (b1.x-b2.x > 0) != (a1.x-a2.x > 0)) { // misma dir dx, sentido op
        bool ok = false;
        if (a1.x > a2.x) swap(a1,a2);
        if (b1.x > b2.x) swap(b1,b2);
        if (a1.x <= b1.x && b1.x <= a2.x) ok = true;
        if (a1.x <= b2.x && b2.x <= a2.x) ok = true;
        if (b1.x <= a1.x && a1.x <= b2.x) ok = true;
        if (b1.x <= a2.x && a2.x <= b2.x) ok = true;
        if (ok) {
            lm = min(lm,(ld)abs(a1.y-b1.y));
            rm = max(rm,(ld)abs(a1.y-b1.y));
        }
    }
}

void compute_45deg(pt a1, pt a2, pt b1, pt b2) {
    if ((a1.x == a2.x) == (b1.x == b2.x))
        return;

    pt d = b1-a1;
    ld off1 = abs(d.x-d.y)/2, off2 = abs(d.x+d.y)/2;
    auto calc = [&](const ld &off) {
        if ((a2-a1).norm2()-off > -EPS && (b2-b1).norm2()-off > -EPS) {
            pt ex1 = addv(a1,off,a1,a2), ex2 = addv(b1,off,b1,b2);
            lm = min(lm, (ex2-ex1).norm2());
        }
    };
    calc(off1);
    calc(off2);
}

// i is start of segment, j is end
void compute_segs(int i, int j) {
    ld sob = prefs[(j-1+n)%n] - prefs[i];
    ld off = sob - k;
    if (off-dif((i+1)%n,i) > EPS)
        return;
    if (abs(off)-dif(j,(j-1+n)%n) > EPS)
        return;

    if (off > EPS) {
        pt st = addv(pts[i],off,pts[i],pts[(i+1)%n]);
        pt nd = pts[(j-1+n)%n];
        lm = min(lm, (st-nd).norm2());
        rm = max(rm, (st-nd).norm2());

        ld diff = min((pts[(i+1)%n] - st).norm1(), (pts[j]-nd).norm1());
        pt st2 = addv(st,diff,pts[i],pts[(i+1)%n]);
        pt nd2 = addv(nd,diff,pts[(j-1+n)%n],pts[j]);

        compute_midpoint(st,st2,nd,nd2);
        compute_45deg(st,st2,nd,nd2);

        lm = min(lm, (st2-nd2).norm2());
        rm = max(rm, (st2-nd2).norm2());
    } else {
        off = abs(off);

        pt st = pts[i];
        pt nd = addv(pts[(j-1+n)%n],off,pts[(j-1+n)%n],pts[j]);
        lm = min(lm, (st-nd).norm2());
        rm = max(rm, (st-nd).norm2());

        ld diff = min((pts[(i+1)%n] - st).norm1(), (pts[j]-nd).norm1());
        pt st2 = addv(st,diff,pts[i],pts[(i+1)%n]);
        pt nd2 = addv(nd,diff,pts[(j-1+n)%n],pts[j]);
        
        compute_midpoint(st,st2,nd,nd2);
        compute_45deg(st,st2,nd,nd2);
        
        lm = min(lm, (st2-nd2).norm2());
        rm = max(rm, (st2-nd2).norm2());
    }
}

vector<double> esprintando(int K, vector<int> &X, vector<int> &Y) {
    n = 2*(int)X.size();
    k = K;
    forn(_,2) forn(i,X.size()) pts.pb({(ld)X[i],(ld)Y[i]});

    forsn(i,1,n+1) prefs[i] = prefs[i-1] + dif(i-1,i%n);

    lm = INF, rm = -INF;

    int idx = 0; ld acc = 0;
    forsn(i,1,n) {
        acc += dif(i-1,i);
        while (idx < n && acc-dif(idx,(idx+1)%n) >= K) {
            compute_segs(idx,i);
            acc -= dif(idx,(idx+1)%n);
            idx++;
        }
        compute_segs(idx,i);
    }

    return {(double)lm,(double)rm};
}
