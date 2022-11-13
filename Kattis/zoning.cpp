#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int MAXN = 2005;
const int Y[] = {1,0,-1,0};
const int X[] = {0,1,0,-1};

string mat[MAXN];
int dist[MAXN][MAXN];

int main() {
	FAST_IO;
	
	int n; cin >> n;
	forn(i,n) cin >> mat[i];
	
	forn(i,n) forn(j,n) dist[i][j] = -1;
	
	queue<ii> Q;
	forn(i,n) forn(j,n) if (mat[i][j] == '3')
		Q.push({j,i}), dist[i][j] = 0;
		
		while (!Q.empty()) {
			auto e = Q.front(); Q.pop();
			
			forn(k,4) {
				int tX = e.fst + X[k], tY = e.snd + Y[k];
				
				if (dist[tY][tX] != -1) continue;
				if (tY < 0 || tX < 0 || tY >= n || tX >= n) continue;
				
				dist[tY][tX] = dist[e.snd][e.fst]+1;
				Q.push({tX,tY});
			}
		}
		
		int maxi = 0;
		forn(i,n) forn(j,n) if (mat[i][j] == '1') maxi = max(maxi, dist[i][j]);
		
		cout << maxi << '\n';
		
		return 0;
}
