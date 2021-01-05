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

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int d,k; cin >> d >> k;
        ll rel = ((ll)d*d)/((ll)k*k); // floor a propósito
        int od = 0, ev = 0;
        for (ll x = 0; x*x <= rel; x++) { // tendré como mucho 1e5 pares peor caso (si d² = 1e5 y k = 1, rel = 1e10 -> como x va hasta sqrt(1e10), 1e5 pares), y con t <= 100 va justo 1e8
            ll y = sqrt(rel-(x*x)); // el y maximal tal que (x² + y²) <= floor(d²/k²), el floor va porque siempre la suma de cuadrados es entero
            if ((x*x + y*y) <= rel && abs(x-y) <= 1) { // check por las dudas
                if ((x+y)&1) od++;
                else ev++;
            }
        }
        cout << (od > ev ? "Ashish" : "Utkarsh") << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
