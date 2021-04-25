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

const int MAXN = 2e5+5;
const int MAXST = (1<<(32-__builtin_clz(MAXN)));

struct node {
    ll l,r,step; // principio, final, pasos incrementales
};

ll ST[MAXST<<1];
node lazy[MAXST<<1];
int n,m,N;

// TODO ES INCLUSIVO-EXCLUSIVO [A,B)
void update(int i, int tl, int tr, int bl, int br, const int &L, const int &R) { // busco bl,br y estoy en tl,tr, original L,R
    if (bl >= br) return;
    if (bl == tl and br == tr) {
        lazy[i].l += bl-L+1; // agrego margen izq
        lazy[i].r += br-L; // agrego margen der
        lazy[i].step++; // aumenta pasadas
    }
    else {
        int mid = (tl+tr)>>1;
        update(i<<1,tl,mid,bl,min(br,mid),L,R);
        update((i<<1)+1,mid,tr,max(bl,mid),br,L,R);
        ST[i] += ((((ll)(bl-L+1)+(br-L))*(ll)(br-bl))>>1LL); // actualizo los de arriba que pase, suma en una progresión aritmética
    }
}

ll get (int i, int tl, int tr, const int &L, const int &R) {
    if (tr <= L or tl >= R) return 0;

    int mid = (tl+tr)>>1;

    if (lazy[i].step) {// upd lazy a mi y pusheo a los que faltan siguientes
        node me = lazy[i];
        lazy[i] = {0,0,0};
        ST[i] += (((me.l+me.r)*(ll)(tr-tl))>>1LL); // suma en una progresión aritmética

        if (abs(tr-tl) > 1) {
            ll midVL = me.l+me.step*(mid-tl-1);
            ll midVR = midVL+me.step;
            if ((i<<1) < (MAXST<<1)) {
                lazy[(i<<1)].l += me.l;
                lazy[(i<<1)].r += midVL;
                lazy[(i<<1)].step += me.step;
            }
            if ((i<<1)+1 < (MAXST<<1)) {
                lazy[(i<<1)+1].l += midVR;
                lazy[(i<<1)+1].r += me.r;
                lazy[(i<<1)+1].step += me.step;
            }
        }
    }

    if (tl >= L and tr <= R) return ST[i];

    return get(i<<1,tl,mid,L,R) + get((i<<1)+1,mid,tr,L,R);
}

int main() {
    scanf("%d %d",&n,&m);

    N = (1<<(32-__builtin_clz(n)));

    forn(i,n) {int x; scanf("%d",&x); ST[i+N] = x;}
    dforsn(i,1,N) ST[i] = ST[i<<1] + ST[(i<<1)+1]; // BUILD INIT

    forn(i,m) {
        int typ,l,r; scanf("%d %d %d",&typ,&l,&r); l--;
        if (typ == 1) update(1,0,N,l,r,l,r);
        else printf("%lld\n",get(1,0,N,l,r));
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
