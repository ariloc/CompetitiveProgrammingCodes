#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)

using namespace std;
typedef long long ll;

int const MAXN = 1e5+5;

ll cn[MAXN],vn[MAXN];

int main() {
    int n; cin >> n;

    ll prvc = 0, prvv = 0;
    forn(i,n) {
        int c,v; cin >> c >> v;
        prvc += c;
        prvv += v;
        cn[i] = prvc;
        vn[i] = prvv;
    }

    int q; cin >> q;
    forn(i,q) {
        int dep; cin >> dep;
        --dep;
        int a = cn[dep]-vn[dep];
        int b = cn[dep]+vn[dep];
        if (!a) cout << "NEUTRO\n";
        else if ((a > 0 && b > 0) || (a < 0 && b < 0)) cout << "COMPRA\n";
        else cout << "VENDA\n";
    }

    return 0;
}
