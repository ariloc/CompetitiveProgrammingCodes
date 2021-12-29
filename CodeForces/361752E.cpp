// First Not Less Than Y
// https://ibero1.contest.codeforces.com/group/BXJ6xt3tnH/contest/361752/problem/E
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

const int MAXN = 2e5+5;
const int MAXST = (1<<(32-__builtin_clz(MAXN)));

struct mon {
    int v, idx;

    mon operator+ (const mon &o) const {
        return max(*this, o);
    }
    bool operator< (const mon &o) const {
        if (v != o.v) return v < o.v;
        return idx > o.idx; // para quedarme con el mas izquierdo
    }
};

mon ST[2*MAXST];
int N;

void update (int p, int v) {
    p += N, ST[p].v = v;
    while (p > 1)
        p /= 2, ST[p] = ST[2*p] + ST[2*p+1];
}

mon query (int i, int v, int tl = 0, int tr = N) {
    if (tr-tl <= 1) return ST[i];

    int mid = (tl+tr)/2;
    if (ST[2*i].v >= v) return query(2*i, v, tl, mid);
    return query(2*i+1, v, mid, tr);
}

int main() {
    int n,q; scanf("%d %d",&n,&q);
    
    N = (1<<(32-__builtin_clz(n)));
    forn(i,N) ST[i+N] = {0,-1};

    forn(i,n) scanf("%d",&ST[i+N].v), ST[i+N].idx = i+1;
    dforsn(i,1,N) ST[i] = ST[2*i] + ST[2*i+1];

    forn(i,q) {
        int typ; scanf("%d",&typ);
        if (typ == 1) {
            int p,x; scanf("%d %d",&p,&x), p--;
            update(p,x);
        }
        else {
            int y; scanf("%d",&y);
            printf("%d\n",query(1,y).idx);
        }
    }

    return 0;
}