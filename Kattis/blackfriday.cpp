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

int arr[7], ind[7];

int main() {
	int n; scanf("%d",&n);
	
	forn(i,n) {
		int x; scanf("%d",&x);
		arr[x]++;
		ind[x] = i;
	}
	
	int posib = -1;
	dforn(i,7) {
		if (arr[i] == 1) {
			posib = ind[i]; break;
		}
	}
	
	if (posib == -1)
		printf("none\n");
	else printf("%d\n",posib+1);
	
	return 0;
}
