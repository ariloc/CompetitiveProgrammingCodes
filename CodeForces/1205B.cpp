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

const int MAXD = 70;
const int MAXN = 200;
const int INF = 1e9+5;

int bitsOn[MAXD],tin[MAXN],n;
bool ady[MAXN][MAXN];
vector<ll> inp,inp2;
bitset<MAXN> done;

struct nodoBFS {
    int v,turn,p;
};

int bfs (int st) {
    queue<nodoBFS> Q; tin[st] = 0; Q.push({st,0,-1});

    int mini = INF;
    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        forn(i,n) if (ady[e.v][i]) {
            if (tin[i] == -1) tin[i] = e.turn+1, Q.push({i,e.turn+1,e.v});
            else if (i != e.p) mini = min(mini,e.turn+tin[i]+1);
        }
    }
    return mini;
}

int main() {
    scanf("%d",&n);
    forn(i,n) {
        ll x; scanf("%lld",&x);
        forn(j,63) if (x&(1LL<<j)) bitsOn[j]++; // tranqui total es 1e18
        inp.pb(x);
    }

    forn(j,MAXD) if (bitsOn[j] > 2) return puts("3"); // si hay más de dos con un mismo bit
    forn(i,n) if (inp[i]) inp2.pb(inp[i]); // descartemos los que tienen cero para que quede chico el grafo
    // ahora queda aprox peor caso, 128 nodos (pues como mucho dos pueden tener un mismo bit y no son 0s -> 2*64), capaz menos porque a_i <= 1e18, no 9e18

    // de lo contrario el grafo me queda chiquito y se puede hacer naive
    n = inp2.size();
    forn(i,n) forsn(j,i+1,n)
        if (inp2[i]&inp2[j]) ady[i][j] = ady[j][i] = 1;

    int rta = INF;
    forn(i,n) {
        forn(j,n) tin[j] = -1;
        rta = min(bfs(i),rta);
    }
    printf("%d",(rta == INF ? -1 : rta));

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
