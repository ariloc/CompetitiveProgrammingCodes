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
typedef long double ld;

const int MAXN = 1e5+5;
const ll INFL = 9e18;

vector<pair<int, ll>> sums[MAXN];
bool done[MAXN];
int spf[MAXN];
int inipos[MAXN];

void criba() {
    forn(i,MAXN) spf[i] = i;
    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2, done[i] = true;
    for (int i = 3; i*i <= MAXN; i += 2)
        if (!done[i])
            for (int j = i+i; j < MAXN; j += i)
                if (!done[j])
                    done[j] = true, spf[j] = i;
}

vi fact_uniq (int x) {
    vi ret;
    int prv = -1;
    while (x > 1) {
        if (spf[x] != prv) ret.pb(spf[x]);
        prv = spf[x];
        x /= spf[x];
    }
    return ret;
}

ll sumToTime (int t, vi &fact) {
    int sz = (int)fact.size();
    ll rta = 0;
    forsn(i,1,1<<sz) {
        int bits = 0, mult = 1;
        int key = 1;
        forn(k,sz) if(i&(1<<k)) key *= fact[k], bits++;
        if (!(bits & 1)) mult *= -1; // inclusion-exclusion
        
        auto &vec = sums[key];

        int ind = upper_bound(all(vec), (pair<int, ll>){t, INFL})-vec.begin()-1;
        ll val = 0;
        if (ind >= 0 && ind < (int)vec.size())
            val = vec[ind].snd;

        rta += val * mult;
    }
    return rta;
}

int main() {
    criba();

    int n,q; scanf("%d %d",&n,&q);

    forn(i,n) scanf("%d",&inipos[i]);

    forn(i,q) {
        int c,d; scanf("%d %d",&c,&d);
        vi aux = fact_uniq(c);
        int sz = (int)aux.size();
        forsn(j,1,1<<sz) {
            int key = 1;
            forn(k,sz) if (j&(1<<k)) key *= aux[k];
            auto &vec = sums[key];
            
            ll last_val = 0;
            if (!vec.empty()) last_val = vec.back().snd;
            vec.pb({i, last_val + d});
        }
    }

    forn(i,n) {
        int x = inipos[i];

        vi my_fact = fact_uniq(i+1);

        int low = -1, high = q-1; // tiempo hasta mid inclusive
        while (high-low > 1) {
            int mid = (high+low)/2;
            if (sumToTime(mid, my_fact) >= x)
                high = mid;
            else low = mid;
        }

        if (sumToTime(high, my_fact) >= x) printf("%d\n",high+1);
        else printf("-1\n");
    }
    
    return 0;
}
