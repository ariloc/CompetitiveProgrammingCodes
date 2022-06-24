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

const int MAXN = 3005;
const int INF = 2e9;

struct edge_full {
	int u,v,w;

	bool operator< (const edge_full &o) const {
		return w < o.w;
	}
};

struct edge {
	int v,w;
};

struct DS {
	vi p,r;

	void init (int N) {
		p.assign(N,0);
		r.assign(N,0);
		forn(i,N) p[i] = i;
	}

	int find (int x) {return p[x] == x ? x : p[x] = find(p[x]);}

	bool join (int a, int b) {
		int x = find(a), y = find(b);
		if (x == y) return false;
		if (r[x] > r[y]) swap(x,y);
		p[x] = y;
		if (r[x] == r[y]) r[y]++;
		return true;
	}
};

vector<edge_full> edges;
vector<edge> G[MAXN];
int D[MAXN][MAXN];
DS UF;

void dfs (int st, int act, int acc = 1) {
	if (D[st][act] != INF)
		return;

	D[st][act] = acc;

	for (auto &i : G[act])
		if (D[st][i.v] == INF)
			dfs(st,i.v,max(acc,i.w));
}

int main() {
	int c,l,h;
	while (scanf("%d %d %d",&c,&l,&h) != -1) {
		if (c == -1 && l == -1 && h == -1)
			break;

		forn(i,c) G[i].clear();
		edges.clear();
		UF.init(c+2);	

		forn(i,l) {
			int a,b,v; scanf("%d %d %d",&a,&b,&v);
			--a, --b;
			edges.pb({a,b,v});
		}
		
		sort(all(edges));
		for (auto &i : edges)
			if (UF.join(i.u,i.v))
				G[i.u].pb({i.v,i.w}), G[i.v].pb({i.u,i.w});

		forn(i,c) {
			forn(j,c) D[i][j] = INF;
			dfs(i,i);
		}
		
		forn(i,h) {
			int s,t; scanf("%d %d",&s,&t);
			--s, --t;
			printf("%d ",D[s][t]);
		}
		puts("");
	}

	return 0;
}
