#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

int query (string s) {
	cout << s << endl;
	string rta; getline(cin,rta);
	int ind = -1;
	forn(i,rta.size()) {
		if (rta[i] == '(') {
			ind = i+1;
			break;
		}
	}
	if (ind == -1) {
		exit(0);
	}
	int ms = 0;
	while (ind < (int)rta.size() && rta[ind] >= '0' && rta[ind] <= '9') {
		ms = 10*ms + rta[ind]-'0';
		ind++;
	}
	cerr << ms << endl;
	
	return ms;
}

int getlet (int x) {
	return (x-4) / 9;
}

int main() {
	FAST_IO;
	
	string chars;
	forsn(i,'a','z'+1) chars.pb(i);
	forsn(i,'A','Z'+1) chars.pb(i);
	forsn(i,'0','9'+1) chars.pb(i);
	
	int len = -1, aux;
	string test;
	forsn(k,1,21) {
		test = string(k,'a');
		if ((aux = query(test)) > 5) {
			len = k; break;
		}
	}
		
	int win = getlet(aux), curind = 0;
	while (win <= len) {
		test[win-1] = chars[++curind];
		
		aux = query(test);
		if (getlet(aux) != win) {
			curind = 0;
		}
		win = getlet(aux);
	}
   
	return 0;
}
