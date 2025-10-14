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

int const INF = 2e9+5;
int const MAXN = 2e5+5;

struct pt {
    int x,y;

    pt operator- (const pt &o) const {
        return {x-o.x,y-o.y};
    }
    int norm1() {
        return abs(x) + abs(y);
    }
};

vector<pt> pts;
int lm,rm;
ll prefs[MAXN];
int n,k;

int dif (int i, int j) {
    return (pts[i]-pts[j]).norm1();
}

pt addv (pt cur, int v, int stidx) {
    if (pts[stidx].x == pts[(stidx+1)%n].x) { // dy
        int sign = pts[(stidx+1)%n].y - pts[stidx].y > 0 ? 1 : -1;
        cur.y += v * sign;
    }
    else { // dx
        int sign = pts[(stidx+1)%n].x - pts[stidx].x > 0 ? 1 : -1;
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
            lm = min(lm,abs(a1.x-b1.x));
            rm = max(rm,abs(a1.x-b1.x));
        }
    }
    else if (b2.y == b1.y && a1.y == a2.y && (b1.x-b2.x != 0) && (a1.x-a2.x != 0) && (b1.x-b2.x > 0) != (a1.x-a2.x > 0)) { // misma dir dx, senti
        bool ok = false;
        if (a1.x > a2.x) swap(a1,a2);
        if (b1.x > b2.x) swap(b1,b2);
        if (a1.x <= b1.x && b1.x <= a2.x) ok = true;
        if (a1.x <= b2.x && b2.x <= a2.x) ok = true;
        if (b1.x <= a1.x && a1.x <= b2.x) ok = true;
        if (b1.x <= a2.x && a2.x <= b2.x) ok = true;
        if (ok) {
            lm = min(lm,abs(a1.y-b1.y));
            rm = max(rm,abs(a1.y-b1.y));
        }
    }
}

// i is start of segment, j is end
void compute_segs(int i, int j) {
    ll sob = prefs[(j-1+n)%n] - prefs[i];
    int off = sob - k;
    if (off > dif((i+1)%n,i))
        return;
    if (abs(off) > dif(j,(j-1+n)%n))
        return;

    if (off > 0) {
        pt st = addv(pts[i],off,i);
        pt nd = pts[(j-1+n)%n];
        lm = min(lm, (st-nd).norm1());
        rm = max(rm, (st-nd).norm1());

        int diff = min((pts[(i+1)%n] - st).norm1(), (pts[j]-nd).norm1());
        pt st2 = addv(st,diff,i);
        pt nd2 = addv(nd,diff,(j-1+n)%n);

        compute_midpoint(st,st2,nd,nd2);

        lm = min(lm, (st2-nd2).norm1());
        rm = max(rm, (st2-nd2).norm1());
    } else {
        off = abs(off);

        pt st = pts[i];
        pt nd = addv(pts[(j-1+n)%n],off,(j-1+n)%n);
        lm = min(lm, (st-nd).norm1());
        rm = max(rm, (st-nd).norm1());

        int diff = min((pts[(i+1)%n] - st).norm1(), (pts[j]-nd).norm1());
        pt st2 = addv(st,diff,i);
        pt nd2 = addv(nd,diff,(j-1+n)%n);
        
        compute_midpoint(st,st2,nd,nd2);
        
        lm = min(lm, (st2-nd2).norm1());
        rm = max(rm, (st2-nd2).norm1());
    }
}

vector<int> esprintando(int K, vector<int> &X, vector<int> &Y) {
    n = 2*(int)X.size();
    k = K;
    forn(_,2) forn(i,X.size()) pts.pb({X[i],Y[i]});

    forsn(i,1,n+1) prefs[i] = prefs[i-1] + dif(i-1,i%n);

    lm = INF, rm = -INF;

    int idx = 0, acc = 0;
    forsn(i,1,n) {
        acc += dif(i-1,i);
        while (idx < n && acc-dif(idx,(idx+1)%n) >= K) {
            compute_segs(idx,i);
            acc -= dif(idx,(idx+1)%n);
            idx++;
        }
        compute_segs(idx,i);
    }

    return {lm,rm};
}
