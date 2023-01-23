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

const int MAXN = 3e5+5;
const int MAXST = (1<<(32-__builtin_clz(MAXN)));

int n,q;

struct mon {
    int l,r;
    bool posib;

    mon(){l = -1, r = -1, posib = 1;}
    mon(int l, int r) : l(l), r(r) { posib = true; }
    mon(int l, int r, bool posib) : l(l), r(r), posib(posib) {}

    mon operator+ (const mon &o) const {
        if (l == -1) return o;
        if (o.l == -1) return *this;
        return mon(l, o.r, posib & o.posib & (o.l == (r+1)%n));
    }
};

int N;
mon ST[2*MAXST];
int posic[MAXN];

void update (int p, int v) {
    p += N; ST[p] = mon(v,v);
    while (p > 1) p /= 2, ST[p] = ST[2*p] + ST[2*p+1];
}

mon query (int i, int tl, int tr, int bl, int br) {
    if (tl >= br || tr <= bl) return mon();
    if (tl >= bl && tr <= br) return ST[i];

    int mid = (tl+tr)/2;
    return query(2*i,tl,mid,bl,br) + query(2*i+1,mid,tr,bl,br);
}

int main() {
    scanf("%d %d",&n,&q);
    
    N = (1<<(32-__builtin_clz(n)));

    forn(i,n) {
        int x; scanf("%d",&x), x--;
        ST[x+N] = mon(i,i);
        posic[x] = i;
    }
    dforsn(i,1,N) ST[i] = ST[2*i] + ST[2*i+1];

    forn(_,q) {
        int a,b; scanf("%d %d",&a,&b), a--, b--;

        swap(posic[a],posic[b]);
        update(a,posic[a]);
        update(b,posic[b]);

        printf("%s\n", query(1,0,N,0,n).posib ? "DA" : "NE");
    }

    return 0;
}
