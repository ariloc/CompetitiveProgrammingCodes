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

    int q; cin >> q;

    set<ii> mono;
    auto comp = [](const ii &a, const ii &b) {if (a.snd == b.snd) {return a.fst < b.fst;}
                                                                   return a.snd > b.snd;};
    set<ii, decltype(comp)> poly(comp);

    int cnt = 0;
    forn(i,q) {
        int typ; cin >> typ;
        if (typ == 1) {
            int m; cin >> m;
            mono.insert({cnt,m});
            poly.insert({cnt++,m});
        }
        else if (typ == 2) {
            ii me = (*mono.begin());
            cout << me.fst+1 << ' ';
            mono.erase(mono.begin());
            poly.erase(me);
        }
        else {
            ii me = (*poly.begin());
            cout << me.fst+1 << ' ';
            poly.erase(poly.begin());
            mono.erase(me);
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
