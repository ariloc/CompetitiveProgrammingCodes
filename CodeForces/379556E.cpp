// https://codeforces.com/gym/379556/problem/E
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

const int X[] = {1,0,-1,0};
const int Y[] = {0,1,0,-1};

const int MAXN = 105;

char tablero[MAXN][MAXN];

int main() {
	int n; scanf("%d",&n);
	forn(i,n) scanf("%s",tablero[i]);

	bool posib = true;
	forn(i,n) forn(j,n) {
		int cnt = 0;
		forn(k,4) {
			int tX = j+X[k], tY = i+Y[k];
			if (tX < 0 || tY < 0 || tX >= n || tY >= n) continue;
			if (tablero[tY][tX] == 'o') cnt++;
		}
		if (cnt&1) {posib = false; break;}
	}

	printf("%s",posib ? "YES" : "NO");

	return 0;
}
