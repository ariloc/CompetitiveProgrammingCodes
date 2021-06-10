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
 
const int MAXN = 1e5+5;
const int MAXM = 2*MAXN;
 
struct node {
    int v,id;
};
 
void fs (int &x) {
    int c; x = 0;
    c = getchar_unlocked();
    if (c < '0' || c > '9') c = getchar_unlocked();
    for (; c >= '0' && c <= '9'; c = getchar_unlocked())
        x = 10*x + c - '0';
}
 
vector<node> G[MAXN];
vector<ii> rta;
int tin[MAXN], actT = 1;
bitset<MAXM> matched;
bool posib = true;
 
vector<pair<ii,int>> pila; // (a -> b), id
int tarjan(int st) {
    tin[st] = actT++;
 
    int mini = tin[st];
    for (auto &i : G[st]) {
        if (!matched[i.id]) {
            int aux = tin[st];
            matched[i.id] = true;
            pila.pb({{st,i.v},i.id});
 
            if (!tin[i.v]) aux = min(aux,tarjan(i.v));
            if (tin[i.v] > 0) aux = min(aux,tin[i.v]);
 
            if (aux >= tin[st]) {
                int cnt = 0;
                while (!pila.empty()) {
                    auto e = pila.back(); pila.pop_back();
                    cnt++;
                    rta.pb(e.fst);
                    if (e.snd == i.id) break; // hasta el mío incluído
                }
 
                if (cnt == 1) posib = false; // no se puede si hay puentes
            }
 
            mini = min(aux,mini);
        }
    }
 
    return mini;
}
 
int main() {
    int n,m; fs(n), fs(m);
 
    forn(i,m) {
        int u,v; fs(u), fs(v); u--, v--;
        G[u].pb({v,i}), G[v].pb({u,i});
    }
 
    tarjan(0);
    if (posib && (int)rta.size() < m) posib = false; // nunca me dice que sea un grafo conexo
 
    if (posib) 
        for (auto &i : rta) printf("%d %d\n",i.fst+1,i.snd+1);
    else printf("IMPOSSIBLE");
 
    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!