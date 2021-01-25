#include <bits/stdc++.h>

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

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

const int MAXN = 20;
const int MOD = 1e9+7;

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

int G[MAXN][MAXN];
int dp[1<<(MAXN-1)][MAXN-1];

int main() {
    int n,m; fs(n), fs(m);
    forn(i,m) {
        int u,v; fs(u), fs(v); u--, v--;
        G[u][v]++;
    }

    dp[1][0] = 1;
    forn(i,(1<<(n-1))-1) { // al hacer menos uno saco una pasada entera
        int st = __builtin_ctz(i), nd = 32-__builtin_clz(i); // desde el primer al ultimo bit significativo
        forsn(j,st,nd) if (i&(1<<j))
            forsn(k,1,n-1)
                if (!(i&(1<<k))) {
                    int mk = i|(1<<k);
                    dp[mk][k] = (dp[mk][k] + (ll)dp[i][j]*G[j][k])%MOD; // añadimos aristas
                }
    }
    int s = 0;
    forn(j,n-1) s = (s + dp[(1<<(n-1))-1][j]*G[j][n-1])%MOD; // conecto hacia el final
    fp(s);

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
