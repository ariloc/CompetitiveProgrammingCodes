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

const int MAXST = (1<<19);

ll ST[2*MAXST];
int stat,N; // 1 if swapped

void update (int i, int tl, int tr, int p, int v, int lvl) {
    if (tr-tl == 1) ST[i] = v;
    else {
        int mid = (tl+tr)/2;
        bool der = (p >= mid), isSwap = (stat&(1<<lvl));
        if (isSwap) der = !der;
        if (der) update(2*i+1,(isSwap ? tl : mid),(isSwap ? mid : tr),p,v,lvl-1);
        else update(2*i,(isSwap ? mid : tl),(isSwap ? tr : mid),p,v,lvl-1);
        ST[i] = ST[2*i]+ST[2*i+1];
    }
}

ll query (int i, int tl, int tr, int L, int R, int lvl) {
    if (tl >= L && tr <= R) return ST[i];
    if (tl >= R || tr <= L) return 0;

    int mid = (tl+tr)/2;
    bool isSwap = (stat&(1<<lvl));
    return query(2*i,(isSwap ? mid : tl),(isSwap ? tr : mid),L,R,lvl-1)+
           query(2*i+1,(isSwap ? tl : mid),(isSwap ? mid : tr),L,R,lvl-1);
}

int main() {
    int n,q; scanf("%d %d",&n,&q);
    N = (1<<n);

    forn(i,N) scanf("%d",&ST[i+N]);
    dforsn(i,1,N) ST[i] = ST[2*i]+ST[2*i+1]; // build
    forn(i,q) {
        int typ; scanf("%d",&typ);
        if (typ == 1) {int x,k; scanf("%d %d",&x,&k); update(1,0,N,x-1,k,n);}
        else if (typ == 2) {int k; scanf("%d",&k); stat ^= ((1<<(k+1))-1);}
        else if (typ == 3) {int k; scanf("%d",&k); stat ^= (1<<(k+1));}
        else {int l,r; scanf("%d %d",&l,&r); printf("%lld\n",query(1,0,N,l-1,r,n));}
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
