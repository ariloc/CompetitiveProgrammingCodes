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
const int INF = 1e9+5;
const int MAXST = (1<<(32-__builtin_clz(2*MAXN)));

void fs (int &x) {
    int c; x = 0;
    c = getchar_unlocked();
    if (c>'9'||c<'0') c = getchar_unlocked();
    for (;c<='9'&&c>='0'; c = getchar_unlocked())
        x = 10*x + c-'0';
}

vi G[MAXN];
ii ST[2*MAXST];
int F[MAXN], dist[MAXN], actT = 1;

void euler (int st, int lvl) {
    ST[actT+MAXST] = {lvl,st};
    F[st] = actT++;

    for (auto &i : G[st])
        if (!F[i]) {
            euler(i,lvl+1);
            ST[actT+MAXST] = {lvl,st};
            actT++;
        }
}

void calcDist (int st, int lvl) {
    dist[st] = lvl;

    for (auto &i : G[st])
        if (!dist[i] && i) calcDist(i,lvl+1); // nunca hay arista a si mismo
}

ii query (int i, int tl, int tr, int bl, int br) {
    if (tl >= br || tr <= bl) return {INF,INF};
    if (tl >= bl && tr <= br) return ST[i];

    int mid = (tl+tr)/2;
    return min(query(2*i,tl,mid,bl,br),query(2*i+1,mid,tr,bl,br));
}

int main() {
    int n,q; fs(n); fs(q);

    forn(j,n-1) {
        int u,v; fs(u); fs(v); u--; v--;
        G[u].pb(v); G[v].pb(u);
    }

    euler(0,0); calcDist(0,0);

    dforsn(i,1,MAXST) ST[i] = min(ST[2*i],ST[2*i+1]); // build

    forn(j,q) {
        int a,b; fs(a); fs(b); a--; b--;
        if (F[a] > F[b]) swap(a,b);
        ii v = query(1,0,MAXST,F[a],F[b]+1);
        printf("%d\n",dist[a]+dist[b]-dist[v.snd]*2);
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
