#include <algorithm>
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
const int MAXMT = (1<<(32-__builtin_clz(MAXN)));

vi mt[2*MAXMT];
int N;

void build (int i = 1, int l = 0, int r = N) {
    if (r-l <= 1) return;

    int mid = (l+r)/2;
    build(2*i,l,mid);
    build(2*i+1,mid,r);

    int a = 0, b = 0;
    while (a < (int)mt[2*i].size() && b < (int)mt[2*i+1].size()) {
        if (mt[2*i][a] < mt[2*i+1][b]) mt[i].pb(mt[2*i][a++]);
        else mt[i].pb(mt[2*i+1][b++]);
    }
    while (a < (int)mt[2*i].size())
        mt[i].pb(mt[2*i][a++]);
    while (b < (int)mt[2*i+1].size())
        mt[i].pb(mt[2*i+1][b++]);
}

int query (int i, int k, int bl, int br, int tl = 0, int tr = N) {
    if (tr <= bl || tl >= br) return 0;
    if (tl >= bl && tr <= br) {
        return max(0L, (int)mt[i].size() - (lower_bound(all(mt[i]),k+1)-mt[i].begin()));
    }

    int mid = (tl+tr)/2;
    return query(2*i,k,bl,br,tl,mid) + query(2*i+1,k,bl,br,mid,tr);
}

int main() {
    int n; scanf("%d",&n);

    N = (1<<(32-__builtin_clz(MAXN)));

    forn(i,n) {
        int x; scanf("%d",&x);
        mt[i+N].pb(x);
    }

    build();

    int q; scanf("%d",&q);
    forn(_,q) {
        int l,r,k; scanf("%d %d %d",&l,&r,&k), l--, r--;
        printf("%d\n",query(1,k,l,r+1));
    }
         
    return 0;
}
