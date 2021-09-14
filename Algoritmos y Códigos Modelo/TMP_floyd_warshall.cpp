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

const int MAXN = 1e6+2;
const int MAXA = 105;
const int INF = 1e9+5;

int D[MAXA][MAXA];
int path[MAXN],P[MAXN];
multiset<pair<ii,int>> prv; // nodo, longitud subseq, último índice

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) forn(j,n) {char c; cin >> c; D[i][j] = c-'0';}
    int m; cin >> m;
    forn(i,m) cin >> path[i], path[i]--;

    forn(i,n) forn(j,n) if (!D[i][j]) D[i][j] = INF; // no son adyacentes, no hay camino aún
    forn(i,n) D[i][i] = 0; // a mi mismo es 0

    // Floyd-Warshall
    forn(k,n) forn(i,n) forn(j,n)
        D[i][j] = min(D[i][j],D[i][k]+D[k][j]);

    prv.insert({{path[0],0},0}); P[0] = -1; // no tiene padre
    forsn(i,1,m) {
        auto it = prv.lower_bound({{path[i],-INF},-INF});
        if (it != prv.end() && (*it).fst.fst == path[i]) prv.erase(it); // como volví acá, no hay forma para preservar el de antes, entonces lo saco
        int len = INF;
        for (auto &j : prv)
            if (j.fst.snd+1 < len && D[j.fst.fst][path[i]] == i-j.snd) len = j.fst.snd+1, P[i] = j.snd;
        prv.insert({{path[i],len},i});
    }

    vi rta;
    for (int i = m-1; i != -1; i = P[i]) rta.pb(path[i]);

    cout << rta.size() << '\n';
    reverse(all(rta));
    for (auto &i : rta) cout << i+1 << ' ';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
