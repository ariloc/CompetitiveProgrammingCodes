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

const int MOD = 998244353;
const int MAXN = 3e5+2;

int fact[MAXN],arr[MAXN],pref[MAXN];

void precompFact() {
    fact[0] = 1;
    forsn(i,1,MAXN) fact[i] = (fact[i-1]*(ll)i)%MOD;
}

int binExp (int a, int k) {
    int r = 1;
    while (k) {
        if (k&1) r = (r*(ll)a)%MOD;
        a = (a*(ll)a)%MOD; k >>= 1;
    }
    return r;
}

int nCr (int n, int r) {
    if (r > n) return 0;
    return ((ll)fact[n]*binExp(((ll)fact[r]*fact[n-r])%MOD,MOD-2))%MOD;
}

int main() {
    FAST_IO;

    precompFact();

    int n; cin >> n;
    forn(j,2*n) cin >> arr[j];

    sort(arr,arr+2*n);

    int s = 0;
    forn(j,n) s = ((ll)s + abs(arr[j]-arr[2*n-1-j]))%MOD;

    cout << ((ll)nCr(2*n,n)*s)%MOD;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
