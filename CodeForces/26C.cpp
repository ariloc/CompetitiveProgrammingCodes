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

const int MAXN = 105;
const int MAXA = 26;
const int X[] = {0,1,0,-1};
const int Y[] = {1,0,-1,0};

char rta[MAXN][MAXN];

void chooseNextLet (vector<ii> touch, char &let) {
    set<char> avoid;
    for (auto &i : touch) {
        forn(k,4) {
            int tY = i.fst+Y[k], tX = i.snd+X[k];
            if (tY < 0 || tX < 0 || !rta[tY][tX]) continue;
            avoid.insert(rta[tY][tX]);
        }
    }
    forn(i,MAXA) if (!avoid.count(i+'a')) {let = i+'a'; return;}
}

int main() {
    FAST_IO;

    int n,m,a,b,c; cin >> n >> m >> a >> b >> c;
    if ((n*m)&1) return cout << "IMPOSSIBLE", 0;

    // tratamos casos impares
    bool impN = false, impM = false;
    if (n&1) {
        bool me = 0;
        for (int j = 0; j < m; j += 2) rta[n-1][j] = rta[n-1][j+1] = me+'a', me = !me;
        if (a < m/2) return cout << "IMPOSSIBLE", 0;
        n--, a -= m/2, impN = true;
    }
    if (m&1) {
        bool me = 0;
        for (int j = 0; j < n; j += 2) rta[j][m-1] = rta[j+1][m-1] = me+'a', me = !me;
        if (b < n/2) return cout << "IMPOSSIBLE", 0;
        m--, b -= n/2, impM = true;
    }

    int cA = a/2, cB = b/2;
    // con todo par ya es más sencillo
    char let = 0;
    for (int i = 0; i < n; i += 2)
        for (int j = 0; j < m; j += 2) {
            bool done = false;
            if (c) {
                done = true, c--;
                chooseNextLet({{i,j},{i+1,j},{i,j+1},{i+1,j+1}},let);
                rta[i][j] = rta[i+1][j] = rta[i][j+1] = rta[i+1][j+1] = let;
            }
            else if (cA) {
                done = true, cA--;
                chooseNextLet({{i,j},{i,j+1}},let);
                rta[i][j] = rta[i][j+1] = let;
                chooseNextLet({{i+1,j},{i+1,j+1}},let);
                rta[i+1][j] = rta[i+1][j+1] = let;
            }
            else if (cB) {
                done = true, cB--;
                chooseNextLet({{i,j},{i+1,j}},let);
                rta[i][j] = rta[i+1][j] = let;
                chooseNextLet({{i,j+1},{i+1,j+1}},let);
                rta[i][j+1] = rta[i+1][j+1] = let;
            }

            if (!done) return cout << "IMPOSSIBLE", 0;
        }

    //cerr << impN << ' ' << impM << endl;
    forn(i,n+impN) {forn(j,m+impM) cout << rta[i][j]; cout << '\n';}

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
