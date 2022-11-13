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

const int MAXN = 100005;

int cang[MAXN], ejer[MAXN];

int main() {
	int n,m; scanf("%d %d",&n,&m);
	
	forn(i,n) scanf("%d",&cang[i]);
	forn(i,m) scanf("%d",&ejer[i]);
	
	ll sum = 0;
	forn(i,m) sum += ejer[i];
	
	sort(cang, cang+n);
	
	ll acc = 0; int cnt = 0;
	dforn(i,n) {
		acc += cang[i];
		cnt++;
		if (acc >= sum) break;
	}
	
	if (acc < sum) printf("0 0\n");
	else printf("1 %d\n", cnt);
	
	return 0;
}
