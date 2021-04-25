#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast,unroll-loops")
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
const int MAXT = 2*MAXN;

void fs (int &x) {
    int c; x = 0; bool neg = false;
    c = getchar_unlocked(); neg |= (c == '-');
    if (c < '0' || c > '9') c = getchar_unlocked(), neg |= (c == '-');
    for (; c>='0' && c<='9'; c = getchar_unlocked())
        x = 10*x + c-'0';
    if (neg) x *= -1;
}

void fp (ll x) {
    if (!x) {putchar_unlocked('0'); return;}
    int i = 19;
    char buf[20];
    while (x) buf[i--] = (x%10)+'0', x /= 10LL;
    while ((++i) < 20) putchar_unlocked(buf[i]);
}

vi G[MAXN];
int val[MAXN],FA[MAXN],LA[MAXN],actT = 2;
ll FT[MAXT];

void setFT (int p, int v) {
    for (int i = p; i < MAXT; i += i & -i)
        FT[i] += v;
}

ll getFT (int p) {
    ll r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

void dfs (int st) {
    FA[st] = LA[st] = actT;
    setFT(actT++,val[st]);

    for (auto &i : G[st]) {
        if (!FA[i]) {
            dfs(i);
            LA[st] = actT++;
        }
    }
}

int main() {
    int n,q; fs(n), fs(q);

    forn(i,n) fs(val[i]);

    forn(i,n-1) {
        int u,v; fs(u), fs(v); u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    dfs(0);

    forn(i,q) {
        int typ,s; fs(typ), fs(s); s--;
        if (typ == 2) fp(getFT(LA[s])-getFT(FA[s]-1)), putchar_unlocked('\n');
        else {
            int x; fs(x);
            setFT(FA[s],x-val[s]);
            val[s] = x;
        }
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
