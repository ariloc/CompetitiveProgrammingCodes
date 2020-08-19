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

const int INF = 1e9+2;

int main() {
    FAST_IO;

    int t; cin >> t;

    forn (i,t) {
        string s; cin >> s;

        vector<ii> dpF(s.size()), dpB(s.size());

        int z = 0, o = 0;
        forn (j,s.size()) { // dp accum
            if (s[j] == '0') z++;
            else o++;
            dpF[j] = {z,o};
        }
        z = o = 0;
        dforn (j,s.size()) { // dp accum
            if (s[j] == '0') z++;
            else o++;
            dpB[j] = {z,o};
        }

        int rta = INF;
        forn (j,s.size()) {
            rta = min(rta,(j-1 < 0 ? 0 : dpF[j-1].fst)+dpB[j].snd);
            rta = min(rta,(j-1 < 0 ? 0 : dpF[j-1].snd)+dpB[j].fst);
        }

        cout << rta << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!