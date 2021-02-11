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

const int TOP = 2500;
const ld EPS = 1e-13;

ld n,p,s,v;

ld fun(ld c) {
    return s*((ld)1 + 1/c)/v + (n*pow(log2(n),c*sqrt(2)))/(p*(ld)1e9); // OBLIGADO A USAR POW :'v
}

int main() {
    FAST_IO;

     cin >> n >> p >> s >> v;

    int cnt = TOP;
    ld l = 0, r = TOP;
    while (cnt--) {
        ld tl = (2*l + r)/3, tr = (l + 2*r)/3;
        if (fun(tl) < fun(tr)) r = tr;
        else l = tl;
    }

    cout << fixed << setprecision(15) << fun(l) << ' ' << l;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
