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

const int MAXN = 1005;

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

pt poly[MAXN];

ll polyArea (pt fig[], int n) {
    ll r = 0;
    forn(i,n) r += (fig[(i+1)%n]-fig[i])%(((pt){0,0})-fig[i]);
    return abs(r); // no me asegura el sentido de giro
}

int main() {
    int n; fs(n);
    forn(i,n) {
        int x,y; fs(x), fs(y);
        poly[i] = {x,y};
    }
    printf("%lld",polyArea(poly,n));

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
