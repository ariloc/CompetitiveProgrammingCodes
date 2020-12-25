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

const int MAXN = 1005;
const int MOD = 1e9+7;

short int arr[MAXN]; // 0 nothing, 1 is <=, 2 is >
int fact[MAXN];

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

void precompFact() {
    fact[0] = 1;
    forsn(i,1,MAXN) fact[i] = (fact[i-1]*(ll)i)%MOD;
}

int main() {
    FAST_IO;
    precompFact();

    int n,x,pos; cin >> n >> x >> pos;

    // pseudoBinary
    int l = 0, r = n;
    while (l < r) {
        int m = (l+r)/2;
        if (m <= pos) {l = m+1; arr[m] = 1;}
        else {r = m; arr[m] = 2;}
    }

    int cant[3] = {0,0,0};
    forn(j,n) if (j == pos) continue; else cant[arr[j]]++;

    cout << ((ll)(((ll)( ((ll)fact[cant[0]] * nCr(x-1,cant[1]) )%MOD) *
            nCr(n-x,cant[2]))%MOD) * (((ll)fact[cant[1]] * fact[cant[2]])%MOD))%MOD;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
