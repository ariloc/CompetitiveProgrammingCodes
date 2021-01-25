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

    ll n,d,a,b; cin >> n >> d >> a >> b;
    ll prv = -1, kD = 1, kA = 1, shares = 0;
    forn(i,n) {
        int x; cin >> x;

        if (i) {
            if (x > prv) {
                kD = 1;
                ll cant = d/x;
                cant = min(cant,kA*a);
                shares += cant, d -= x*cant;
                kA++;
            }
            else if (x < prv) {
                kA = 1;
                ll cant = min(kD*b,shares);
                shares -= cant, d += x*cant;
                kD++;
            }
        }

        prv = x;
    }

    cout << d << ' ' << shares;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
