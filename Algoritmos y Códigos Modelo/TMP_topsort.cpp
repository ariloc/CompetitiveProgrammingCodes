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

int posic[MAXN], inDeg[MAXN];
bool supera[MAXN][MAXN],ady[MAXN][MAXN];
vi G[MAXN];

int main() {
    //freopen("entrada.txt","r",stdin);
    int t; scanf("%d",&t);

    forn(o,t) {
        int n; scanf("%d",&n);

        forn(i,n+2) inDeg[i] = 0, G[i].clear(); // reset
        forn(i,n+2) forn(j,n+2) supera[i][j] = ady[i][j] = 0;

        forn(i,n) scanf("%d",&posic[i]), posic[i]--;
        forn(i,n) forn(j,i) supera[posic[j]][posic[i]] = true;

        int m; scanf("%d",&m);
        forn(i,m) {
            int u,v; scanf("%d %d",&u,&v); u--, v--;
            if (supera[u][v]) swap(u,v);
            ady[u][v] = true;
            G[u].pb(v); inDeg[v]++;
        }

        forn(i,n) {
            forn(j,i) if (!ady[posic[i]][posic[j]]) G[posic[j]].pb(posic[i]), inDeg[posic[i]]++; // si no hay nada que diga que lo supero, me supera
            forsn(j,i+1,n) if (!ady[posic[j]][posic[i]]) G[posic[i]].pb(posic[j]), inDeg[posic[j]]++; // si no hay nada que diga que me supera, lo sigo superando
        }

        vi topSort;
        queue<int> Q;
        forn(i,n) if (!inDeg[i]) Q.push(i);

        while (!Q.empty()) {
            auto e = Q.front(); Q.pop();
            topSort.pb(e);

            for (auto &i : G[e])
                if (!(--inDeg[i])) Q.push(i);
        }

        if ((int)topSort.size() < n) puts("IMPOSSIBLE");
        else {
            for (auto &i : topSort) printf("%d ",i+1);
            putchar('\n');
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!