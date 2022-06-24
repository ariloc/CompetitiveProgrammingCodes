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

const int MAXA = 200;

int sum[MAXA];

int main() {
	FAST_IO;

	int g,n; cin >> g >> n;

	string w; cin >> w;
	string s; cin >> s;

	if (g > n) {printf("0"); return 0;}
	
	for (auto &i : w) sum[i]++;
	
	int pending = 0;
	forn(i,g) sum[s[i]]--;
	forsn(i,'a','z'+1) pending += max(0,sum[i]);
	forsn(i,'A','Z'+1) pending += max(0,sum[i]);

	int cnt = (!pending);
	forsn(i,g,n) {
		pending -= max(0,sum[s[i]]) + max(0,sum[s[i-g]]);
		sum[s[i-g]]++, sum[s[i]]--;
		pending += max(0,sum[s[i]]) + max(0,sum[s[i-g]]);
		if (!pending) cnt++;
	}

	cout << cnt;

	return 0;
}
