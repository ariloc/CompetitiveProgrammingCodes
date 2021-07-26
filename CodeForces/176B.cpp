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

const int MOD = 1e9+7;
const int MAXK = 1e5+5;
const int MAXS = 1005;

int dp[2][MAXS]; // estando en la k-ésima operación, con un j-ésimo shift neto

int main() {
    FAST_IO;

    string st,nd; cin >> st >> nd;
    int k; cin >> k;
    int n = (int)st.size(); // los size son iguales

    // es básicamente otra forma de decir "se puede sacar shifteando cíclicamente"
    vi posib;
    forn(i,n) {
        if (st == nd) posib.pb(i);
        rotate(st.begin(),st.begin()+1,st.end()); // 1 shifteo left
    }

    dp[0][0] = 1; // parto con 0 shift
    forsn(i,1,k+1) {
        int sum = 0;
        forn(j,n) sum = (sum + dp[1^(i&1)][j])%MOD;
        forn(j,n) dp[i&1][j] = (sum - dp[1^(i&1)][j] + MOD)%MOD;
    }

    int rta = 0;
    for (auto &i : posib) rta = (rta + dp[k&1][i])%MOD; // sólo vale si llego con estos shifts

    cout << rta;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!