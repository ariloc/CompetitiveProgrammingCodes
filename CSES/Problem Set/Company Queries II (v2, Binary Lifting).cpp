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
const int LOGMAXN = 19;

int P[MAXN][LOGMAXN], dep[MAXN];
vi G[MAXN];

void dfs (int st, int lvl) {
    dep[st] = lvl;
    for (auto &i : G[st])
        dfs(i,lvl+1);
}

int lca (int a, int b) {
    if (dep[a] > dep[b]) swap(a,b);
    int dif = dep[b]-dep[a];
    forn(i,LOGMAXN) if (dif&(1<<i)) b = P[b][i];
    if (a == b) return a;
    dforn(i,LOGMAXN)
        if (P[a][i] != P[b][i]) 
            a = P[a][i], b = P[b][i];
    return P[a][0];
}

int main() {
    int n,q; scanf("%d %d",&n,&q);
    forsn(i,1,n) {
        int x; scanf("%d",&x); x--;
        P[i][0] = x, G[x].pb(i);
    }

    forsn(j,1,LOGMAXN) forn(i,n) P[i][j] = P[P[i][j-1]][j-1];

    dfs(0,0);

    forn(i,q) {
        int a,b; scanf("%d %d",&a,&b); a--, b--;
        printf("%d\n",lca(a,b)+1);
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!