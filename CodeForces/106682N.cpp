#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

int const MOD = 998244353;
int const MAXN = 2e6+5;

int fact[MAXN];
int pota[MAXN];

int binExp(int a, int k) {
	int r = 1;
	while (k) {
		if (k&1) r = (r*(ll)a)%MOD;
		a = (a*(ll)a)%MOD; k >>= 1;
	}
	return r;
}

int calc(int n, int k, int a) {
    int cuts = n-1-k;
    if (cuts < 0) return 0;
	int bol = k, pal = cuts;
	int r = (((fact[bol+pal] * (ll)binExp(fact[bol],MOD-2))%MOD) * (ll)binExp(fact[pal],MOD-2))%MOD;
	return (((r * (ll)pota[cuts])%MOD) * (ll)a)%MOD;
}

int main() {
	FAST_IO;
	
	fact[0] = 1;
	forsn(i,1,MAXN) fact[i] = (fact[i-1] * (ll)i)%MOD;
	
	int n,k,a; cin >> n >> k >> a;
	
	pota[0] = 1;
	forsn(i,1,MAXN) pota[i] = (pota[i-1] * (ll)(a-1))%MOD;
	
	if (n == 1) {
		if (k == 0) cout << a << '\n';
		else cout << "0\n";
		return 0;
	}
	
	if (n <= 2) {
		if (k == 0) cout << a*a << '\n';
		else cout << "0\n";
		return 0;
	}
	
	int od = n/2, ev = (n+1)/2;
	
	int rta = 0;
	forn(i,k+1) {
		int v1 = calc(od,i,a), v2 = calc(ev,k-i,a);
		rta = (rta + ((v1 * (ll)v2)%MOD))%MOD;
	}
	
	cout << rta << '\n';
	
	return 0;
}
