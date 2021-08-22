#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

map<char,int> let;

int main() {
    FAST_IO;

    string s; cin >> s;

    forn(i,s.size()) {
        let[s[i]]++;
    }

    if (let.size() <= 1) cout << 0;
    else {
        bool palindrome = true;
        forn(i,s.size()/2) if (s[i] != s[s.size()-i-1]) {palindrome = false; continue;}
        if (palindrome) cout << s.size()-1;
        else cout << s.size();
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!