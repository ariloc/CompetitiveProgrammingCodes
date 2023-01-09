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

const int MAXN = 1e6+5;
const int MOD = 1e9+7;

int fact[MAXN], inv[MAXN], invFact[MAXN];

int nCk (int n, int k) {
    return (((ll)fact[n] * invFact[k])%MOD * (ll)invFact[n-k])%MOD;
}

int main() {
    fact[0] = 1, invFact[0] = 1, inv[1] = 1;

    forsn(i,1,MAXN) fact[i] = (fact[i-1] * (ll)i)%MOD;
    forsn(i,2,MAXN) inv[i] = MOD - ((ll)(MOD/i) * inv[MOD%i])%MOD;
    forsn(i,1,MAXN) invFact[i] = ((ll)invFact[i-1] * inv[i])%MOD;

    int n; scanf("%d",&n);

    int rta = 0;
    forn(i,n+1) {
        int x = ((ll)fact[n-i] * nCk(n,i))%MOD;
        rta = (rta + (i%2 ? -1 : 1)*(ll)x)%MOD;
        rta = (rta + MOD)%MOD;
    }

    printf("%d",rta);

    return 0;
}
