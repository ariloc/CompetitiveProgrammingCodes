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

const int MAXN = 1005;

ld dp[MAXN][MAXN];

int main() {
    FAST_IO;

    int w,b; cin >> w >> b;

    ld prob = 0;
    dp[w][b] = 1;
    dforn(i,w+1) dforn(j,b+1) {
        if (i-1 >= 0) {
            int turn = ((w+b-i-j)%3); ld calc = dp[i][j]*(i/(ld)(i+j));
            if (turn == 2) dp[i-1][j] += calc; // solo sigo si fue uno que saltó
            if (!turn) prob += calc; // si agarra la princesa
        }
        if (j-1 >= 0) dp[i][j-1] += dp[i][j]*(j/(ld)(i+j));
    }

    cout << fixed << setprecision(15) << prob;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
