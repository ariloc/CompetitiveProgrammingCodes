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

void change (int j, int &ddU, int &ddR, int &ddD, int &ddL) {
    if (j&1) ddU = max(0,ddU-1);
    if (j&2) ddR = max(0,ddR-1);
    if (j&4) ddD = max(0,ddD-1);
    if (j&8) ddL = max(0,ddL-1);
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n,u,r,d,l; cin >> n >> u >> r >> d >> l;
        int du = min(u,n-2), dr = min(r,n-2), dd = min(d,n-2), dl = min(l,n-2);

        bool posib = false;
        forn(i,(1<<4)) {
            int ddU = du, ddR = dr, ddD = dd, ddL = dl;
            change(i,ddU,ddR,ddD,ddL);
            forn(k,(1<<4)) {
                int dddU = ddU, dddR = ddR, dddD = ddD, dddL = ddL;
                change(k,dddU,dddR,dddD,dddL);
                forn(j,(1<<4)) { // &1 is top-left, clockwise order
                    int au = u-dddU, ar = r-dddR, ad = d-dddD, al = l-dddL;
                    if (j&1) au--, al--;
                    if (j&2) au--, ar--;
                    if (j&4) ar--, ad--;
                    if (j&8) ad--, al--;
                    if (!au && !ar && !ad && !al) {posib = true; break;}
                }
            }
        }

        cout << (posib ? "YES" : "NO") << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
