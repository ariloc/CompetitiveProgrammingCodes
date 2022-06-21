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

const int MAXN = 1e5+5;
const int MAXST = (1<<(32-__builtin_clz(MAXN)));
const int INF = 2e9;

struct mon {
	int mx1,mx2;
	mon(){mx1 = mx2 = -INF;}
	mon(int a, int b) : mx1(a), mx2(b) {}

	mon operator+ (const mon &o) const {
		mon aux = *this;
		if (o.mx1 > aux.mx1) aux.mx2 = max(aux.mx2, aux.mx1), aux.mx1 = o.mx1;
		else if (o.mx1 > aux.mx2) aux.mx2 = o.mx1;

		if (o.mx2 > aux.mx1) aux.mx2 = max(aux.mx2, aux.mx1), aux.mx1 = o.mx2;
		else if (o.mx2 > aux.mx2) aux.mx2 = o.mx2;

		return aux;
	}
};

int N;
mon ST[2*MAXST];

void update (int p, int x) {
	p += N; ST[p].mx1 = x;
	while (p > 1)
		p /= 2, ST[p] = ST[2*p] + ST[2*p+1];
}

mon query (int l, int r) {
	mon ret;
	for (l += N, r += N; l < r; l /= 2, r /= 2) {
		if (l&1) ret = ret + ST[l++];
		if (r&1) ret = ret + ST[--r];
	}
	return ret;
}

int main() {
	int n; scanf("%d",&n);

	N = (1<<(32-__builtin_clz(n)));

	forn(i,n) scanf("%d",&ST[i+N].mx1);

	dforsn(i,1,N) ST[i] = ST[2*i] + ST[2*i+1];

	int q; scanf("%d",&q);
	forn(_,q) {
		char c; int a,b; getchar();
		scanf("%c %d %d",&c,&a,&b);

		if (c == 'Q') {
			mon r = query(--a,b);
			printf("%d\n",r.mx1 + r.mx2);
		}
		else update(--a, b);
	}

	return 0;
}
