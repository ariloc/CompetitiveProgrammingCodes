#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(ll i = ll(s); i < ll(n); i++)
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

const int MAXN = 2e6+5;

int KMP[MAXN];

int KMPcompute(string s) { // KMP get
    forn (i,s.size()) KMP[i] = 0;
    int j = 0;
    forsn (i,1,s.size()) {
        j = KMP[i-1];
        while (j > 0 and s[i] != s[j]) j = KMP[j-1];
        if (s[i] == s[j]) j++;
        KMP[i] = j;
    }
    return j; // return for the last one, as I want respectively the suffix or prefix, not a substring
}

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        string s; cin >> s;

        int ind = 0;
        forn (j,s.size()/2+1) // find how much they stay equal
            if (s[j] != s[(int)s.size()-j-1]) {ind = j; break;}
        ind = max(0,ind);

        if (ind == s.size()/2) {cout << s << '\n'; continue;}

        string prim = s.substr(0,ind);
        string aux = prim; reverse(all(aux));

        s = s.substr(ind,s.size()-2*ind); // in the middle portion
        string sR = s; reverse(all(sR));
        int a = KMPcompute(s + '$' + sR); // finding palindromes is matching string with its reverse
        int b = KMPcompute(sR + '$' + s);

        cout << prim << (a > b ? s.substr(0,a) : s.substr(s.size()-b,b)) << aux << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!