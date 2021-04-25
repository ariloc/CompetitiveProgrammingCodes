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

const int MAXN = 2e5+5;
const int MAXP = 1e7+5;

int spf[MAXP];
bitset<MAXP> done;

void criba() {
    forn(i,MAXP) spf[i] = i;
    for (int i = 4; i < MAXP; i+=2) done[i] = true, spf[i] = 2;
    for (int i = 3; i*i <= MAXP; i+=2)
        if (!done[i])
            for (int j = i+i; j < MAXP; j+=i) {
                if (!done[j]) spf[j] = i;
                done[j] = true;
            }
}

set<int> used;

int main() {
    FAST_IO;

    criba();

    int t; cin >> t;
    forn(o,t) {
        int n,k; cin >> n >> k;

        used.clear(); // reset
        
        int rta = 1;
        forn(i,n) {
            int x; cin >> x;
            int reduc = 1;

            int prv = spf[x], cnt = 0;
            while (x > 1) {
                if (spf[x] != prv) {
                    if (cnt&1) reduc *= prv; // sólo tengo que ver que se arreglen los impares, así que si el patron da tal
                    cnt = 0;
                }

                prv = spf[x];
                x /= spf[x];
                cnt++;
            }
            if (cnt&1) reduc *= prv;
            
            if (used.count(reduc)) {rta++; used.clear();}
            used.insert(reduc);
        }

        cout << rta << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!