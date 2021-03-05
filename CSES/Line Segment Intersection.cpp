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

void fs (int &x) {
    int c; x = 0; bool neg = false;
    c = getchar_unlocked(); neg |= (c == '-');
    if (c < '0' || c > '9') c = getchar_unlocked(), neg |= (c == '-');
    for (; c>='0' && c<='9'; c = getchar_unlocked())
        x = 10*x + c-'0';
    if (neg) x *= -1;
}

struct pt {
    ll x,y;
    pt(){}
    pt(ll xx, ll yy) : x(xx), y(yy){}

    pt operator+ (const pt &o) const {return {x+o.x,y+o.y};}
    pt operator- (const pt &o) const {return {x-o.x,y-o.y};}
    ll operator* (const pt &o) const {return x*o.x + y*o.y;} // dot
    ll operator% (const pt &o) const {return x*o.y - y*o.x;} // cross
    int side (const pt a, const pt b) {
        ll v = (b-a)%(*this-a);
        if (!v) return 0; // touch
        if (v > 0) return 1; // left
        return 2; // right
    }
};

bool intersec1D (ii a, ii b) {
    if (a.fst > a.snd) swap(a.fst,a.snd);
    if (b.fst > b.snd) swap(b.fst,b.snd);
    ii c = {max(a.fst,b.fst),min(a.snd,b.snd)};
    return c.fst <= c.snd;
}

bool intersec2D (pt a, pt b, pt c, pt d) {
    int aux1 = c.side(a,b), aux2 = (d.side(a,b));
    if (!aux1 && !aux2) return (intersec1D({a.x,b.x},{c.x,d.x}) && intersec1D({a.y,b.y},{c.y,d.y}));
    return (aux1 != aux2) && (a.side(c,d) != b.side(c,d)); // interseca si son distintos. Si toca alguno hay intersec y también vale lo de distintos. Lo de igual si tocan ya lo cubrí
}

int main() {
    int t; fs(t);
    forn(i,t) {
        int x1,x2,y1,y2,x3,y3,x4,y4; fs(x1), fs(y1), fs(x2), fs(y2), fs(x3), fs(y3), fs(x4), fs(y4);
        pt a = {x1,y1}, b = {x2,y2}, c = {x3,y3}, d = {x4,y4};
        printf("%s\n",intersec2D(a,b,c,d) ? "YES" : "NO");
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
