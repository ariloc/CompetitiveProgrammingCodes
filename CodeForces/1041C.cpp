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
const int INF = 1e9+5;

ii brks[MAXN];
int P[MAXN],S[MAXN],rta[MAXN];

int main() {
    FAST_IO;
    memset(P,-1,sizeof(P)); // init
    memset(S,-1,sizeof(S)); // init

    int n,m,d; cin >> n >> m >> d;
    forn(i,n) cin >> brks[i].fst, brks[i].snd = i;

    sort(brks,brks+n);

    multiset<ii> LIS;
    forn(i,n) {
        auto it = LIS.upper_bound({brks[i].fst-1-d,INF});
        if (it != LIS.begin()) {
            it--;
            P[brks[i].snd] = (*it).snd;
            S[(*it).snd] = brks[i].snd;
            LIS.erase(it);
        }
        LIS.insert(brks[i]);
    }

    int prox_libre = 1;
    dforn(i,n) {
        if (rta[i]) continue; // hago ambos pues el orden de los índices no me asegura nada
        for (int j = i; j != -1; j = P[j]) // predecesores
            rta[j] = prox_libre;
        for (int j = i; j != -1; j = S[j]) // sucesores
            rta[j] = prox_libre;
        prox_libre++;
    }

    cout << prox_libre-1 << '\n';
    forn(i,n) cout << rta[i] << ' ';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
