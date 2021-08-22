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

const int MAXN = 1005;

struct circle {
    int x,y; ll r;
};

ii control[MAXN];
circle circunf[MAXN];

int main() {
    FAST_IO;

    int n,m,k; cin >> n >> m >> k;

    forn (i,n) cin >> control[i].fst >> control[i].snd;
    forn (i,m) cin >> circunf[i].r >> circunf[i].x >> circunf[i].y;
    forn (i,k) {
        int a,b; cin >> a >> b; a--; b--;

        int cnt = 0;
        forn (j,m) {
            bool containA = false, containB = false;
            ll x = abs(control[a].fst-circunf[j].x), y = abs(control[a].snd-circunf[j].y);
            //cerr << x << ' ' << y << ' ' << circunf[j].r << "!!" << endl;
            if ((x*x + y*y) < (circunf[j].r*circunf[j].r)) containA = true;

            x = abs(control[b].fst-circunf[j].x), y = abs(control[b].snd-circunf[j].y);
            if ((x*x + y*y) < (circunf[j].r*circunf[j].r)) containB = true;

            if (containA^containB) cnt++;
        }

        cout << cnt << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!