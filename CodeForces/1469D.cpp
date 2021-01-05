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
        int n; cin >> n;

        // agarro las raíces, y sus raíces, y así hasta el 2
        set<int> roots;
        vi lst;
        int aux = sqrt(n)+1; lst.pb(n);
        while (aux >= 2) {
            roots.insert(aux); lst.pb(aux);
            if (aux == 2) break;
            aux = sqrt(aux)+1;
        }

        vector<ii> rta;
        forsn(j,3,n) if (!roots.count(j)) rta.pb({j,n}); // a 1 todos menos las raíces y el 2

        forn(j,lst.size()-1) {rta.pb({lst[j],lst[j+1]}); rta.pb({lst[j],lst[j+1]});} // cancelo raíces

        cout << rta.size() << '\n';
        for (auto &j : rta) cout << j.fst << ' ' << j.snd << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
