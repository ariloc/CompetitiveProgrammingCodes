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

int main() {
	int n; scanf("%d",&n);
	
	int aux = 2018, mo = 3;
	while (aux < n) {
		mo += 26;
		aux += mo/12;
		mo %= 12;
	}
	
	if (aux == n)
		printf("yes\n");
	else printf("no\n");
	
	return 0;
}
