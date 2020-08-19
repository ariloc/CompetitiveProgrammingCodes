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
        string s; cin >> s;
        vi mark(s.size());
        vi pares;

        forsn (j,2,s.size()) {
            if (s[j] == 'e' and s[j-1] == 'n' and s[j-2] == 'o')
                {mark[j]++; mark[j-2]++;}
            if (s[j] == 'o' and s[j-1] == 'w' and s[j-2] == 't')
                {mark[j]++; mark[j-2]++;}
        }

        forn (j,s.size()) // I always win with intersection
            if (mark[j] == 2)
                {pares.pb(j+1); mark[j] = mark[j-2] = mark[j+2] = 0;}

        int bal = 0;
        forn (j,s.size())
            if (mark[j])
                if (bal >= 0) {pares.pb(j+2); bal--;}
                else bal++;

        cout << pares.size() << '\n';
        for (auto &j : pares) cout << j << ' ';
        cout << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!