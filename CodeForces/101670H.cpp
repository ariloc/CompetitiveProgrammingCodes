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

const int MAXN = 200005;

int arr[MAXN];

int main() {
	FAST_IO;
	
	int n;
	while (cin >> n) {
		forn(i,n) cin >> arr[i], arr[i]--;
		
		int cnt = 0;
		forn(i,n) {
			while (arr[i] != i) {
				swap(arr[arr[i]], arr[i]);
				cnt++;
			}
		}
		
		cout << cnt << endl;
	}
	
	return 0;
}
