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

    forn(i,t) {
        int n; cin >> n;
        string a,b; cin >> a >> b;

        vi moves;

        // polarizamos 0s y 1s
        bool actC = (a[0] == '1');
        forn (j,n) if (a[j]-'0' != actC) {moves.pb(j); actC = !actC;}
        // quedarán todos del mismo bit, ahora solo me quedan n operaciones

        if (actC) moves.pb(n);
        bool invert = false;
        dforn (j,n) {
            if (!invert)
                if (b[j] == '0') continue;
                else {moves.pb(j+1); invert = !invert;}
            else
                if (b[j] != '0') continue;
                else {moves.pb(j+1); invert = !invert;}
        }

        cout << moves.size() << ' ';
        for (auto &o : moves) cout << o << ' ';
        cout << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!