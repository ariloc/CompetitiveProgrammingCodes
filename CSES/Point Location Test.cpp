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
    pt(ll xx, ll yy) : x(xx), y(yy) {}

    pt operator- (const pt &o) const {return {x-o.x,y-o.y};}
    ll operator% (const pt &o) const {return x*o.y - y*o.x;}

    int side (const pt a, const pt b) {
        ll val = ((b-a)%(*this-a));
        if (!val) return 0; // touch
        if (val > 0) return 1; // left
        return 2; // right
    }
};

int main() {
    int t; fs(t);
    forn(i,t) {
        int x1,y1,x2,y2,x3,y3; fs(x1), fs(y1), fs(x2), fs(y2), fs(x3), fs(y3);
        pt a = {x1,y1}, b = {x2,y2}, c = {x3,y3};
        int aux = c.side(a,b);
        printf("%s\n",(!aux ? "TOUCH" : aux == 1 ? "LEFT" : "RIGHT"));
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
