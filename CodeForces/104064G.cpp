#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int MAXN = 5005;
const int INF = 2e9;

int len[MAXN];
vector<string> inp;
int dp[MAXN],P[MAXN];
vector<vi> col;
vi lencol;
int n,w;

bool posib (int mid) {
	forn(i,n+2) dp[i] = INF, P[i] = -1;
	dp[0] = 0;
	forsn(i,1,n+1) {
		int maxi = -1;
		forsn(j,i,min(i+mid,n+1)) {
			maxi = max(maxi, len[j-1]);
			int val = dp[i-1] + maxi + 1;
			if (val < dp[j]) {
				P[j] = i-1;
				dp[j] = val;
			}
		}
	}
	return dp[n] != INF && dp[n]-1 <= w;
}

/*
9 30
algorithm
contest
eindhoven
icpc
nwerc
programming
regional
reykjavik
ru

*/

int main() {
	FAST_IO;
	
	cin >> n >> w;
	forn(i,n) {
		string s; cin >> s;
		len[i] = (int)s.size();
		inp.pb(s);
	}
	
	int low = -1, high = n;
	while (high - low > 1) {
		int mid = (high + low)/2;
		if (posib(mid)) high = mid;
		else low = mid;
	}
	
	posib(high);
	
	vi cant;
	int aux = n;
	while (aux != 0) {
		cant.pb(aux-P[aux]);
		aux = P[aux];
	}
	reverse(all(cant));
	
	int mcol = (int)cant.size();
	col.resize(mcol);
	lencol.resize(mcol, 0);

	int ind = 0;
	forn(i,mcol) {
		forsn(j,ind,ind+cant[i]) {
			col[i].pb(j);
			lencol[i] = max(lencol[i], len[j]);
		}
		ind += cant[i];
	}

	
	forn(k,mcol) reverse(all(col[k]));
	
	cout << high << ' ' << mcol << '\n';
	forn(i,mcol) cout << lencol[i] << ' ';
	cout << '\n';
	
	int proc = 0;
	while (proc < n) {
		forn(k,mcol) {
			if (col[k].empty())
				cout << string(lencol[k], ' ');
			else {                                                                        
				cout << inp[col[k].back()];
				cout << string(lencol[k]-(int)inp[col[k].back()].size(), ' ');
				proc++;
				col[k].pop_back();
			}
			cout << ' ';
		}
		cout << '\n';
	}
	
	
	return 0;
}
