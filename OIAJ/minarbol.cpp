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

bool operator< (const list<char> &lhs, const list<char> &rhs) {
	auto x = lhs.begin(), y = rhs.begin();
	if (lhs.empty()) return false;
	if (rhs.empty()) return true;

	while (x != lhs.end() && y != rhs.end())
		if (*x != *y) return (*x != *y);

	if (x == lhs.end()) return true;
	return false;
}

int ind = 1;
list<char> dfs (string &s) {

	vector<list<char>> children;
	while (s[ind] == '(')
		++ind, children.pb(dfs(s));
	
	sort(all(children));
	list<char> ret;
	ret.push_back('(');
	for (auto &i : children) ret.splice(ret.end(), i);
	ret.push_back(')');

	++ind;
	return ret;
}

string minarbol(string &s) {
	list<char> r_list = dfs(s);

	string rta;
	for (auto &i : r_list)
		rta.pb(i);

	return rta;
}
