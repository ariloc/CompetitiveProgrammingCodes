#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
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
typedef long double ld;
typedef pair<int,int> ii;

const ll INF = 9e18;

ll calcSup (ll r, ll c) {
    return 40LL*r + 88LL*c + 440LL*r*c + 8LL;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        ll n; cin >> n;

        ll a = -1, b = -1, sup = INF;
        for (ll j = 1; j*j <= n; j++) {
            ll r = (n+5*j-1)/(5*j), c = j;
            ll calc = calcSup(r,c);
            if (calcSup(c,r) < calc) {swap(r,c); calc = calcSup(r,c);}
            if (calc < sup) sup = calc, a = 4 + 2*(r-1) + 8*r, b = 8 + 4*(c-1) + 40*c;
        }

        if (a < b) swap(a,b);
        cout << a << " X " << b << " = " << sup << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
