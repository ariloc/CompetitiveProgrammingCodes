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
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXD = 64;

int main() {
    FAST_IO;

    ull a,b; cin >> a >> b;
    ll x = 0, y = 0;
    forn(i,MAXD) if (b&(1ULL<<i)) y |= (1ULL<<i); // si es un bit prendido, tiene que ir el positivo a Y, ya que minimizo X (pues XOR, en uno es 0 y en el otro 1)

    a -= y; // me fijo cuánto me queda para mi objetivo
    bool posib = true;
    forn(i,MAXD) if (a&(1ULL<<i)) { // si hay un bit prendido de a, para sumar el bit anterior en b tiene que estar apagado, así no lo puse y lo pongo en X e Y, y al sumar dos potencias previas me da la mía
        if (!i || (b&(1ULL<<(i-1)))) {posib = false; break;} // si no se cumple, imposible
        x |= (1ULL<<(i-1)), y |= (1ULL<<(i-1));
    }

    if (posib) cout << x << ' ' << y;
    else cout << -1;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
