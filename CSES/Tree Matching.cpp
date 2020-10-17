#include <bits/stdc++.h>

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

const int MAXN = 2e5+2;

bitset<MAXN> done;
vi G[MAXN];
ii dp[MAXN]; // not taken | taken (0,1)

void dfs(int st) {
    done[st] = true;

    ii me = {0,0};
    int parent = -1;
    // si no agarro, es como si agarrara en cada caso abajo
    for (auto &i : G[st])
        if (!done[i]) {dfs(i); me.fst += dp[i].snd;}
        else parent = i; // padre, de existir

    // si agarro, es lo mismo que caso contrario, excepto uno que no agarro, y sumo 1 del que agarro
    // (obtengo la mejor posibilidad)
    int sum = 0;
    for (auto &i : G[st]) if (i != parent)
        me.snd = max(me.fst-dp[i].snd+dp[i].fst+1,me.snd);

    dp[st] = me;
}

int main() {
    int n; scanf("%d",&n);
    int cnt = 0;
    forn(i,n-1) {
        int a,b; scanf("%d %d",&a,&b); a--; b--;
        G[a].pb(b); G[b].pb(a);
    }

    dfs(0);
    printf("%d",max(dp[0].fst,dp[0].snd));

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
