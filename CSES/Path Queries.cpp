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

int vals[MAXN],tin[MAXN],tout[MAXN],actT = 1;
ll FT[MAXN];
vi G[MAXN];

void fs (int &x) {
    int c; x = 0; bool neg = false;
    c = getchar_unlocked(); neg |= (c == '-');
    if (c < '0' || c > '9') c = getchar_unlocked(), neg |= (c == '-');
    for (; c>='0' && c<='9'; c = getchar_unlocked())
        x = 10*x + c-'0';
    if (neg) x *= -1;
}

void setFT (int p, ll v) {
    for (int i = p; i < MAXN; i += i & -i)
        FT[i] += v;
}

ll getFT (int p) {
    ll r = 0;
    for (int i = p; i; i -= i & -i)
        r += FT[i];
    return r;
}

void tour (int st, ll acc) {
    setFT(actT,acc+vals[st]),setFT(actT+1,-acc-vals[st]);
    tin[st] = actT++;

    for (auto &i : G[st])
        if (!tin[i]) tour(i,acc+vals[st]);

    tout[st] = actT-1; // si bien le llamo Euler Tour, nomás me guardo los hijos y la aparic del últ
}

int main() {
    int n,q; fs(n), fs(q);
    forn(i,n) fs(vals[i]);
    forn(i,n-1) {
        int u,v; fs(u), fs(v); u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    tour(0,0);

    forn(i,q) {
        int typ,s; fs(typ), fs(s); s--;
        if (typ == 1) {
            int x; fs(x);
            ll dif = x-vals[s]; vals[s] = x;
            setFT(tin[s],dif), setFT(tout[s]+1,-dif);
        }
        else printf("%lld\n",getFT(tin[s]));
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
