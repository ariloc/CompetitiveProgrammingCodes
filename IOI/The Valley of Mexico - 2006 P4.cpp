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

const int MAXN = 1005;
const int INF = 1e9;

bool ady[MAXN][MAXN];
// covered i to j, available ends
bool dp[MAXN][MAXN][2];

int main() {
	int c,n; scanf("%d %d",&c,&n);
	forn(i,n) {
		int u,v; scanf("%d %d",&u,&v);
		--u, --v;
		ady[u][v] = ady[v][u] = 1;
	}

	forn(i,c) dp[i][i][0] = dp[i][i][1] = 1;

	dforn(i,c) forn(k,c) {
		int j = (i+k)%c, prv = (i-1+c)%c, nxt = (j+1)%c;
		dp[prv][j][0] |= (ady[i][prv] && dp[i][j][0]);
		dp[i][nxt][1] |= (ady[j][nxt] && dp[i][j][1]);
		dp[prv][j][0] |= (ady[j][prv] && dp[i][j][1]);
		dp[i][nxt][1] |= (ady[nxt][i] && dp[i][j][0]);
	}

	forn(i,c) forn(k,2) if (dp[i][(i-1+c)%c][k]) {
		int l = i, r = (i-1+c)%c, s = k, last = -1;
		while (l != r) {
			printf("%d\n",(s ? r : l)+1);
			last = (s ? r : l);

			if (!s) l = (l+1)%c;
			else r = (r-1+c)%c;
			
			if (!dp[l][r][s] || !ady[last][s ? r : l]) s ^= 1;
		}
		printf("%d\n",l+1);
		return 0;
	}

	printf("-1");

	return 0;
}
