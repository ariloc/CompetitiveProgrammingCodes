// based on https://gitlab.com/mredigonda/olaf/-/blob/master/geometry/polygon_test_has.cpp
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

    pt operator- (const pt &o) const {return {x-o.x,y-o.y};}
    ll operator% (const pt &o) const {return x*o.y - y*o.x;} // cross
};

pt poly[MAXN];
int n,m;

bool onSegm (pt a, pt b, pt x) {
    return (!((a-b)%(x-b)) && x.x >= min(a.x,b.x) && x.x <= max(a.x,b.x) && x.y >= min(a.y,b.y) && x.y <= max(a.y,b.y));
}

int inPoly (pt fig[], pt x) {
    // Winding Number Algorithm, suponiendo un rayo de proyección horizontal desde el pto hacia la derecha
    int cnt = 0;
    forn(i,n) {
        int j = (i+1)%n;

        if (onSegm(fig[i],fig[j],x)) return 0; // boundary

        ll v = (x-fig[j])%(fig[i]-fig[j]); // damn it, overflow
        if (v > 0 && fig[j].y >= x.y && fig[i].y < x.y) cnt++;
        if (v < 0 && fig[i].y >= x.y && fig[j].y < x.y) cnt--;
    }
    return !cnt ? -1 : 1;
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
