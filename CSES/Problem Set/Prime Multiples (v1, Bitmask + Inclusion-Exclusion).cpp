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

const int MAXK = 20;

ll primes[MAXK];

int main() {
	ll n; int k; scanf("%lld %d",&n,&k);
	forn(i,k) scanf("%lld",&primes[i]);

	ll rta = 0;
	forsn(i,1,(1<<k)) {
		int bits = 0;
		ll mcm = 1; // given they are prime, there's no need to divide by the gcd
		bool overflow = 0;
		forn(j,k)
			if (i&(1<<j)) {
				bits++;
				if (n/primes[j] < mcm)
					overflow = 1;
				if (!overflow)
					mcm *= primes[j];
			}

		if (overflow) continue;

		if (bits & 1)
			rta += n / mcm;
		else rta -= n / mcm;
	}

	printf("%lld",rta);

	return 0;
}
