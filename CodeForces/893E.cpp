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

const int MAXN = 2e6+5;
const int MOD = 1e9+7;

map<int,int> F;
int fact[MAXN],inv[MAXN],factInv[MAXN],pot2[MAXN];

void factors (int x) {
    for (int i = 2; i*i <= x; i++)
        while (!(x%i)) F[i]++, x /= i;
    if (x > 1) F[x]++;
}

void precomp() {
    inv[1] = 1;
    forsn(i,2,MAXN) inv[i] = MOD - ((MOD/(ll)i)*(ll)inv[MOD%i])%MOD;

    fact[0] = 1;
    forsn(i,1,MAXN) fact[i] = (fact[i-1]*(ll)i)%MOD;

    factInv[0] = 1;
    forsn(i,1,MAXN) factInv[i] = (factInv[i-1]*(ll)inv[i])%MOD;

    pot2[0] = 1;
    forsn(i,1,MAXN) pot2[i] = (pot2[i-1]<<1)%MOD;
}

int nCr (int n, int r) {
    if (r > n) return 0;
    return ((ll)(((ll)fact[n]*factInv[r])%MOD)*factInv[n-r])%MOD;
}

int main() {
    FAST_IO;

    precomp();

    int q; cin >> q;
    forn(i,q) {
        int x,y; cin >> x >> y;

        F.clear();
        factors(x);

        int n = 0;
        for (auto &j : F) n += j.snd;
        int rta = 1;

        for (auto &j : F)
            rta = (rta * (ll)nCr(y+j.snd-1,j.snd))%MOD;

        cout << ((ll)rta*pot2[y-1])%MOD << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
