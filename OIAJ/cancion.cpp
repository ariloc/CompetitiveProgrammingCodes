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

vector<string> forEach;
multiset<string> dpR;

int main() {
    FAST_IO;

    string s; cin >> s;

    int n = s.size();
    forn(j,n) forEach.pb("");
    forEach.pb(""); // dummy

    int rta = -1, ap = -1;
    forsn(k,1,n/2) { // suponete que el largo es k, y es hasta la mitad porque tiene que haber dos
        forsn(i,k-1,n) forEach[i-k+1].pb(s[i]); // en cada paso en O(n) formo las strings
        forEach.pop_back(); // por el aumento, el último se va

        dpR.clear(); // por las dudas
        forsn(j,k,forEach.size()) dpR.insert(forEach[j]);

        forn(j,n-2*k+1) { // porque si tiene que haber dos, no tiene sentido
            if (dpR.count(forEach[j])) {ap = j, rta = k; break;} // porque tengo el de prim aparic, entonces me voy
            dpR.erase(dpR.find(forEach[j+k]));
        }
    }

    if (rta == -1) cout << "NO HAY";
    else cout << rta << ' ' << ap+1;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
