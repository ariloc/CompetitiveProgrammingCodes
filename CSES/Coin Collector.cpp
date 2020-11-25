#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const int MAXN = 1e5+2;

int coins[MAXN],tin[MAXN],col[MAXN],colInDegree[MAXN],prox_libre = 0,actT = 1;
ll dp[MAXN];
bitset<MAXN> done,matched;
vi G[MAXN],comp[MAXN];

void fastscan (int &x) {
    int c; x = 0;
    c=getchar_unlocked();
    if (c<'0'||c>'9') c=getchar_unlocked();
    for(; c>='0'&&c<='9'; c=getchar_unlocked())
        x = 10*x + c-'0';
}

ll dfs (int st) {
    for (auto &i : comp[col[st]]) done[i] = true;

    ll r = 0;
    for (auto &i : comp[col[st]])
        for (auto &j : G[i]) {
            if (!done[j]) dfs(j);
            if (col[st] != col[j]) r = max(r,dp[col[j]]);
        }

    dp[col[st]] += r;
    return dp[col[st]];
}

vi pila;
int tarjan (int st) {
    tin[st] = actT++;
    pila.pb(st);

    int myT = actT-1;
    for (auto &i : G[st]) {
        if (!tin[i]) myT = min(myT,tarjan(i));
        if (!matched[i]) myT = min(myT,tin[i]);
    }

    if (myT >= tin[st]) while (!pila.empty()) {
        auto e = pila.back(); pila.pop_back();
        matched[e] = true;
        col[e] = prox_libre; dp[prox_libre] += coins[e];
        comp[prox_libre].pb(e);
        if (e == st) {prox_libre++; break;}
    }

    return myT;
}

int main() {
    int n,m; fastscan(n); fastscan(m);
    forn(i,n) fastscan(coins[i]);
    forn(i,m) {
        int u,v; fastscan(u); fastscan(v); u--; v--;
        G[u].pb(v);
    }
    ll maxi = 0;
    forn(i,n) if (!matched[i]) tarjan(i);

    // obtengo el inDegree de las componentes conexas
    forn(i,n) for (auto &j : G[i]) if (col[j] != col[i]) colInDegree[col[j]]++;
    forn(i,n) if (!done[i] && !colInDegree[col[i]]) dfs(i); // recorro desde los inDegree 0
    forn(i,n) maxi = max(maxi,dp[i]);

    printf("%lld",maxi);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
