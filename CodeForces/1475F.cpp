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

const int MAXN = 1015;
const int MAXNN = 2*MAXN;

char a[MAXN][MAXN];
vi G[MAXNN];
bitset<MAXNN> done,color;
bool posib = true;

void dfs (int st, bool comp) {
    done[st] = true;
    color[st] = comp;

    for (auto &i : G[st]) {
        int tg = abs(i);
        if (done[tg]) {
            if ((color[tg] == comp) != (i > 0)) posib = false;
            continue;
        }
        dfs(tg,comp^(i<0));
    }
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int n; cin >> n;

        posib = true;
        forn(j,MAXNN) done[j] = false, G[j].clear();

        forn(j,n) forn(k,n) cin >> a[j][k];
        forn(j,n) forn(k,n) {
            char x; cin >> x;

            // 0 to MAXN-1 is rows, MAXN to 2*MAXN-1 is columns
            int row = j+1, col = MAXN+k+1;
            if (a[j][k] == x) { // xnor edges
                G[row].pb(col);
                G[col].pb(row);
            }
            else { // xor edges
                G[row].pb(-col);
                G[col].pb(-row);
            }
        }
        forn(j,n) if (!done[j]) dfs(j,0);
        cout << (posib ? "YES" : "NO") << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
