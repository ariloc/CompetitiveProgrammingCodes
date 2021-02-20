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

const int TOP = 1e9;

vi nums;

int main() {
    FAST_IO;

    // precalc
    for (ll a = 1; a*a <= 2*TOP + 1; a++) {
        ll c = a*a + 1;
        if (c&1) continue; // tiene que poder dividirse por 2
        c /= 2LL;
        if (a < c && c <= TOP) nums.pb(c); // check de cotas
    }

    int t; cin >> t;
    forn(o,t) {
        int n; cin >> n;
        int ind = upper_bound(all(nums),n)-nums.begin();
        cout << ind << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
