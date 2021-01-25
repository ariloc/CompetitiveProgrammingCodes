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
        int l,b,n; cin >> l >> b >> n;
        string s; cin >> s;

        bool posib = true;
        forsn(j,n-l,n) if (s[j] == '0') {posib = false; break;} // solo si todos libres al final
        if (!posib) {cout << "IMPOSSIBLE\n"; continue;}

        ll mov = 0;
        int free = l, izq = 0, der = l-1, bub = b-1;

        while (der < n-1) {
            int nd = der;
            forsn(j,der+1,bub+1) if (s[j] == '1') free++, nd = j;
            if (nd == der) {posib = false; break;} // si no puedo mover ninguno, no se puede
            int tmpBub = bub;
            while (tmpBub < n-1 && izq < nd && (free > l || (free == l && s[izq] == '0'))) free -= (s[izq++] == '1'), mov++, tmpBub++; // suma movimiento de burbujas
            mov += l; // todas las piernas se mueven
            bub = tmpBub, der = nd;
        }

        if (!posib) {cout << "IMPOSSIBLE\n"; continue;}
        cout << mov << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
