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

const int MAXN = 50005;
const int MAXST = (1<<(32-__builtin_clz(MAXN)));
const int INF = 10000;

struct mon {
	int sum_l, sum_r, sum, sum_tot;
	mon(){sum_l = sum_r = sum = sum_tot = -INF;}
	mon (int a, int b, int c, int d) : sum_l(a), sum_r(b), sum(c), sum_tot(d) {}

	mon operator+ (const mon &o) const {
		return mon( max(sum_l, sum_tot + o.sum_l),
					max(o.sum_r, o.sum_tot + sum_r),
			   		max(max(sum, o.sum), sum_r + o.sum_l),
					sum_tot + o.sum_tot
				  );
	}
};

int N;
mon ST[2*MAXST];

void update (int p, int v) {
	p += N; ST[p] = mon(v,v,v,v);
	while (p > 1)
		p /= 2, ST[p] = ST[2*p] + ST[2*p+1];
}

mon query (int i, int bl, int br, int tl = 0, int tr = N) {
	if (tl >= br || tr <= bl) return mon();
	if (tl >= bl && tr <= br) return ST[i];

	int mid = (tl+tr)/2;
	return query(2*i,bl,br,tl,mid) + query(2*i+1,bl,br,mid,tr);
}

int main() {
	int n; scanf("%d",&n);

	N = (1<<(32-__builtin_clz(n)));

	forn(i,n) {
		int x; scanf("%d",&x);
		ST[i+N] = mon(x,x,x,x);
	}

	dforsn(i,1,N) ST[i] = ST[2*i] + ST[2*i+1];

	int m; scanf("%d",&m);
	forn(_,m) {
		int typ,x,y; scanf("%d %d %d",&typ,&x,&y);

		if (!typ) update(--x, y);
		else printf("%d\n",query(1,--x,y).sum);
	}

	return 0;
}
