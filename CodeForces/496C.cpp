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

const int MAXN = 102;

char mat[MAXN][MAXN];
bool sorted[MAXN];

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,n) forn(j,m) cin >> mat[i][j];
    int cnt = 0;
    forn(j,m) {
        bool posib = true;
        vi gotSorted;
        forsn(i,1,n) {
            if (mat[i][j] > mat[i-1][j]) gotSorted.pb(i);
            if (mat[i][j] < mat[i-1][j] && !sorted[i]) {posib = false; break;}
        }
        if (posib) for (auto &k : gotSorted) sorted[k] = true; // una vez que quedó ordenado en una posic lex menor, después no me importa
        else cnt++;
    }

    cout << cnt;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
