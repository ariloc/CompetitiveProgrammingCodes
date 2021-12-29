// Distinct Elements in Range
// https://ibero1.contest.codeforces.com/group/BXJ6xt3tnH/contest/361752/problem/G
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
const int MAXE = 60;

struct mon {
    int cnt[MAXE], uniq;
    mon(){
        forn(i,MAXE) cnt[i] = 0;
        uniq = 0;
    } 

    mon operator+ (const mon &o) const {
        mon aux;
        forn(i,MAXE) {
            aux.cnt[i] = cnt[i] + o.cnt[i];
            aux.uniq += (aux.cnt[i] > 0);
        }
        return aux;
    }
};

mon ST[2*MAXST];
int N;

void update (int p, int v) {
    p += N;
    forn(i,MAXE) ST[p].cnt[i] = 0;
    ST[p].cnt[v]++;
    while (p > 1)
        p /= 2, ST[p] = ST[2*p] + ST[2*p+1];
}

mon query (int l, int r) {
    mon ret;

    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l&1) ret = (ret + ST[l++]);
        if (r&1) ret = (ret + ST[--r]);
    }
    return ret;
}

int main() {
    int n,q; scanf("%d %d",&n,&q);
    N = (1<<(32-__builtin_clz(n)));
    
    forn(i,n) {
        int x; scanf("%d",&x), x--;
        ST[i+N].cnt[x]++, ST[i+N].uniq = 1;
    }
    dforsn(i,1,N) ST[i] = ST[2*i] + ST[2*i+1];

    forn(i,q) {
        int typ; scanf("%d",&typ);
        if (typ == 1) {
            int p,x; scanf("%d %d",&p,&x), p--, x--;
            update(p,x);
        }
        else {
            int l,r; scanf("%d %d",&l,&r), l--;
            printf("%d\n",query(l,r).uniq);
        }
    }

    return 0;
}