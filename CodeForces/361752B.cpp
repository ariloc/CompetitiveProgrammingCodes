// Range Minimum Queries
// https://ibero1.contest.codeforces.com/group/BXJ6xt3tnH/contest/361752/problem/B
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

const int MAXN = 2e5+10;
const int INF = 2e9;
const int MAXST = (1<<(32-__builtin_clz(MAXN)));

struct mon {
    int v;

    mon operator+ (const mon &o) const {
        return {min(v,o.v)};
    }
};


mon ST[2*MAXST];
int N;

void update (int p, int v) {
    p += N;
    ST[p].v = v;
    while (p > 1)
        p >>= 1, ST[p] = ST[2*p] + ST[2*p+1];
}

int query (int l, int r) {
    int ret = INF;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l&1) ret = min(ret,ST[l++].v);
        if (r&1) ret = min(ret,ST[--r].v);
    }
    return ret;
}

int main() {
    int n,q; scanf("%d %d",&n,&q);
    
    N = (1<<(32-__builtin_clz(n)));
    forn(i,N) ST[i].v = INF; // init
    
    forn(i,n) scanf("%d",&ST[i+N].v);
    dforsn(i,1,N) ST[i] = ST[2*i] + ST[2*i+1]; // build

    forn(i,q) {
        int typ; scanf("%d",&typ);
        if (typ == 1) {
            int p,x; scanf("%d %d",&p,&x), p--;
            update(p,x);
        }
        else {
            int l,r; scanf("%d %d",&l,&r), l--;
            printf("%d\n",query(l,r));
        }
    }

    return 0;
} 
