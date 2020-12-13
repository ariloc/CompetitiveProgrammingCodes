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

const int MAXN = 3e5+2;
const ll INF = 1e12;
const int MAXST = (1<<(32-__builtin_clz(MAXN)));

struct term {
    ll s,r; // suman, restan

    term operator+ (const term &o) const {
        return {s+o.s,r+o.r};
    }
    bool operator< (const term &o) const {return (s-r) < (o.s-o.r);}
};

struct segT {
    term op[4]; // suma o resta al principio (1er bit) || suma o resta al final (2do bit)

    segT operator+ (const segT &o) const {
        segT rta;
        rta.op[0] = max({op[0],o.op[0],op[2]+o.op[1],op[0]+o.op[0]});
        rta.op[1] = max({op[1],o.op[1],op[1]+o.op[0],op[3]+o.op[1]});
        rta.op[2] = max({op[2],o.op[2],op[0]+o.op[2],op[2]+o.op[3]});
        rta.op[3] = max({op[3],o.op[3],op[1]+o.op[2],op[3]+o.op[3]});
        return rta;
    }
};

segT ST[2*MAXST];
int N;

void update (int p, segT v) {
    p += N;
    ST[p] = v;
    while (p > 1) {
        p /= 2;
        ST[p] = ST[2*p] + ST[2*p+1];
    }
}

int main() {
    int t; scanf("%d",&t);
    forn(i,t) {
        int n,q; scanf("%d %d",&n,&q);
        N = (1<<(32-__builtin_clz(n)));
        forn(j,2*N) ST[j] = {{{0,0},{0,0},{0,0},{0,0}}};

        forn(j,n) {int x; scanf("%d",&x); ST[j+N].op[1].r = ST[j+N].op[2].s = x; ST[j+N].op[1].s = ST[j+N].op[2].r = 0;}
        dforsn(j,1,N) ST[j] = ST[2*j] + ST[2*j+1]; // build
        printf("%lld\n",max(ST[1].op[0].s-ST[1].op[0].r,ST[1].op[2].s-ST[1].op[2].r));
        forn(j,q) {
            int l,r; scanf("%d %d",&l,&r); l--; r--;
            segT aux = ST[l+N];
            update(l,ST[r+N]); update(r,aux);
            printf("%lld\n",max(ST[1].op[0].s-ST[1].op[0].r,ST[1].op[2].s-ST[1].op[2].r));
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
