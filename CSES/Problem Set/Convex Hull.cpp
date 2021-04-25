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

const int MAXN = 2e5+5;

struct pt {
    ll x,y;
    pt(){}
    pt (ll xx, ll yy) : x(xx), y(yy){}

    ll operator% (const pt &o) const {return x*o.y - y*o.x;} // cross
    pt operator- (const pt &o) const {return pt(x-o.x,y-o.y);}
    bool operator< (const pt &o) const { // chull cmp
        if (x == o.x) return y < o.y;
        return x < o.x;
    }
    bool cw (const pt &a, const pt &b) {return (b-a)%(*this-a) > 0;} // > 0 --> clockwise (puedo cambiar por un int y si es < 0 es ccw, == 0 es que son colineales)
};

vector<pt> chull (pt p[], int n) {
    vector<pt> r;
    sort(p,p+n);
    forn(i,n) { // lower hull  (de min x a max x)
        while ((int)r.size() >= 2 && r.back().cw(r[(int)r.size()-2],p[i])) r.pop_back();
        r.pb(p[i]);
    }
    r.pop_back(); int k = r.size();
    dforn(i,n) { // upper hull (de max x a min x)
        while ((int)r.size() >= k+2 && r.back().cw(r[(int)r.size()-2],p[i])) r.pop_back();
        r.pb(p[i]);
    }
    r.pop_back();
    return r;
}

pt poly[MAXN];

int main() {
    int n; fs(n);
    forn(i,n) {
        int x,y; fs(x), fs(y);
        poly[i] = {x,y};
    }

    vector<pt> rta = chull(poly,n);

    printf("%d\n",(int)rta.size());
    for (auto &i : rta) printf("%lld %lld\n",i.x,i.y);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
