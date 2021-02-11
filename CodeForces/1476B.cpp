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

const int MAXN = 102;

ll p[MAXN],ch[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n,k; cin >> n >> k;
        forn(j,n) cin >> p[j];
        forn(j,n) ch[j] = 0; // reset;

        ld coef = (k/(ld)100);

        ll actP = p[0];
        forsn(j,1,n) {
            ld me = p[j]/(ld)actP;
            //cerr << me << ' ' << actP << endl;
            if (me > coef) {
                //cerr << "OKK" << endl;
                ll tg = (ld)p[j]/coef;
                if ((p[j]/(ld)tg) > coef) tg++; // trunc issues
                ch[j-1] = tg-actP;
            }
            actP += p[j];
        }

        ll accDif = 0, rta = 0;
        forn(j,n-1) {
            ll aux = max(0LL,ch[j]-accDif);
            accDif += aux; rta += aux;
        }

        cout << rta << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
