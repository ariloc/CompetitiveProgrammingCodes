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

const int MAXA = 26;

int sum[MAXA][2], refer[MAXA][2];

void add (char c, int arr[][2], int v) {
	if (isupper(c)) arr[c-'A'][1] += v;
	else arr[c-'a'][0] += v;
}

bool compare() {
	forn(i,MAXA) forn(k,2)
		if (sum[i][k] != refer[i][k])
			return false;
	return true;
}

int main() {
	FAST_IO;

	int g,n; cin >> g >> n;

	string w; cin >> w;
	string s; cin >> s;

	for (auto &i : w)
		add(i,refer,1);

	if (g > n) {printf("0"); return 0;}

	forn(i,g) add(s[i],sum,1);

	int cnt = 0;
	forsn(i,g,n) {
		cnt += compare();
		add(s[i-g],sum,-1);
		add(s[i],sum,1);
	}

	cnt += compare();

	printf("%d",cnt);

	return 0;
}
