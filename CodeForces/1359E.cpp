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

const int MOD = 998244353;
const int MAXN = 5e5+2;

int fact[MAXN], inv[MAXN], factInv[MAXN];

void precomp() {
    fact[0] = 1;
    forsn(i,1,MAXN) fact[i] = (fact[i-1]*(ll)i)%MOD;

    inv[1] = 1;
    forsn(i,2,MAXN) inv[i] = MOD - ((MOD/(ll)i)*(ll)inv[MOD%i])%MOD;

    factInv[0] = 1;
    forsn(i,1,MAXN) factInv[i] = (factInv[i-1]*(ll)inv[i])%MOD;
}

int nCr (int n, int r) {
    if (r > n) return 0;
    return ((ll)((fact[n]*(ll)factInv[r])%MOD)*factInv[n-r])%MOD;
}

int main() {
    FAST_IO;

    precomp();

    int n,k; cin >> n >> k;

    int rta = 0;
    forsn(i,1,n+1) {
        int cantDiv = n/i;
        rta = (rta + nCr(cantDiv-1,k-1))%MOD;
    }

    cout << rta;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
