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
typedef unsigned long long ull;

ll sumMod (ull a, ull b, ull MOD) { // (a+b) % MOD  |||  admite ll, devuelve ll, pero opera con ull
    ull aux = a+b;
    if (aux < a || aux >= MOD) aux -= MOD;
    return aux;
}

ll mulMod (ll a, ll b, ll MOD) { // a*b % MOD
    if (b <= 1) return b ? a : 0;
    ll half = mulMod(a, b >> 1, MOD);
    half = sumMod(half, half, MOD);
    if (b&1) half = sumMod(half, a, MOD);
    return half;
}

ll binMod (ll a, ll k, ll MOD) { // a^k % MOD
    ll r = 1; a %= MOD;
    while (k) {
        if (k&1) r = mulMod(r,a,MOD);
        a = mulMod(a,a,MOD); k >>= 1;
    }
    return r;
}

bool is_composite (ll n, ll a, ll d, int s) {
    ll aux = binMod(a,d,n); // a^d % n
    if (aux == 1 || aux == n-1) return false; // a^d \equiv +-1 (mod n)  |||  [caso -1 en MOD es n-1]
    forsn(r,1,s) { // 0 < r < s
        aux = mulMod(aux,aux,n); // a^d -> a^(2*d) -> a^(4*d) -> ... -> a^(2^r * d)
        if (aux == n-1) return false; // a^(2^r * d) \equiv -1 (mod n)
    }
    return true;
}

// a^(p-1) \equiv 1 (mod n) ->
// a^(2^s * d) - 1 \equiv 0 (mod n)
// [si p primo, p es impar -> (p-1) es par -> se puede representar (p-1) = 2^s * d]
bool miller_rabin (ll n) { 
    if (n < 2) return false;

    int s = 0;
    ll d = n-1;
    while (!(d&1)) d >>= 1, s++;

    for (int a : {2,3,5,7,11,13,17,19,23,29,31,37}) { // hasta 64-bit, chequeado funciona con estas bases
        if (n == a) return true;
        if (is_composite(n,a,d,s))
            return false;
    }
    
    return true;
}

int main() {
    int t; scanf("%d",&t);
    forn(o,t) {
        ll x; scanf("%lld",&x);
        printf("%s\n",miller_rabin(x) ? "YES" : "NO");
    }

    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!