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

ll cnt (ll v, ll n, ll m) { // cantidad de numeros menores que hay
    ll r = 0;
    forsn(i,1,n+1) {
        ll factor = v / i;
        if ((factor * i) == v) factor--;
        factor = min(factor,m);
        r += factor;
    }
    return r;

}

int main() {
    FAST_IO;

    ll n,m,k; cin >> n >> m >> k;

    ll low = 1, high = n*m + 1;
    while (high - low > 1) {
        ll mid = (high+low)/2;

        if (cnt(mid,n,m) >= k) high = mid;
        else low = mid;
    }

    cout << low;

    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!