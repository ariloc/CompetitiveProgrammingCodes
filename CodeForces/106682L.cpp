#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef pair<int,int> ii;

int const MAXN = 2e5+5;

ii dpl[MAXN], dpr[MAXN];
int arr[MAXN];
bitset<MAXN> have;
int nxthave[MAXN];
int lseen[MAXN];
int fposr[MAXN], fposl[MAXN];

int main() {
	FAST_IO;
	
	int n,m; cin >> n >> m;
	
	forn(i,n) cin >> arr[i];
	
	forn(i,n) have[arr[i]] = true;
	int last = -1;
	forsn(i,1,m+1) {
		if (have[i]) {
			last = i; break;
		}
	}
	
	int curlast = last;
	forsn(i,last+1,m+1) {
		if (!have[i]) continue;
		nxthave[curlast] = i;
		curlast = i;
	}
	nxthave[curlast] = -1; // dummy
	
	forn(i,n) dpl[i] = dpr[i] = {1,arr[i]};
	forsn(i,1,m+1) lseen[i] = -1;
	dforn(i,n) {
		lseen[arr[i]] = i;
		if (nxthave[arr[i]] == -1) continue;
		if (lseen[nxthave[arr[i]]] == -1) continue;
		ii auxi = dpr[lseen[nxthave[arr[i]]]];
		dpr[i] = {1+auxi.fst, auxi.snd};
	}
	forsn(i,1,m+1) lseen[i] = -1;
	forn(i,n) {
		lseen[arr[i]] = i;
		if (nxthave[arr[i]] == -1) continue;
		if (lseen[nxthave[arr[i]]] == -1) continue;
		ii auxi = dpl[lseen[nxthave[arr[i]]]];
		dpl[i] = {1+auxi.fst, auxi.snd};
	}
	
	int lasthave = -1;
	forsn(i,1,m+1) if (have[i]) lasthave = i;
	
	forsn(i,1,m+1) fposl[i] = fposr[i] = -1;
	forn(i,n) if (fposl[arr[i]] == -1) fposl[arr[i]] = i;
	dforn(i,n) if (fposr[arr[i]] == -1) fposr[arr[i]] = i;
	
	int cur = last;
	int cnt = 0, pak = 0;
	while (cur != -1) {
		ii maxi = max(dpl[fposr[cur]], dpr[fposl[cur]]);
		cnt += maxi.fst;
		cur = nxthave[maxi.snd]; ++pak;
	}
	
	cout << cnt << ' ' << pak << '\n';
	
	return 0;
}
