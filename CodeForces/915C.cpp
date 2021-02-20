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

const int MAXD = 10;

map<char,int> dig;
string a,b;

void subtractOne (map<char,int> &x, char y) {
    if (!(--x[y])) x.erase(y);
}

int main() {
    FAST_IO;

    cin >> a >> b;

    for (auto &i : a) dig[i]++;

    // log2(a) < log2(b) porque la rta existe, la rta es del mismo largo que a y no puede tener leading zeroes
    bool eq = (b.size() == a.size());

    // caso igual igualito
    map<char,int> tmp_copy = dig;
    if (eq) {
        bool posib = true;
        forn(i,b.size())
            if (!tmp_copy.count(b[i])) {posib = false; break;}
            else subtractOne(tmp_copy,b[i]);
        if (posib) return cout << b, 0;
    }

    // caso dist tamaño
    tmp_copy = dig;
    if (!eq) {
        while (!tmp_copy.empty())
            cout << (*tmp_copy.rbegin()).fst, subtractOne(tmp_copy,(*tmp_copy.rbegin()).fst);
        return 0;
    }

    // caso igual tamaño, pero no igualitos
    dforn(i,a.size()) { // bloqueando i dígitos
        map<char,int> tmp1 = dig;
        string tmpL;
        bool posib = true;
        forn(j,i) {
            if (!tmp1.count(b[j])) {posib = false; break;}
            else subtractOne(tmp1,b[j]), tmpL.pb(b[j]);
        }
        if (!posib) continue; // si siquiera puedo bloquear los dígitos
        dforn(j,MAXD) { // usando un dígito j en el siguiente (j < b[pos] y j en los que quedan de a)
            if (b[i] <= j+'0' || !tmp1.count(j+'0') || (!i && !j)) continue; // si no bloqueo ninguno, no puedo poner un cero
            // si llegué acá, escupo la rta
            cout << tmpL << (char)(j+'0'), subtractOne(tmp1,j+'0');
            while (!tmp1.empty()) cout << (*tmp1.rbegin()).fst, subtractOne(tmp1,(*tmp1.rbegin()).fst);
            return 0;
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
