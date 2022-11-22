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

const int MOD = 1e9+7;
const int MAXN = 1e6+5;

int fact[MAXN], inv[MAXN], invfact[MAXN], pot[MAXN];

int nCk (int n, int k) {
    if (n < 0 || k < 0) return 0;
    return ( ((fact[n] * (ll)invfact[k])%MOD) * (ll)invfact[n-k] )%MOD;
}

int pot3 (int a) {
    if (a < 0) return 0;
    return pot[a];
}

int sumMod (int a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

int main() {
    int n,k; scanf("%d %d", &n, &k);

    fact[0] = 1, inv[1] = 1, invfact[0] = 1;
    forsn(i,1,MAXN) fact[i] = (fact[i-1] * (ll)i)%MOD;
    forsn(i,2,MAXN) inv[i] = MOD - ((ll)(MOD/i) * inv[MOD%i])%MOD;
    forsn(i,1,MAXN) invfact[i] = (invfact[i-1] * (ll)inv[i])%MOD;

    pot[0] = 1;
    forsn(i,1,MAXN) pot[i] = (pot[i-1] * 3LL)%MOD;

    if (!k) {
        printf("%d\n", pot[n]);
        return 0;
    }

    int rta = 0;
    forsn(b,1,k+1) {
        int distrib = nCk(k-1, k-b);
        int general = ( ((distrib * (ll)nCk(n-k, n-b-k))%MOD) * (ll)pot3(n-2*b) )%MOD;
        int edge = ( ((distrib * (ll)nCk(n-k, n-b-k+1))%MOD) * (ll)pot3(n-2*b+1) )%MOD;
        rta = sumMod(sumMod(rta, general), edge);
    }

    printf("%d", rta);

    return 0;
}
