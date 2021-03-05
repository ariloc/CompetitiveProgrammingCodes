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
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int INF = 1e9+5;

struct pt {
    ld x,y;

    ld operator% (const pt &o) const {return x*o.y - y*o.x;}
    pt operator- (const pt &o) const {return {x-o.x,y-o.y};}
    bool colinear(const pt &a, const pt &b) {return !((b-a)%(*this-a));}
    bool operator< (const pt &o) const {
        if (x == o.x) return y < o.y;
        return x < o.x;
    }
};

pt sq1[4], sq2[4];

bool onSegm (pt x, pt a, pt b) {
    return (x.colinear(a,b) && x.x >= min(a.x,b.x) && x.x <= max(a.x,b.x) && x.y >= min(a.y,b.y) && x.y <= max(a.y,b.y));
}

bool isInside (pt fig[], pt x) {
    // podría hacerse con un par de productos cruces, pero mejor repaso Winding Number
    int cnt = 0;
    forn(i,4) {
        int j = (i+1)%4;

        if (onSegm(x,fig[i],fig[j])) return 1;

        ld v = (x-fig[j])%(fig[i]-fig[j]);
        if (v > 0 && fig[j].y >= x.y && fig[i].y < x.y) cnt++;
        if (v < 0 && fig[i].y >= x.y && fig[j].y < x.y) cnt--;
    }

    return (cnt > 0);
}

bool solve (pt a[], pt b[]) {
    forn(i,4) if (isInside(b,a[i])) return 1;
    forn(i,4) if (isInside(a,b[i])) return 1;
    return 0;
}

bool isCCW (pt a[]) {
    int n = 4;
    int ind = min_element(a,a+n)-a;
    return ((a[(ind-1+4)%n]-a[(ind+1)%n])%(a[ind]-a[(ind+1)%n])) > 0;
}

void normPoly (pt a[]) {
    if (!isCCW(a)) reverse(a,a+4);
}

pt centerPoint (pt a[]) {
    ld miniX = INF, maxiX = -INF, miniY = INF, maxiY = -INF;
    forn(i,4) {
        miniX = min(miniX,a[i].x);
        maxiX = max(maxiX,a[i].x);
        miniY = min(miniY,a[i].y);
        maxiY = max(maxiY,a[i].y);
    }
    return {(miniX+maxiX)/2.0,(maxiY+miniY)/2.0};
}

int main() {
    FAST_IO;

    forn(i,4) cin >> sq1[i].x >> sq1[i].y;
    forn(i,4) cin >> sq2[i].x >> sq2[i].y;

    normPoly(sq1), normPoly(sq2);

    // they intersect if one of the points is inside the other square
    bool cond = solve(sq1,sq2);

    // edge case: superpuestos pero no se tocan
    // solución: fijémonos también si se encuentra el pto central en c/u (?)

    pt ctr1 = centerPoint(sq1), ctr2 = centerPoint(sq2);
    cond |= isInside(sq1,ctr2), cond |= isInside(sq2,ctr1);

    cout << (cond ? "YES" : "NO");

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
