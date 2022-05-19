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

const int MOD = 1e9+7;
const int MAXN = 1e5+5;

struct factor {
	int a,k;
};

factor fact[MAXN];
int phi_prefs[MAXN], phi_sufs[MAXN];

int binExp (int a, ll k, int mod) {
	int r = 1;
	while (k) {
		if (k&1) r = (r*(ll)a)%mod;
		a = (a*(ll)a)%mod; k >>= 1;
	}
	return r;
}

int pow_sum (int a, int k, int mod) {
	return ((binExp(a,k+1,mod)-1) * (ll)binExp(a-1,MOD-2,mod) + mod)%mod;
}

int calc_prod (int s_phi, int a, int k, int mod) {
	int phi = mod-1;
	ll gauss = (k*(ll)(k+1))/2LL;
	return binExp(binExp(a,gauss,mod), s_phi%phi, mod);	
}

int main() {
	int n; scanf("%d",&n);
	forn(i,n) scanf("%d %d",&fact[i].a,&fact[i].k);

	int num = 1, sum = 1, prod = 1;

	// number of divisors
	forn(i,n) num = (num * (ll)(fact[i].k+1))%MOD;

	// sum of divisors
	forn(i,n) sum = (sum * (ll)pow_sum(fact[i].a,fact[i].k,MOD))%MOD;

	// product of divisors
	dforsn(i,1,n+1) fact[i] = fact[i-1];
	fact[0].k = 0;
	
	int PHI = MOD-1;
	phi_prefs[0] = phi_sufs[n+1] = 1;
	forsn(i,1,n+1) phi_prefs[i] = (phi_prefs[i-1] * (ll)(fact[i].k+1))%PHI;
	dforsn(i,1,n+1) phi_sufs[i] = (phi_sufs[i+1] * (ll)(fact[i].k+1))%PHI;

	forsn(i,1,n+1)
		prod = (prod * (ll)calc_prod( (phi_prefs[i-1] * (ll)phi_sufs[i+1])%PHI ,fact[i].a,fact[i].k,MOD))%MOD;

	printf("%d %d %d",num,sum,prod);

	return 0;
}
