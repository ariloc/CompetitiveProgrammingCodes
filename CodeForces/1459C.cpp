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

    int n,m; cin >> n >> m;
    ll dcm = -1,prev;
    forn(i,n) {
        ll x; cin >> x;
        if (i) {
            if (i == 1) dcm = abs(x-prev);
            else dcm = __gcd(dcm,abs(x-prev));
        }
        prev = x;
    }
    if (n == 1) {forn(j,m) {ll x; cin >> x; cout << prev+x << ' ';} return 0;} // caso 0
    forn(j,m) {ll x; cin >> x; cout << __gcd(prev+x,dcm) << ' ';}

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
