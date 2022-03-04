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

const int INF = 2e9;
const int MAXN = 2e5+5;
const int MAXST = (1<<(32-__builtin_clz(MAXN)));

struct mon {
    int tl,tr,lpref,lsuf,vpref,vsuf;
    ll cnt;

    mon(){cnt = 0; tl = tr = -1; lpref = lsuf = 1; vpref = -INF, vsuf = INF;}
    mon(int tl, int tr, int lpref, int lsuf, int vpref, int vsuf, ll cnt) :
        tl(tl), tr(tr), lpref(lpref), lsuf(lsuf), vpref(vpref), vsuf(vsuf), cnt(cnt){}

    mon operator+ (const mon &o) const {
        mon ret;

        if (o.tl == -1) return *this;
        if (tl == -1) return o;

        ret.cnt = cnt + o.cnt;
        ret.vsuf = o.vsuf, ret.vpref = vpref;
        ret.lsuf = o.lsuf, ret.lpref = lpref;
        ret.tl = tl, ret.tr = o.tr;
        if (o.vpref >= vsuf) {
            ret.cnt += (lsuf * (ll)o.lpref);
            if (o.lsuf == (o.tr-o.tl))
                ret.lsuf = o.lsuf + lsuf;
            if (lpref == (tr-tl))
                ret.lpref = lpref + o.lpref;
        }
        return ret;
    }
};

int N;
mon ST[2*MAXST];
int arr[MAXN];

void update (int p, int v) {
    p += N, ST[p].vpref = ST[p].vsuf = v;
    while (p > 1)
        p /= 2, ST[p] = ST[2*p] + ST[2*p+1];
}


mon query (int i, int bl, int br, int tl = 0, int tr = N) {
    if (tl >= br || tr <= bl) return mon();
    if (tl >= bl && tr <= br) return ST[i];

    int mid = (tl+tr)/2;
    return query(2*i,bl,br,tl,mid) + query(2*i+1,bl,br,mid,tr);
}

int main() {
    int n,q; scanf("%d %d",&n,&q);
    forn(i,n) scanf("%d",&arr[i]);

    N = (1<<(32-__builtin_clz(n)));
    
    forn(i,n) ST[i+N] = mon(i,i+1,1,1,arr[i],arr[i],1);
    dforsn(i,1,N) ST[i] = ST[2*i] + ST[2*i+1];

    forn(_,q) {
        int typ; scanf("%d",&typ);
        if (typ == 1) {
            int x,y; scanf("%d %d",&x,&y); x--;
            update(x,y);
        }
        else {
            int l,r; scanf("%d %d",&l,&r); l--;
            printf("%lld\n",query(1,l,r).cnt);
        }
    }

    return 0;
}