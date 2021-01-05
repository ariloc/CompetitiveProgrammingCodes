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

void fs (int &x) {
    int c; x = 0;
    c = getchar_unlocked();
    if (c>'9'||c<'0') c = getchar_unlocked();
    for (;c<='9'&&c>='0'; c = getchar_unlocked())
        x = 10*x + c-'0';
}

vi G[MAXN];
bitset<MAXN> done;
pair<ii,int> distCh[MAXN];
int rta[MAXN];

int dfs (int st) {
    done[st] = true;

    int maxi = 0, maxi2 = 0, idMaxi = st;
    for (auto &i : G[st])
        if (!done[i]) {
            int v = dfs(i);
            if (v > maxi) {
                swap(maxi,maxi2);
                maxi = v; idMaxi = i;
            }
            else if (v > maxi2) maxi2 = v;
        }
    distCh[st] = {{maxi,idMaxi},maxi2};
    rta[st] = maxi;
    return 1+maxi;
}

void dfs2 (int st, int maxi) {
    done[st] = true;
    rta[st] = max(maxi,rta[st]);

    for (auto &i : G[st])
        if (!done[i])
            dfs2(i,max(maxi,(distCh[st].fst.snd == i ? distCh[st].snd : distCh[st].fst.fst))+1);
}

int main() {
    int n; fs(n);
    forn(j,n-1) {
        int u,v; fs(u); fs(v); u--; v--;
        G[u].pb(v); G[v].pb(u);
    }

    dfs(0);
    done.reset(); dfs2(0,-INF);

    forn(j,n) printf("%d ",rta[j]);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
