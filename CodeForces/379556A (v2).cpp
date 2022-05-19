// https://codeforces.com/gym/379556/problem/A
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

const int MAXN = 2e5+5;

ii arr[MAXN];

int main() {
	int n, x; scanf("%d %d",&n,&x);
	forn(i,n) scanf("%d",&arr[i].fst), arr[i].snd = i;

	sort(arr,arr+n);

	int l = 0;
	ii sol = {-1,-1};
	dforn(r,n) {
		while (l < n && arr[l].fst + arr[r].fst < x) l++;
		if (arr[l].fst + arr[r].fst == x && l != r) sol = {arr[l].snd, arr[r].snd};
		if (l == r && l+1 < n && arr[l+1].fst + arr[r].fst == x)
			sol = {arr[l+1].snd, arr[r].snd};
	}

	if (sol.fst == -1) printf("-1");
	else printf("%d %d",sol.fst+1,sol.snd+1);

	return 0;
}
