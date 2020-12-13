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

const int MAXN = 5e6;
const int MAXQ = 1e5+2;
const int MAXST = (1<<(32-__builtin_clz(MAXQ)));

struct node {
    int sum,l,r;
};

node ST[MAXN];
int cantN = 0;

int newNode (int i) {
    if (i != -1) ST[cantN] = ST[i];
    return cantN++;
}

int update (int i, int p, int v, int tl = 0, int tr = MAXST) {
    if (tl > p || tr <= p) return i;
    i = newNode(i);

    if (tr-tl == 1) ST[i].sum += v;
    else {
        int mid = (tl+tr)/2;
        ST[i].l = update(ST[i].l,p,v,tl,mid);
        ST[i].r = update(ST[i].r,p,v,mid,tr);
        ST[i].sum = (ST[i].l == -1 ? 0 : ST[ST[i].l].sum) + (ST[i].r == -1 ? 0 : ST[ST[i].r].sum);
    }
    return i;
}

int query (int i, int bl, int br, int tl = 0, int tr = MAXST) {
    if (tl >= br || tr <= bl || i == -1) return 0;
    if (tl >= bl && tr <= br) return ST[i].sum;

    int mid = (tl+tr)/2;
    return query(ST[i].l,bl,br,tl,mid) + query(ST[i].r,bl,br,mid,tr);
}

vi vers = {-1};

int main() {
    forn(i,MAXN) ST[i].l = ST[i].r = -1;

    int n; scanf("%d",&n);
    forn(i,n) {int x; scanf("%d",&x); vers[0] = update(vers[0],i,x);}

    int q; scanf("%d",&q);
    forn(i,q) {
        int typ; scanf("%d",&typ);
        if (typ == 1) {
            int idx,pos,v; scanf("%d %d %d",&idx,&pos,&v); pos--;
            vers.pb(update(vers[idx],pos,v));
        }
        else {
            int idx,l,r; scanf("%d %d %d",&idx,&l,&r); l--;
            printf("%d\n",query(vers[idx],l,r));
        }
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
