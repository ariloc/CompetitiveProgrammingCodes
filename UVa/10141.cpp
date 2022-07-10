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

struct propTyp {
    ld comp, price;
    int ind;
    string name;

    bool operator< (const propTyp &o) const {
        if (comp == o.comp) {
            if (price == o.price) return ind < o.ind;
            return price < o.price;
        }
        return comp > o.comp;
    }
};

vector<propTyp> prop;

int main() {
    FAST_IO;

    int n,p,t = 0; bool prv = false;
    while (cin >> n >> p) {
        if (!n && !p) break;
        if (prv) cout << '\n';

        prop.clear();

        string aux;
        getline(cin,aux);
        forn(i,n) getline(cin,aux); // solo me importa la cantidad
        forn(i,p) {
            string s; getline(cin,s);
            ld pr; int req; cin >> pr >> req;
            getline(cin,aux);
            forn(j,req) getline(cin,aux); // nuevamente, como son todos de la lista y no duplican, solo me importa la cantidad
            prop.pb({req/(ld)n,pr,i,s});
        }

        sort(all(prop));

        cout << "RFP #" << ++t << '\n' << prop[0].name << "\n";
        prv = true;
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
