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

struct edges {
	int v,id;
};

vector<edges> G[MAXN];
ii inp[MAXN];
vi comps[MAXN]; // nodos de cada componente
int comps_isin[MAXN]; // cantidad de componentes distintas en las que esta
bitset<MAXN> matched, matched_tmp;
int tin[MAXN], actT = 1, comp_cnt = 0;

vi pila;
int tarjan (int st) {
	tin[st] = actT++;

	int mini = tin[st];
	for (auto &i : G[st]) {
		if (!matched[i.id]) {
			int myMini = tin[st];
			matched[i.id] = true;
			pila.pb(i.id);
			// cerr << st+1 << "->" << i.v+1 << "RECORRE" << endl;

			if (!tin[i.v]) myMini = min(myMini,tarjan(i.v));
			myMini = min(myMini, tin[i.v]);

			if (myMini >= tin[st]) {
				vi nodes;
				while (!pila.empty()) {
					auto e = pila.back(); pila.pop_back();
					int exts[] = {inp[e].fst, inp[e].snd};
					forn(k,2)
						if (!matched_tmp[exts[k]]) matched_tmp[exts[k]] = true, nodes.pb(exts[k]);

					if (e == i.id) break;
				}

				for (auto &j : nodes) {
					comps_isin[j]++;
					comps[comp_cnt].pb(j);
					matched_tmp[j] = false;
				}

				comp_cnt++;
			}

			mini = min(mini,myMini);
		}
	}
	return mini;
}

int main() {
	int o = 0, n; 
	while (scanf("%d",&n) != -1) {
		if (!n) break;
		actT = 1, comp_cnt = 0;

		forn(i,2*n) G[i].clear(), tin[i] = 0, matched[i] = 0, comps_isin[i] = 0, comps[i].clear();

		int maxi = -1;
		forn(i,n) {
			int u,v; scanf("%d %d",&u,&v), u--, v--;

			maxi = max(maxi,max(u,v));

			G[u].pb({v,i}), G[v].pb({u,i});
			inp[i] = {u,v};
		}
		maxi++;

		tarjan(0);

		int art_pts = 0;
		forn(i,2*n) if (comps_isin[i] > 1) art_pts++;

		printf("Case %d: ",o+1);
		if (!art_pts) printf("2 %lld\n",(ll)maxi*(maxi-1)/2LL); // nunca va a ser uno, en todo caso las combinaciones de tomar de a 2
		else {
			ll cntr = 0, posibr = 1;
			forn(i,comp_cnt) {
				int isleaf = 0, cntcomp = 0;
				for (auto &j : comps[i])
					if (comps_isin[j] > 1) isleaf++;
					else cntcomp++;

				if (isleaf <= 1)
					cntr++, posibr *= (ll)cntcomp;
			}

			printf("%lld %lld\n",cntr,posibr);
		}

		o++;
	}

    return 0;
}
