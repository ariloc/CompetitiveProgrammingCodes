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

int main() {
    FAST_IO;

    int a,b,k; cin >> a >> b >> k;

    if (!k) {cout << "Yes\n"; string aux; aux = string(b,'1')+string(a,'0'); cout << aux << '\n' << aux; return 0;} // caso se puede siempre, k = 0

    string x = "1", y = "1"; b--; // los 1s oblig al principio

    if (!a || b <= 0) return cout << "No", 0; // no se puede porque si no puedo transformar 1, tienen que ser iguales y como k != 0, perdí

    x.pb('1'), y.pb('0'), k--, a--, b--; // primer par, y con su contraparte ya me hacen uno
    if (a + b < k) return cout << "No", 0; // si siquiera combinando lo que me queda puedo zafar
    int top = min(k,b); k -= top, b -= top;
    forn(i,top) x.pb('1'), y.pb('1');
    top = min(k,a); k -= top, a -= top;
    forn(i,top) x.pb('0'), y.pb('0');
    x.pb('0'),y.pb('1'); // la contraparte que cierra/empieza

    forn(i,b) x.pb('1'), y.pb('1');
    forn(i,a) x.pb('0'), y.pb('0');

    cout << "Yes\n" << x << '\n' << y;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
