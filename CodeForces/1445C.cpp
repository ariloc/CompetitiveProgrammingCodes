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

const ll INF = 9e18;

map<int,int> F;

void fact (ll x) {
    for (ll i = 2; i*i <= x; i++)
        while (!(x%i)) F[i]++, x /= i;
    if (x > 1) F[x]++;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        ll p,q; cin >> p >> q;

        if (!(p%q)) {
            F.clear(); fact(q);
            ll maxi = 1;
            for (auto &j : F) {
                ll mult = 1;
                while (int(log10(mult))+int(log10(j.fst))+2 <= int(log10(p))+1) {
                    mult *= j.fst;
                    if (((p/mult)%q) && !(p%mult))
                        maxi = max(maxi,p/mult);
                }
            }
            cout << maxi << '\n';
        }
        else cout << p << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
