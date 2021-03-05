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

const int MAXN = 505;
const int MAXT = 3*MAXN;
const int INF = 1e9+5;

struct DS {
    vi p,r;

    void init (int N) {
        p.assign(N,0);
        r.assign(N,0);
        forn(i,N) p[i] = i;
    }

    int find (int x) {return p[x] == x ? x : p[x] = find(p[x]);}
    bool join (int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x,y);
        p[x] = y; if (r[x] == r[y]) r[y]++;
        return true;
    }
};

int ady[MAXN][MAXN],sal[MAXT],P[MAXT];
bool done[MAXN][MAXN];
bitset<MAXN> doneN;
vi G[MAXT],cmp[MAXN];
DS UF;

int main() {
    FAST_IO;

    UF.init(MAXN);
    forn(i,MAXN) P[i] = i; // init

    int n; cin >> n;
    forn(i,n) forn(j,n) cin >> ady[i][j];
    int prox_libre = n;

    for(;;) {
        forn(i,MAXN) cmp[i].clear(); // reset
        doneN.reset();

        int mini = INF;
        forn(i,n) forn(j,n) if (i != j && !done[i][j])
            mini = min(mini,ady[i][j]);

        forn(i,n) forn(j,n) if (ady[i][j] == mini) done[i][j] = true; // así el mínimo es mayor en la pŕoxima pasada

        forn(i,n) { // voy uniendo aquellas comp que pairwise dan el mínimo, entonces tienen padre común
            if (doneN[UF.find(i)]) continue;
            int y = i; doneN[i] = true;
            forn(x,n) if (y != x && ady[y][x] == mini) UF.join(x,y), y = x, doneN[x] = true; // voy saltando
        }

        forn(i,n) cmp[UF.find(i)].pb(i);
        int cmpCnt = 0;
        forn(i,MAXN) if (!cmp[i].empty()) {
            set<int> toPush;
            for (auto &j : cmp[i]) toPush.insert(P[j]);
            if ((int)toPush.size() <= 1) {cmpCnt++; continue;}
            for (auto &j : toPush) G[prox_libre].pb(j);
            for (auto &j : cmp[i]) P[j] = prox_libre;
            sal[prox_libre] = mini;
            prox_libre++, cmpCnt++;
        }

        if (cmpCnt <= 1) break; // cuando todo está unido
    }

    forn(i,n) sal[i] = ady[i][i]; // los que no puse nunca

    cout << prox_libre << '\n';
    forn(i,prox_libre) cout << sal[i] << ' ';
    cout << '\n';
    cout << prox_libre << '\n';
    forn(i,prox_libre) for (auto &j : G[i]) cout << j+1 << ' ' << i+1 << '\n';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
