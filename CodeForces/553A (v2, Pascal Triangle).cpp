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
const int MOD = 1e9+7;

int C[MAXN][MAXN];

int main() {
    FAST_IO;

    C[0][0] = 1;
    forsn(n,1,MAXN) {
        C[n][0] = C[n][n] = 1;
        forsn(k,1,n) 
            C[n][k] = (C[n-1][k-1] + C[n-1][k])%MOD;
    }

    int n; cin >> n;
    int rta = 1, acc = 0;
    forn(i,n) {
        int x; cin >> x;
        rta = (rta * (ll)C[acc+x-1][x-1])%MOD;
        acc += x;
    }

    cout << rta;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!