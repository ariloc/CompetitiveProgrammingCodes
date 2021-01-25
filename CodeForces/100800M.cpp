#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
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
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 1005;

ll t[MAXN],x[MAXN];
set<ll> rta;

int main() {
    FAST_IO;

    int m,n; cin >> m >> n;

    forn(i,m) cin >> t[i];
    forn(i,n) cin >> x[i];

    forn(i,n-m+1) {
        ld k = (x[i+1]-x[i])/(ld)(t[1]-t[0]);
        bool posib = true;
        forsn(j,1,m-1) {
            ld myK = (x[i+j]-x[i+j+1])/(ld)(t[j]-t[j+1]);
            if (myK != k) {posib = false; break;}
        }
        if (posib) rta.insert(x[i+1]-x[i]);
    }

    cout << rta.size() << '\n';
    for (auto &i : rta) cout << i << ' ';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
