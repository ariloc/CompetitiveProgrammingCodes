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

vector<ii> G[MAXN];
bitset<MAXN> done;
int degree[MAXN],stFrom[MAXN];

int main() {
    int n,m; fs(n), fs(m);
    forn(i,m) {
        int u,v; fs(u), fs(v); u--, v--;
        G[u].pb({v,i}); degree[v]++, degree[u]++;
    }

    forsn(i,1,n-1) if (degree[i]&1) return printf("IMPOSSIBLE"), 0;
    if (!(degree[0]&1) || !(degree[n-1]&1)) return printf("IMPOSSIBLE"), 0;

    vi pila; pila.pb(0); vi path; int markedEdges = 0;
    while (!pila.empty()) {
        auto e = pila.back();
        if (!degree[e]) {path.pb(e); pila.pop_back(); continue;}
        else {
            forsn(j,stFrom[e],G[e].size()) {
                ii v = G[e][j];
                if (!done[v.snd]) {
                    done[v.snd] = true;
                    degree[v.fst]--, degree[e]--;
                    stFrom[e] = j+1; markedEdges++;
                    pila.pb(v.fst); break;
                }
            }
        }
    }

    if (markedEdges < m) return printf("IMPOSSIBLE"), 0;
    dforn(i,path.size()) fp(path[i]+1), putchar_unlocked(' ');

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
