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

    string s; cin >> s; s.pb('a'); // dummy
    string aux; bool let = false;
    ld price = 0;
    forn(j,s.size()) {
        if (s[j] >= 'a' && s[j] <= 'z') {
            if (!let && !aux.empty()) { // procesamos precios
                int cnt = 0; bool hascents = 0, mark = false;
                dforn(k,aux.size()) if (aux[k] != '.') cnt++; else {mark = true; break;}
                if (cnt == 2 && mark) hascents = 1;

                int acc = 0;
                forn(k,aux.size()) if (aux[k] != '.') acc = acc*10 + aux[k]-'0';
                price += (acc)/(ld)(hascents ? 100 : 1);

                aux.clear();
            }
            aux.pb(s[j]); let = true;
        }
        else {
            if (let) aux.clear(), let = false; // ignoramos nombres
            aux.pb(s[j]);
        }
    }

    bool decPosic = 0;
    if ((ll(price*100LL))%100LL) decPosic = true;

    stringstream ss;
    ss << setprecision(decPosic*2) << fixed << price;
    string rta;
    ss >> rta;

    int cnt = 0;
    dforn(j,rta.size()-decPosic*3) {
        if (cnt >= 3) cnt = 0, rta.insert(j+1,".");
        cnt++;
    }

    cout << rta;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
