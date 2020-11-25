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

int main() {
    string s; cin >> s;
    int games[2] = {0,0}, pts[2] = {0,0};
    bool serve = 0, win = 0;
    forn(i,s.size()) {
        if (s[i] == 'S') pts[serve]++;
        else if (s[i] == 'R') {serve = !serve; pts[serve]++;}
        else {
            if (win) printf("%d%s - %d%s\n",games[0],(games[0] > games[1] ? " (winner)" : ""),games[1],(games[1] > games[0] ? " (winner)" : ""));
            else printf("%d (%d%s) - %d (%d%s)\n",games[0],pts[0],(!serve ? "*" : ""),games[1],pts[1],(serve ? "*" : ""));
        }

        if (pts[0] >= 5 && pts[0]-pts[1] >= 2 || pts[0] >= 10) {pts[0] = pts[1] = 0; games[0]++;}
        else if (pts[1] >= 5 && pts[1]-pts[0] >= 2 || pts[1] >= 10) {pts[0] = pts[1] = 0; games[1]++;}

        if (games[0] > 1 || games[1] > 1) win = true;
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
