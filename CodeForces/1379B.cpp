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

const ll INF = 1e18+5;

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        ll l,r,m; cin >> l >> r >> m;

        ll a,b,c;
        forsn (j,l,r+1) { // consigo a
            ll rest = m % j; // para sacar
            ll otR = ((ll((m+j-1)/j))*j) - m; // para poner

            if (m-rest < 1) rest = INF;

            if (r-l+1 >= rest and l+rest <= r) {a = j; b = l+rest; c = l; break;}
            if (r-l+1 >= otR and l+otR <= r) {a = j; b = l; c = l+otR; break;}
        }

        cout << a << ' ' << b << ' ' << c << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!