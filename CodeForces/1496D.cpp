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

const int MAXN = 1e5+5;

int arr[MAXN];
vector<ii> pendientesR,pendientesL;

int main() {
    FAST_IO;

    int n; cin >> n;

    forn(i,n) cin >> arr[i];

    int act = 0;
    forsn(i,1,n) {
        if (arr[i] < arr[i-1]) {
            pendientesL.pb({i-act,i-1});
            act = i;
        }
    }
    pendientesL.pb({n-act,n-1});

    act = n-1;
    dforn(i,n-1) 
        if (arr[i] < arr[i+1])
            pendientesR.pb({act-i,i+1}), act = i;
    pendientesR.pb({act+1,0});

    sort(all(pendientesL));
    sort(all(pendientesR));

    // Objetivo: Se puede 1 si tengo uno con dos ramas pares iguales, y es el único mayor sin pendiente que lo iguale
    if (
        !(pendientesL.back().fst&1) || // si es par, incluye a la punta, entonces la rama del mayor es impar y no se puede
        (int)pendientesL.size() == 1 || // todo es una gran pendiente, no hay ramas y no se puede
        pendientesL.back().fst == pendientesL[pendientesL.size()-2].fst // hay dos pendientes mayores idénticas, entonces el otro me puede ganar
    ) cout << 0;
    else {
        // si es una sóla pendiente más grande y única, impar con el extremo (sin sería rama par), verifico si está el simétrico, y si también es único
        if (!(pendientesR.back().fst&1) ||
            (int)pendientesR.size() == 1 ||
            pendientesR.back().fst == pendientesR[pendientesR.size()-2].fst) cout << 0; // mismas condiciones que otra pendiente
        else if (pendientesR.back() != pendientesL.back()) cout << 0; // si tienen distinto final o largo, tampoco va
        else cout << 1;
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!