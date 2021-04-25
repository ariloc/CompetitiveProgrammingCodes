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

const int MAXN = 2e5+2;

void fs (int &x) {
    int c; x = 0;
    c = getchar_unlocked();
    if (c>'9'||c<'0') c = getchar_unlocked();
    for (;c<='9'&&c>='0'; c = getchar_unlocked())
        x = 10*x + c-'0';
}

vi G[MAXN];
bitset<MAXN> done;
int maxSt,maxL = -1;

void dfs (int st, int lvl) {
    done[st] = true;
    if (lvl > maxL) maxL = lvl, maxSt = st;

    for (auto &i : G[st])
        if (!done[i]) dfs(i,lvl+1);
}

int main() {
    int n; fs(n);
    forn(j,n-1) {
        int u,v; fs(u); fs(v); u--; v--;
        G[u].pb(v); G[v].pb(u);
    }
    dfs(0,0); maxL = -1; done.reset();
    dfs(maxSt,0);

    printf("%d",maxL);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
