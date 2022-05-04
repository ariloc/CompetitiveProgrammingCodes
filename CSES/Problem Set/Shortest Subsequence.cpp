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
	FAST_IO;

	string s; cin >> s;
	string r;
	int used = 0;
	int l_ind[] = {0,0,0,0};
	forn(i,s.size()) {
		char c = s[i];
		int ind = (c == 'A' ? 0 : c == 'C' ? 1 : c == 'G' ? 2 : 3);
		if (!l_ind[ind]) l_ind[ind] = 1, used++;
		if (used == 4) r.pb(c), used = 0, l_ind[0] = l_ind[1] = l_ind[2] = l_ind[3] = 0;
	}
	forn(k,4) if (!l_ind[k]) {r.pb(!k ? 'A' : k == 1 ? 'C' : k == 2 ? 'G' : 'T'); break;}

	cout << r;

	return 0;
}
