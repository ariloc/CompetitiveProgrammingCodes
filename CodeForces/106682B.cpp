#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define pb push_back 

using namespace std;

bool isvow(char c) {
	return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int main() {
	string s; cin>> s;
	int n = (int)s.size();
	
	set<string> posib;
	forsn(i,4,n) {
		string aux = s.substr(i-3,3);
		if (s[i] == s[i-4] && isvow(s[i]) && aux == "GAS") {
			string aux2;
			forn(j,n) {
				if (j == i-4) j = j+3;
				else aux2.pb(s[j]);
			}
			posib.insert(aux2);
		}
	}
	
	if (posib.empty()) {
		cout << "-\n";
	}
	else if ((int)posib.size() > 1) {
		cout << "+\n";
	}
	else {
		cout << (*posib.begin()) << '\n';
	}
	
	return 0;
}
