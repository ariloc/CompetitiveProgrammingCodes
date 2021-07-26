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

const int INF = 2e9;
const int MAXN = 1e5+5;
const int MAXST = (1<<(32-__builtin_clz(MAXN)));

struct range {
    int l,r,col;

    bool operator< (const range &o) const {
        if (l != o.l) return l < o.l;
        if (r != o.r) return r < o.r;
        return col < o.col;
    }
};

ll ST[2*MAXST], lazy[2*MAXST];
set<range> ranges;

void passLazy (int i, int n) {
    ST[i] += lazy[i]*n;

    if (2*i+1 < 2*MAXST) {
        lazy[2*i] += lazy[i];
        lazy[2*i+1] += lazy[i];
    }

    lazy[i] = 0;
}

void update (int i, int tl, int tr, int bl, int br, int add) {
    passLazy(i,tr-tl);
    if (tl >= br || tr <= bl) return;
    if (tl >= bl && tr <= br) {
        lazy[i] += add;
        passLazy(i,tr-tl);
        return;
    }

    int mid = (tl+tr)/2;
    update(2*i,tl,mid,bl,br,add);
    update(2*i+1,mid,tr,bl,br,add);
    ST[i] = ST[2*i] + ST[2*i+1];
}

ll query (int i, int tl, int tr, int bl, int br) {
    passLazy(i,tr-tl); // el n es tr-tl pues [tl,tr)
    if (tl >= br || tr <= bl) return 0;
    if (tl >= bl && tr <= br) return ST[i];
    
    int mid = (tl+tr)/2;
    return query(2*i,tl,mid,bl,br) + query(2*i+1,mid,tr,bl,br);
}

ii rangeIntersect (ii a, ii b) { // probablemente sabiendo que de alguna forma intersecan
    return {max(a.fst,b.fst),min(a.snd,b.snd)};
}

int main() {
    int n,m; scanf("%d %d",&n,&m);

    int N = (1<<(32-__builtin_clz(n)));

    forn(i,n) ranges.insert({i,i+1,i+1}); // [a,b)

    forn(i,m) {
        int typ; scanf("%d",&typ);

        if (typ == 1) {
            int l,r,x; scanf("%d %d %d",&l,&r,&x); l--; // [l,r)

            auto itL = ranges.lower_bound({l+1,-INF,-INF}); itL--; // el rango más a la izq que interseco
            auto itR = ranges.lower_bound({r,-INF,-INF}); itR--; // el rango más a la derecha que interseco

            range l_range = *itL, r_range = *itR;

            //fprintf(stderr,"[%d,%d) || L -> [%d,%d) || R -> [%d,%d)\n",l,r,l_range.l,l_range.r,r_range.l,r_range.r);

            ii aux = rangeIntersect({l_range.l,l_range.r},{l,r}), aux2 = rangeIntersect({r_range.l,r_range.r},{l,r});

            update(1,0,N,aux.fst,aux.snd,abs(x-l_range.col));
            if (itL != itR) update(1,0,N,aux2.fst,aux2.snd,abs(x-r_range.col)); // condición, pues si no implica que hago la misma update dos veces

            vector<range> toAdd;
            vector<set<range>::iterator> toErase;
            if (aux.fst != l_range.l) toAdd.pb({l_range.l, aux.fst, l_range.col});
            if (aux2.snd != r_range.r) toAdd.pb({aux2.snd, r_range.r, r_range.col});
            toAdd.pb({l,r,x});

            if (itL != itR) {
                for (auto it = next(itL); it != itR; it++) {
                    range thisRange = *it;
                    update(1,0,N,thisRange.l,thisRange.r,abs(thisRange.col-x));
                    toErase.pb(it);
                }
                ranges.erase(itR); // solo si se cumple la condición, de lo contrario lo termino eliminando después
            }
            ranges.erase(itL);
            for (auto &j : toErase) ranges.erase(j);
            for (auto &j : toAdd) ranges.insert(j);
        }
        else {
            int l,r; scanf("%d %d",&l,&r); l--;
            printf("%lld\n",query(1,0,N,l,r));
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!