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

int const MAXN = 3005;
ll const INF = 9e18;

struct voter {
    int p,c,ind;

    bool operator< (const voter &o) const {
        return c < o.c;
    }
};

vector<voter> voters;
vector<voter> parties[MAXN];
bitset<MAXN> done;

int main() {
    int n,m; scanf("%d %d",&n,&m);
    forn(i,n) {
        int p,c; scanf("%d %d",&p,&c); --p;
        voters.pb({p,c,i});
        parties[p].pb({p,c,i});
    }

    forn(i,n) sort(all(voters));
    forn(i,m) sort(all(parties[i])), reverse(all(parties[i]));

    int cur = 0;
    forn(i,n) if (!voters[i].p) cur++, done[voters[i].ind] = true;

    ll rta = INF, acc = 0;
    int cnt = cur;
    dforsn(i,max(1,cur),n+1) {
        forn(j,m) {
            while((int)parties[j].size() >= i) {
                voter x = parties[j].back(); parties[j].pop_back();
                if (!done[x.ind]) acc += x.c, done[x.ind] = true, cnt++;
            }
        }
        int cntgreed = 0; ll accgreed = 0;
        forn(j,n) {
            if (cntgreed+cnt >= i) break;
            if (!done[voters[j].ind]) {
                cntgreed++, accgreed += voters[j].c;
            }
        }
        if (cntgreed + cnt >= i) rta = min(rta, accgreed + acc);
    }

    printf("%lld\n",rta);
    
    return 0;
}
