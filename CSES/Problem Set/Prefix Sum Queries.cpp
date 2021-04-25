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
    ll s,pref;

    segT operator+ (const segT &o) const {
        return {o.s+s,max(pref,s+o.pref)};
    }
};

segT ST[2*MAXST];
int N;

void update (int p, int v) {
    p += N;
    ST[p].s = v, ST[p].pref = max(0,v);
    while (p > 1) p >>= 1, ST[p] = ST[2*p]+ST[2*p+1];
}

segT query (int i, int tl, int tr, int bl, int br) {
    if (tl >= br || tr <= bl) return {0,0};
    if (tl >= bl && tr <= br) return ST[i];

    int mid = (tl+tr)/2;
    return query(2*i,tl,mid,bl,br) + query(2*i+1,mid,tr,bl,br);
}

int main() {
    ll n,q; fs(n), fs(q);
    N = (1<<(32-__builtin_clz(n)));
    forn(i,n) fs(ST[i+N].s), ST[i+N].pref = max(0LL,ST[i+N].s);

    dforsn(i,1,N) ST[i] = ST[2*i]+ST[2*i+1]; // build

    forn(i,q) {
        ll typ,a,b; fs(typ), fs(a), fs(b); a--;

        if (typ == 1) update(a,b);
        else fp(query(1,0,N,a,b).pref), putchar_unlocked('\n');
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
