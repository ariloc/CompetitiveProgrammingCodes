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
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int MAXN = 3e4+5;
const int MAXV = 1e9+5;
const int MAXB = 1e7;

struct mon {
    int l,r,v;

    mon() {l = r = -1, v = 0;}
    mon(int a, int b, int c) : l(a), r(b), v(c) {}
};

int N;
vector<mon> ST;
vi versions = {-1};

int newNode (int st) {
    ST.pb(mon());
    if (st != -1) ST.back() = ST[st];
    return (int)ST.size() - 1;
}

int update (int i, int p, int v, int tl = 0, int tr = N) {
    i = newNode(i);
    if (tr-tl <= 1) {
        ST[i].v += v;
        return i;
    }

    int mid = (tl+tr)/2;
    if (p >= mid) ST[i].r = update(ST[i].r,p,v,mid,tr);
    else ST[i].l = update(ST[i].l,p,v,tl,mid);
    ST[i].v = (ST[i].l == -1 ? 0 : ST[ST[i].l].v) + (ST[i].r == -1 ? 0 : ST[ST[i].r].v);
    return i;
}

int query (int i, int bl, int br, int tl = 0, int tr = N) {
    if (i == -1 || tl >= br || tr <= bl) return 0;
    if (tl >= bl && tr <= br) return ST[i].v;

    int mid = (tl+tr)/2;
    return query(ST[i].l,bl,br,tl,mid) + query(ST[i].r,bl,br,mid,tr);
}

int main() {
    int n; scanf("%d",&n);

    ST.reserve(MAXB); // IMPORTANT!!!

    N = (1<<(32-__builtin_clz(MAXV)));

    forn(i,n) {
        int x; scanf("%d",&x);
        versions.pb(update(versions.back(), x, 1));
    }

    int q; scanf("%d",&q);
    forn(_,q) {
        int l,r,k; scanf("%d %d %d",&l,&r,&k);
        printf("%d\n", query(versions[r],k+1,MAXV) - query(versions[l-1],k+1,MAXV));
    }
       
    return 0;
}
