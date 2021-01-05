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

    int t; cin >> t;
    forn(i,t) {
        ll n; cin >> n;
        if (n&1) cout << "-1\n";
        else {
            vi rta;
            ll sum = 0;

            while (sum < n) {
                if (((n-sum)/2) <= 2000-(int)rta.size()) {
                    forn(j,(n-sum)/2) sum += 2, rta.pb(1);
                }
                else {
                    ll acc = 4;
                    sum += 2; rta.pb(1);
                    while (acc+sum <= n) rta.pb(0), sum += acc, acc <<= 1;
                }
            }
            if (rta.size() <= 2000) {
                cout << rta.size() << '\n';
                for (auto &j : rta) cout << j << ' ';
                cout << '\n';
            }
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
