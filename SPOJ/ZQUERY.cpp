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

int const MAXN = 5e4+5;
int const MAXS = 1e5+5;
int const MAXST = (1<<(32-__builtin_clz(MAXS)));
int const SHIFT = 5e4;
int const BLOCK = 300;
int const INF = 2e9;

struct range {
    int l,r,id;
};

struct mon {
    int v,i;

    mon(){v = 0, i = -1;}
    mon(int a, int b) : v(a), i(b) {}

    mon operator+ (const mon &o) const {
        if (v > o.v) return *this;
        return o;
    }
};

int arr[MAXN], dp[MAXN];
int rta[MAXN];
range queries[MAXN];
deque<int> ap[MAXS];
mon ST[2*MAXST];
int N;

bool byL (const range &lhs, const range &rhs) {
    if (lhs.l != rhs.l) return lhs.l < rhs.l;
    return lhs.r < rhs.r;
}

bool byR (const range &lhs, const range &rhs) {
    if (lhs.r != rhs.r) return lhs.r < rhs.r;
    return lhs.l < rhs.l;
}

void update (int p, int v) {
    p += N; ST[p] = mon(v,p);
    while (p > 1)
        p /= 2, ST[p] = ST[2*p] + ST[2*p+1];
}

void add (int i) {
    if (ap[i].back() == ap[i].front()) return;
    update(i,ap[i].back()-ap[i].front());
}

void del (int i) {
    if (ap[i].empty() || ap[i].back() == ap[i].front()) {
        update(i,0);
        return;
    }
    update(i,ap[i].back()-ap[i].front());
}

int main() {
    int n,q; scanf("%d %d",&n,&q);

    N = (1<<(32-__builtin_clz(2*n)));

    forn(i,n) scanf("%d",&arr[i]);

    forn(i,n) dp[i+1] = dp[i] + arr[i];
    forn(i,n+1) dp[i] += SHIFT;

    forn(i,q) {
        int l,r; scanf("%d %d",&l,&r);
        queries[i] = {l,r,i};
    }

    sort(queries,queries+q,byL);

    int indb = 0;
    forn(i,q) {
        if (queries[i].l-queries[indb].l > BLOCK) {
            sort(queries+indb,queries+i,byR);
            indb = i;
        }
    }
    sort(queries+indb,queries+q,byR);

    int l = 1, r = 1;
    ap[dp[0]].push_front(0);
    ap[dp[1]].push_front(1);
    forn(i,q) {
        int dl = queries[i].l-l, dr = queries[i].r-r;
        int choose = (queries[i].l > r);
        forn(k,2) {
            if (!(choose&1)) {
                while (l != queries[i].l) {
                    if (dl > 0) {
                        ap[dp[l-1]].pop_front();
                        del(dp[l-1]);
                        ++l;
                    }
                    else {
                        --l;
                        ap[dp[l-1]].push_front(l-1);
                        add(dp[l-1]);
                    }
                }
            }
            else {
                while (r != queries[i].r) {
                    if (dr > 0) {
                        ++r;
                        ap[dp[r]].push_back(r);
                        add(dp[r]);
                    }
                    else {
                        ap[dp[r]].pop_back();
                        del(dp[r]);
                        --r;
                    }
                }
            }
            choose ^= 1;
        }
        rta[queries[i].id] = ST[1].v;
    }

    forn(i,q) printf("%d\n",rta[i]);
 
    return 0;
}
