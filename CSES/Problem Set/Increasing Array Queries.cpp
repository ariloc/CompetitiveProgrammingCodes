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
const int MAXST = (1<<(32-__builtin_clz(MAXN)));
 
void fs (int &x) {
    int c; x = 0;
    c = getchar_unlocked();
    if (c < '0' || c > '9') c = getchar_unlocked();
    for (; c >= '0' && c <= '9'; c = getchar_unlocked())
        x = 10*x + c-'0';
}
 
struct mon {
    int maxi,pos;
 
    mon(){maxi = -INF, pos = -1;}
    mon(int maxi, int pos) : maxi(maxi), pos(pos){}
 
    mon operator+ (const mon &o) const {
        if (o.maxi >= maxi) return o;
        return *this;
    }
};
 
int N;
mon ST[2*MAXST];
 
mon query (int l, int r) {
    mon ret;
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l&1) ret = ret + ST[l++];
        if (r&1) ret = ret + ST[--r];
    }
    return ret;
}
 
int arr[MAXN], geqL[MAXN], gtR[MAXN];
ll dp[MAXN], adds[MAXN];
 
int main() {
    int n,q; fs(n), fs(q);
    forn(i,n) fs(arr[i+1]);
 
    N = (1<<(32-__builtin_clz(n)));
    forn(i,n) ST[i+N] = {arr[i+1],i+1};
    dforsn(i,1,N) ST[i] = ST[2*i] + ST[2*i+1];
 
    arr[n+1] = arr[0] = INF;
    dforsn(i,1,n+1) {int j; for (j = i+1; arr[j] <= arr[i]; j = geqL[j]); geqL[i] = j;}
    forsn(i,1,n+1) {int j; for (j = i-1; arr[j] < arr[i]; j = gtR[j]); gtR[i] = j;}
    
    arr[n+1] = arr[0] = 0;
    forsn(i,1,n+2) dp[i] += dp[i-1] - arr[i];
 
    // para atras miro el mayor (gt) y no mayor o igual (geq),
    // porque tengo que sumar tambien los bloques iguales
    forsn(i,1,n+1) {
        int geq_nxt = geqL[i], gt_prv = gtR[i];
        ll calc = (dp[geq_nxt-1] - dp[i-1]) + (ll)(geq_nxt-i) * arr[i];
        adds[gt_prv+1] += calc, adds[i+1] -= calc;
    }
 
    forsn(i,1,n+1) adds[i] += adds[i-1];
 
    forn(i,q) {
        int l,r; fs(l), fs(r);
        mon aux = query(l-1, r);
        int nxt = geqL[aux.pos];
        printf("%lld\n",adds[l] - adds[nxt] - ((ll)(dp[nxt-1]-dp[r]) + (ll)(nxt-r-1) * arr[aux.pos]));
    }
 
    return 0;
}