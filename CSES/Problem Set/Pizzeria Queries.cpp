#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 2e5+2;
const ll INF = 9e18;
const int MAXST = (1<<(32-__builtin_clz(MAXN)));

void fs (ll &x) {
    int c; x = 0; bool neg = false;
    c = getchar_unlocked(); neg |= (c == '-');
    if (c < '0' || c > '9') c = getchar_unlocked(), neg |= (c == '-');
    for (; c>='0' && c<='9'; c = getchar_unlocked())
        x = 10*x + c-'0';
    if (neg) x *= -1;
}

void fp (ll x) {
    if (!x) {putchar_unlocked('0'); return;}
    int i = 19;
    char buf[20];
    while (x) buf[i--] = (x%10)+'0', x /= 10LL;
    while ((++i) < 20) putchar_unlocked(buf[i]);
}

struct segT {
    ll l,r;
    int tl,tr;

    segT operator+ (const segT &o) const {
        return {min({l,o.l+o.tl-tl,o.r+o.tr-tl-1}),min({o.r,r+o.tr-tr,l+o.tr-tl-1}),tl,o.tr}; // resto unos pues incl-excl
    }
};

segT ST[2*MAXST];
int N;

void update (int p, int v) {
    p += N; ST[p].l = ST[p].r = v;
    while (p > 1) p >>= 1, ST[p] = ST[2*p] + ST[2*p+1];
}

void build () {
    forn(i,N) ST[i+N].tl = i, ST[i+N].tr = i+1;
    dforsn(i,1,N) ST[i] = ST[2*i]+ST[2*i+1];
}

ll query (int i, int p) {
    int tl = ST[i].tl, tr = ST[i].tr;
    if (tr-tl <= 1) return ST[i].l;

    int mid = (tl+tr)/2;
    ll calc = min({ST[i].r+tr-1-p, ST[i].l+p-tl});
    if (p >= mid) return min({calc, query(2*i+1,p), ST[2*i].r+p-ST[2*i].tr+1});
    return min({calc, query(2*i,p), ST[2*i+1].l+ST[2*i+1].tl-p});
}

int main() {
    ll n,q; fs(n), fs(q);
    N = (1<<(32-__builtin_clz(n)));
    forn(i,N) ST[i+N].l = ST[i+N].r = INF;
    forn(i,n) fs(ST[i+N].l), ST[i+N].r = ST[i+N].l;

    build();

    forn(i,q) {
        ll typ,k; fs(typ), fs(k); k--;
        if (typ == 1) {
            ll x; fs(x);
            update(k,x);
        }
        else fp(query(1,k)), putchar_unlocked('\n');
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
