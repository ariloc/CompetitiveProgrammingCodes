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

const int INF = 2e9;
const int MAXN = 2e5+5;
const int MAXK = 5;
const int MAXST = (1<<(32-__builtin_clz(MAXN)));

struct mon {
    int mini,maxi;
    mon(){mini = INF, maxi = -INF;}
    mon(int mini, int maxi) : mini(mini), maxi(maxi){}

    mon operator+ (const mon &o) const {
        return mon(min(mini,o.mini), max(maxi,o.maxi));
    }
};

int N;
mon ST[1<<MAXK][2*MAXST];

void update (mon *mST, int p, int v) {
    p += N; mST[p].mini = mST[p].maxi = v;
    while (p > 1) 
        p >>= 1, mST[p] = mST[2*p] + mST[2*p+1];
}

mon query (mon *mST, int l, int r) {
    mon ret;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l&1) ret = (ret + mST[l++]);
        if (r&1) ret = (ret + mST[--r]);
    }
    return ret;
}

int main() {
    int n,k; scanf("%d %d",&n,&k);
    N = (1<<(32-__builtin_clz(n)));

    forn(i,n) {
        vi coords;
        forn(j,k) {int x; scanf("%d",&x); coords.pb(x);}
        forn(j,1<<k) {
            ST[j][i+N].mini = ST[j][i+N].maxi = 0;
            forn(l,k)
                ST[j][i+N].mini = ST[j][i+N].maxi = (ST[j][i+N].mini +
                                            coords[l] * ((j & (1<<l)) ? -1 : 1));
        }
    }
    forn(j,1<<k) dforsn(i,1,N) ST[j][i] = ST[j][2*i] + ST[j][2*i+1];

    int q; scanf("%d",&q);
    forn(_,q) {
        int typ; scanf("%d",&typ);
        if (typ == 1) {
            int pos; scanf("%d",&pos); pos--;

            vi coords;
            forn(i,k) {int x; scanf("%d",&x); coords.pb(x);}
            forn(j,1<<k) {
                int s = 0;
                forn(l,k) s += coords[l] * ((j & (1<<l)) ? -1 : 1);
                update(ST[j], pos, s);
            }
        }
        else {
            int l,r; scanf("%d %d",&l,&r); l--;
            int rta = -INF;
            forn(j,1<<k) {
                mon aux = query(ST[j], l, r);
                rta = max(rta, aux.maxi - aux.mini);
            }
            printf("%d\n",rta);
        }
    }

    return 0;
}