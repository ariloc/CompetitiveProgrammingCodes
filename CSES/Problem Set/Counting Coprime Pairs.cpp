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
 
const int MAXN = 1e5+5;
const int MAXNUM = 1e6+5;
 
int arr[MAXN], spf[MAXNUM];
int mults[MAXNUM];
bitset<MAXNUM> done;
 
void criba() {
    forn(i,MAXNUM) spf[i] = i;
    for (int i = 4; i < MAXNUM; i += 2)
        done[i] = true, spf[i] = 2;
    for (int i = 3; i*i <= MAXNUM; i++)
        if (!done[i])
            for (int j = i+i; j < MAXNUM; j += i)
                if (!done[j]) done[j] = true, spf[j] = i;
}
 
int main() {
    criba();
    int n; scanf("%d",&n);
 
    forn(i,n) scanf("%d",&arr[i]);
 
    ll rta = 0;
    forn(i,n) {
        int aux = arr[i];
 
        int prv = -1;
        vi fact;
        while (aux > 1) {
            if (spf[aux] != prv) prv = spf[aux], fact.pb(prv);
            aux /= spf[aux];
        }
 
        int m = (int)fact.size();
        int v = 0;
        vi pending;
        forsn(j,1,1<<m) {
            int ind = 1, bits = 0;
            forn(k,m) if (j&(1<<k)) ind *= fact[k], bits++;
            //cerr << arr[i] << ' ' << mults[ind] << ' ' << ind << endl;
 
            int sgn = (bits&1) ? 1 : -1;
            pending.pb(ind);
            v += sgn * mults[ind];
        }
 
        rta -= v;
        rta += (n-v-1);
        for (auto &j : pending) mults[j]++;
    }
 
    printf("%lld",rta/2);
 
    return 0;
}
