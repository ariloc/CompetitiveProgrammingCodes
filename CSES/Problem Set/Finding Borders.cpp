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

const int MAXN = 1e6+5;

int border[MAXN];

void get_bordes (string s) {
    int n = s.size();
    forsn (i,1,n) {
        int j = border[i-1];
        while (j > 0 and s[i] != s[j])
            j = border[j-1];
        if (s[i] == s[j]) j++;
        border[i] = j;
    }
}

int main() {
    FAST_IO;

    string s; cin >> s;
    get_bordes(s);

    int ind = border[(int)s.size()-1];
    vi show; if (ind) show.pb(ind);
    while (ind and border[ind-1]) {
        ind = border[ind-1];
        show.pb(ind);
    }

    dforn(i,show.size()) cout << show[i] << ' ';

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
