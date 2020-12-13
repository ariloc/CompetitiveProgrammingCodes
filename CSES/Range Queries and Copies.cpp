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

const int MAXN = 1e7;
const int MAXQ = 2e5+2;
const int MAXST = (1<<(32-__builtin_clz(MAXQ)));

void fs (int &x) {
    int c; x = 0;
    c=getchar_unlocked();
    if (c>'9' || c<'0') c=getchar_unlocked();
    for(; c>='0' && c<='9'; c=getchar_unlocked())
        x = 10*x + c-'0';
}

struct node {
    ll sum; int l,r;
};

node ST[MAXN];
int cntN = 0;

int newNode (int ind) {
    if (ind != -1) ST[cntN] = ST[ind];
    return cntN++;
}

int update (int i, int p, int v, int tl = 0, int tr = MAXST) {
    if (tl > p || tr <= p) return i;
    i = newNode(i);

    if (tr-tl == 1) ST[i].sum = v;
    else {
        int mid = (tl+tr)/2;
        ST[i].l = update(ST[i].l,p,v,tl,mid);
        ST[i].r = update(ST[i].r,p,v,mid,tr);
        ST[i].sum = (ST[i].l == -1 ? 0 : ST[ST[i].l].sum) + (ST[i].r == -1 ? 0 : ST[ST[i].r].sum);
    }
    return i;
}

ll query (int i, int bl, int br, int tl = 0, int tr = MAXST) {
    if (tl >= br || tr <= bl || i == -1) return 0LL;
    if (tl >= bl && tr <= br) return ST[i].sum;
    int mid = (tl+tr)/2;
    return query(ST[i].l,bl,br,tl,mid) + query(ST[i].r,bl,br,mid,tr);
}

vi vers = {-1};

int main() {
    forn(i,MAXN) {ST[i].l = ST[i].r = -1; ST[i].sum = 0;}
    int n,q; fs(n); fs(q);
    forn(i,n) {int x; fs(x); vers[0] = update(vers[0],i,x);}
    forn(i,q) {
        int typ; fs(typ);
        if (typ == 1) {
            int k,a,x; fs(k); fs(a); fs(x); k--; a--;
            vers[k] = update(vers[k],a,x);
        }
        else if (typ == 2) {
            int k,l,r; fs(k); fs(l); fs(r); k--; l--;
            printf("%lld\n",query(vers[k],l,r));
        }
        else {
            int k; fs(k); k--;
            vers.pb(vers[k]);
        }
    }
    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
