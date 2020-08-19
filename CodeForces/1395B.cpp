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

const int MAXN = 105;

bool done[MAXN][MAXN];

int main() {
    FAST_IO;

    int n,m,x,y; cin >> n >> m >> y >> x; x--; y--;

    forn (j,n) {
        forn (i,m) {
            cout << y+1 << ' ' << x+1 << '\n';
            if (i+1 != m) x = (x+1)%m;
        }
        y = (y+1)%n;
    }

    /*
    queue<ii> Q; Q.push({y,x});
    int cnt = 0;
    while (not Q.empty()) {
        auto e = Q.front(); Q.pop(); cnt++;
        done[e.snd][e.fst] = true;
        cout << e.snd+1 << ' ' << e.fst+1 << '\n';

        if (cnt >= n*m) break;

        if (e.fst+1 >= m) if(!done[e.snd][0]) Q.push({0,e.snd}); else goto TWO;
        else if (done[e.snd][e.fst+1]) {TWO: Q.push({e.fst,(e.snd+1)%n});}
        else Q.push({e.fst+1,e.snd});
    }*/

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!