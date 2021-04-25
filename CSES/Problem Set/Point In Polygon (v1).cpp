// based on https://codeforces.com/blog/entry/48868
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

const int MAXN = 1005;
const int INF = 1e9+5;

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
    bool operator== (const pt &o) const {return (x == o.x && y == o.y);}
    bool operator< (const pt &o) const {
        if (x == o.x) return y < o.y;
        return x < o.x;
    }
};

pt poly[MAXN];
int n,m;

int inPoly (pt fig[], pt x) {
    // suponiendo un rayo de proyección horizontal hacia la derecha, usemos el Winding Number Algorithm
    int cnt = 0;
    forn(i,n) {
        if (fig[i] == x) return 0; // boundary
        int j = (i+1)%n;
        if (fig[i].y == x.y && fig[j].y == x.y) { // caso segmento horizontal
            int l = min(fig[i].x,fig[j].x), r = max(fig[i].x,fig[j].x);
            if (x.x >= l && x.x <= r) return 0; // boundary, porque es horiz y está entre los extremos
        }
        else {
            bool below = fig[i].y < x.y;
            if (below != (fig[j].y < x.y)) { // si están en lados distintos
                auto aux = x.side(fig[j],fig[i]); // es todo clockwise si el punto está a la izq del vector de los pts de i a j
                if (!aux) return 0;
                if (below == (aux == 1)) cnt += (below ? 1 : -1); // si el i está abajo, sube, de lo contrario estoy bajando.
            }
        }
    }
    return (!cnt) ? -1 : 1; // outside, inside
}

int main() {
    fs(n), fs(m);

    forn(i,n) {int x,y; fs(x), fs(y); poly[i] = {x,y};}
    forn(i,m) {
        int x,y; fs(x), fs(y);
        pt me = {x,y};
        int aux = inPoly(poly,me);
        printf("%s\n", (!aux ? "BOUNDARY" : aux == 1 ? "INSIDE" : "OUTSIDE"));
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
