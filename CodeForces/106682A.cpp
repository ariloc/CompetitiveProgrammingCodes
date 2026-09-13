#include <bits/stdc++.h>

using namespace std;

int main() {
	int h,m,s; cin >> h >> m >> s;
	
	if (h == 2 && m == 30 && s == 0) {
		cout << "=\n";
	}
	else if (h < 2 || (h == 2 && m < 30)) {
		cout << "-\n";
	}
	else cout << "+\n";
	
	
	return 0;
}
