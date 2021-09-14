#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

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

const int MAXNO = 4e6;
const int ADD = 1e9;
const ll MAXST = (1LL<<31);

struct node {
    int l,r,sum;
};

node ST[MAXNO];
int cntN = 0;

int newNode(int i) {
    if (i != -1) ST[cntN] = ST[i];
    return cntN++;
}

int update (int i, int p, int v, ll tl = 0, ll tr = MAXST) {
    if (tl > p || tr <= p) return i;
    i = newNode(i);

    if (tr-tl == 1) ST[i].sum += v;
    else {
        ll mid = (tl+tr)/2LL;
        ST[i].l = update(ST[i].l,p,v,tl,mid);
        ST[i].r = update(ST[i].r,p,v,mid,tr);
        ST[i].sum = (ST[i].l == -1 ? 0 : ST[ST[i].l].sum) + (ST[i].r == -1 ? 0 : ST[ST[i].r].sum);
    }
    return i;
}

ll query (int i, int i2, int k, ll tl = 0, ll tr = MAXST) {
    ll mid = (tl+tr)/2LL;
    if (tr-tl == 1) return tl;
    if (i2 == -1) i2 = MAXNO-1; // le pongo un nodo cualquiera vacío, que simplemente no me da nada

    int actL = ST[ST[i].l].sum - (ST[i2].l != -1 ? ST[ST[i2].l].sum : 0); // si no está, resta 0, elemento neutro
    if (actL < k) return query(ST[i].r,ST[i2].r,k-actL,mid,tr);
    else return query(ST[i].l,ST[i2].l,k,tl,mid);
}

vi pref = {-1};

int main() {
    forn(i,MAXNO) ST[i].l = ST[i].r = -1, ST[i].sum = 0;
    int n,m; scanf("%d %d",&n,&m);

    forn(i,n) {int x; scanf("%d",&x); x += ADD; pref.pb(update(pref.back(),x,1));}
    forn(i,m) {
        int l,r,k; scanf("%d %d %d",&l,&r,&k); l--;
        printf("%lld\n",query(pref[r],pref[l],k)-ADD);
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
