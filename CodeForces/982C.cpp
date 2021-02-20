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

const int MAXN = 1e5+5;

vi G[MAXN];
bitset<MAXN> done;
int rta = 0;

int dfs (int st) {
    done[st] = true;
    //cerr << st << "!!!!" << endl;

    int sum = 0;
    for (auto &i : G[st])
        if (!done[i]) {
            int aux = dfs(i);
            if (!(aux&1) && aux) rta++;
            else sum += aux;
            //cerr << i << ' ' << aux << ' ' << st << ' ' << sum << ' ' << rta << endl;
        }

    if (sum&1) {rta++; return 0;}
    return sum+1;
}

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n-1) {
        int u,v; cin >> u >> v; u--, v--;
        G[u].pb(v), G[v].pb(u);
    }
    if (n&1) return cout << -1, 0;

    int leaf = -1;
    forn(i,n) if (G[i].size() <= 1) {leaf = i; break;}

    dfs(leaf);
    cout << rta-1;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
