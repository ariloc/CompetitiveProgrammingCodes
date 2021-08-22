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

int main() {
    FAST_IO;

    int m; cin >> m;
    if (m == 1) {cout << 1; return 0;}

    if (!(m%3)) {cout << -1; return 0;}

    int k = 0;
    while (((9*k) % m) != 1) k++;

    int rest = m -((9*k) % m);
    string s; forn (i,k) s.pb('9');

    int x = min(8,rest); s.pb(x+'0'); rest -= x;
    while (rest) {
        x = min(9,rest); rest -= x; s.pb(x+'0');
    }

    reverse(all(s)); cout << s;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!