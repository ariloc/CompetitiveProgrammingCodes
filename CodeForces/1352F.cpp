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

    int t; cin >> t;

    forn (i,t) {
        int a,b,c; cin >> c >> b >> a;
        bool prev = 0, inserted = 0;
        if (a) cout << 1;
        forn (j,a) cout << 1;
        if (!a and b) cout << 1;
        forn (j,b) {
            if (j == b-1 and prev) {
                inserted  = true;
                forn (k,c) cout << 0;
            }
            cout << prev; prev = !prev;
        }
        if (!inserted) {
            if (c and !b) cout << 0;
            forn(j,c) cout << 0;
        }
        cout << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!