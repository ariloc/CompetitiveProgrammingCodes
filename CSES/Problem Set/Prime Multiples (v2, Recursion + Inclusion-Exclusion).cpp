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

// We can also think that multiplying a number by itself
// makes at most log(n) operations, since 2 is as smallest as it gets.

// Knowing this, plus that primes get bigger (we know they are distinct)
// and that they are at most 20 of them, probably multiplying
// them in all possible combinations is, worst case scenario,
// a little better than using inclusion-exclusion for each bitmask
// (because we can quickly cut short if there's an overflow).
// Sounds similar as when comparing Top-Down vs Bottom-Up DP.

const int MAXK = 20;

ll primes[MAXK];
ll n; int k;

ll check (ll num, int act) {
	ll exclude = 0;
	forsn(i,act+1,k) // Try each pair ONCE
		if (num <= n/primes[i])
			exclude += check(num*primes[i],i);

	return (n/num) - exclude;
}

int main() {
	scanf("%lld %d",&n,&k);
	forn(i,k) scanf("%lld",&primes[i]);

	ll rta = 0;
	forn(i,k) rta += check(primes[i],i);

	printf("%lld",rta);

	return 0;
}
