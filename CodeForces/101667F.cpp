// Also see: https://codeforces.com/gym/379556/problem/D
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

int main() {
	int l,s; scanf("%d %d",&l,&s);

	int tot = l; tot *= tot;
	int quad = tot >> 2;

	// me encuentro en el i-esimo cuadrante, en orden (SO, NO, NE, SE)
	int x = 1, y = 1;
	int ord = 0, ccw = 0;

	while (l > 1) {
		int pos = (s + quad - 1) / quad; // hace ceil
		pos--; // luego 0-indexed

		int act_cuadrante = (ord + pos*(ccw ? -1 : 1) + 4)%4;
		if (act_cuadrante == 1 || act_cuadrante == 2) y += l/2;
		if (act_cuadrante == 2 || act_cuadrante == 3) x += l/2;
		
		s -= pos*quad;
		if (pos == 0) ccw ^= 1;
		if (pos == 3) ccw ^= 1, ord = (ord+2)%4;
		l >>= 1, quad >>= 2;
	}

	printf("%d %d",x,y);


	return 0;
}
