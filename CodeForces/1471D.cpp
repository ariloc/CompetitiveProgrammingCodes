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

const int MAXN = 3e5+5;
const int MAXX = 1e6+5;

int spf[MAXX], arr[MAXN];
bitset<MAXX> done;

void cribaFact() {
    // reemplazo los números por el producto de los factores primos elevados a la paridad.
    forsn(j,1,MAXX) spf[j] = j;
    for (int i = 2; i < MAXX; i+=2) done[i] = true, spf[i] = 2;
    for (int i = 3; i*i <= MAXX; i+=2) {
        if (!done[i])
            for (int j = i; j < MAXX; j+=i) {
                if (!done[j]) spf[j] = i;
                done[j] = true;
            }
    }
}

int main() {
    FAST_IO;

    cribaFact();

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;
        forn(j,n) {
            int x; cin >> x;

            int r = 1, prv = spf[x], cnt = 0;
            while (x > 1) {
                if (spf[x] != prv) {
                    if (cnt&1) r *= prv;
                    cnt = 0;
                }
                prv = spf[x];
                x /= spf[x];
                cnt++;
            }
            if (cnt&1) r *= prv;

            arr[j] = r;
        }

        map<int,int> typ;
        int evS = 0, maxi = 0, maxiOd = 0, cantOne = 0;
        forn(j,n) typ[arr[j]]++;
        for (auto &j : typ) {
            if (j.fst != 1) {
                if (!(j.snd&1)) evS += j.snd;
                else maxiOd = max(maxiOd,j.snd);
            } else cantOne = j.snd;
            maxi = max(maxi,j.snd);
        }

        int q; cin >> q;
        forn(j,q) {
            ll x; cin >> x;
            if (!x) cout << maxi << '\n';
            else cout << max(maxiOd,evS+cantOne) << '\n';
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
