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

const int MAXN = 1010;
const int MAXST = (1<<(32-__builtin_clz(MAXN)));
const int INF = 2e9;

struct mon {
	int v,i,j;
	mon(){v = INF; i = j = -1;}
	mon(int v) : v(v), i(-1), j(-1) {}
	mon(int v, int i, int j) : v(v), i(i), j(j) {}

	mon operator+ (const mon &o) const {
		if ((*this).v < o.v)
			return *this;
		return o;
	}
};

int N;
int grid[MAXN][MAXN];
mon ST[2*MAXST][2*MAXST];

mon query (int j, int i, int bl, int br, int tl = 0, int tr = N) {
	if (tl >= br || tr <= bl) return mon();
	if (tl >= bl && tr <= br) return ST[i][j];

	int mid = (tl+tr)/2;
	return query(2*j,i,bl,br,tl,mid) + query(2*j+1,i,bl,br,mid,tr);
}

mon query_2d (int i, int bl_y, int br_y, int bl_x, int br_x, int tl = 0, int tr = N) {
	if (tl >= br_y || tr <= bl_y) return mon();
	if (tl >= bl_y && tr <= br_y) return query(1, i, bl_x, br_x);

	int mid = (tl+tr)/2;
	return query_2d(2*i,bl_y,br_y,bl_x,br_x,tl,mid) +
		   query_2d(2*i+1,bl_y,br_y,bl_x,br_x,mid,tr);
}

int main() {
	int m,n,a,b,c,d;
	scanf("%d %d %d %d %d %d",&m,&n,&a,&b,&c,&d);

	N = (1<<(32-__builtin_clz(max(n,m)+5)));

	forn(i,n) forn(j,m)
		scanf("%d",&grid[i+1][j+1]);

	forn(i,n+3) forsn(j,1,m+3) {
		grid[i+1][j] += grid[i][j];
		grid[i][j] += grid[i][j-1];
	}

	forsn(i,d,n+3) forsn(j,c,m+3) {
		int sum = grid[i][j] - grid[i][j-c] - grid[i-d][j] + grid[i-d][j-c];
		ST[i+N][j+N] = mon(sum,i,j);
	}

	forn(i,2*N) dforsn(j,1,N) ST[i][j] = ST[i][2*j] + ST[i][2*j+1];
	dforsn(i,1,N) forn(j,2*N) ST[i][j] = ST[2*i][j] + ST[2*i+1][j];

	int max_s = -INF;
	ii sq = {-1,-1}, chamb = {-1,-1};
	forsn(i,b,n+3) forsn(j,a,m+3) {
		int sum = grid[i][j] - grid[i][j-a] - grid[i-b][j] + grid[i-b][j-a];
		mon auxi = query_2d(1, i-b+d+1, i, j-a+c+1, j);
		sum -= auxi.v;

		if (sum > max_s) {
			max_s = sum;
			sq = {i,j};
			chamb = {auxi.i, auxi.j};
		}
	}

	printf("%d %d\n%d %d",sq.snd-a+1,sq.fst-b+1,chamb.snd-c+1,chamb.fst-d+1);

	return 0;
}
