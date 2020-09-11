#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const int MAXN = 1e8+5;
const int MAXD = 10;

ll rta[MAXD][MAXD];
int machete[MAXD][MAXD][MAXD][MAXD]; // a->b con (c,d)
bool invalid[MAXD][MAXD];

int main() {
    FAST_IO;

    string s; cin >> s;

    forn(i,MAXD) forn(j,MAXD) forn(k,MAXD) forn(l,MAXD) { // i->j con (k,l)
        vector<bool> done(10,0);
        queue<ii> Q; // end digit;
        Q.push({i,0});

        while (not Q.empty()) {
            auto e = Q.front(); Q.pop();

            if (e.snd and e.fst == j) {machete[i][j][k][l] = (e.snd-1); break;}

            int c1 = (e.fst+k)%10, c2 = (e.fst+l)%10;
            if (!done[c1]) {Q.push({c1,e.snd+1}); done[c1] = true;}
            if (!done[c2]) {Q.push({c2,e.snd+1}); done[c2] = true;}
        }

        if (!done[j]) machete[i][j][k][l] = -1;
    }

    forn(i,s.size()-1) {
        forn(j,MAXD) forn(k,MAXD) {
            if (rta[j][k] == -1) continue;
            if (machete[s[i]-'0'][s[i+1]-'0'][j][k] == -1) rta[j][k] = -1;
            else rta[j][k] += machete[s[i]-'0'][s[i+1]-'0'][j][k];
        }
    }

    forn(i,MAXD) {forn(j,MAXD) cout << rta[i][j] << ' '; cout << '\n';}

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
