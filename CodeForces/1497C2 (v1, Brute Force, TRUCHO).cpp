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

ll myLcm (ll a, ll b, ll c) {
    ll aux = (a*b)/__gcd(a,b);
    aux = (aux*c)/__gcd(aux,c);
    return aux;
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n,k; cin >> n >> k;
        int a = 1, b = 1, c = 1;

        int dif = n-k;
        a += dif/2; b = a;
        if ((n&1) != (k&1)) {
            c++;
            while (a > 1 && myLcm(a,b,c) > n/2.0) a--, b--, c += 2;
        }

        cout << a << ' ' << b << ' ' << c << ' ';
        forn(i,k-3) cout << "1 ";
        cout << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!