#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 5000;

bool posib[MAXN][MAXN];
int dp1[MAXN][MAXN],dp2[MAXN][MAXN];

int main() {
    FAST_IO;

    string s; cin >> s;
    int n = s.size();

    // odd
    forn(i,n) {
        int l,r; l = r = i;
        while (l >= 0 && r < n && s[l] == s[r]) posib[l--][r++] = true;
    }

    // even
    forn(i,n-1) {
        int l = i, r = i+1;
        while (l >= 0 && r < n && s[l] == s[r]) posib[l--][r++] = true;
    }

    forn(i,n) {
        int acc = 0;
        forsn(j,i,n) acc += (posib[i][j]), dp1[i][j] = acc; // todos los que empiezan en i y terminan en posic <= j
    }

    dforn(j,n) {
        int acc = 0;
        dforn(i,j+1) acc += dp1[i][j], dp2[i][j] = acc;
    }

    int q; cin >> q;
    forn(i,q) {
        int l,r; cin >> l >> r; l--, r--;
        cout << dp2[l][r] << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
