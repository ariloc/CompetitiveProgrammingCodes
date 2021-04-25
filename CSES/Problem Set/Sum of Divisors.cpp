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

const int MOD = 1e9+7;

ll gauss (ll x) {
    return (((x * (ll)(x+1))%MOD) * (ll)((MOD+1)/2))%MOD;
}

int main() {
    FAST_IO;

    ll x; cin >> x;
    ll rta = 0;
    for (ll i = 1; i*i <= x; i++) {
        ll me = x/i;
        rta = (rta+(((ll)me*i)%MOD))%MOD;
        ll prox = x/(i+1);
        if (prox >= i) rta = (rta + ((((((ll)gauss(me%MOD)-gauss(prox%MOD)))%MOD) * (ll)i)%MOD))%MOD;
    }

    cout << (rta+MOD)%MOD;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
