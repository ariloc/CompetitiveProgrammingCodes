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

void fs (int &x) {
    int c; x = 0;
    c = getchar_unlocked();
    while (c < '0' || c > '9') c = getchar_unlocked();
    for(; c >= '0' && c <= '9'; c = getchar_unlocked())
        x = 10*x + c - '0';
}

const int MAXN = 1e5+5;
const int MAXM = 2e5+5;

struct node {
    int v,id;
};

vector<node> G[MAXN];
vi BCT[MAXM], aparic[MAXM];
ii edges[MAXM];
int tin[MAXN], deg[MAXM], actT = 1, cntBiconn = 0; // node is active if tin > 0, else if tin < 0 is inactive
bitset<MAXM> matched,auxmatch;

vi pila;
int tarjan(int st) {
    tin[st] = actT++;

    int mini = tin[st];
    for (auto &i : G[st]) {
        if (!matched[i.id]) {
            int aux = tin[st];
            matched[i.id] = true; // no está matcheado ahora, pero pronto lo estará
            pila.pb(i.id);

            if (!tin[i.v]) aux = min(aux,tarjan(i.v));
            if (tin[i.v] > 0) aux = min(aux,tin[i.v]);

            if (aux >= tin[st]) {
                pila.pb(-1); // dummy

                vi toUnmatch;
                while(!pila.empty() && pila.back() != i.id) {
                    pila.pop_back(); 

                    auto e = pila.back();
                    int ind = cntBiconn+MAXN;

                    int exts[] = {edges[e].fst,edges[e].snd};
                    forn(k,2) {
                        int v = exts[k];
                        if (!auxmatch[v]) {
                            BCT[v].pb(ind), BCT[ind].pb(v);
                            deg[v]++, deg[ind]++;
                            auxmatch[v] = true, toUnmatch.pb(v);
                        }
                    }
                }
                pila.pop_back(), cntBiconn++;
                for (auto &j : toUnmatch) auxmatch[j] = false;
            }

            mini = min(mini,aux);
        }
    }
    
    tin[st] *= -1; // becomes inactive
    return mini;
}

void dfs(int st) {
    aparic[st].pb(actT++);

    for (auto &i : BCT[st]) {
        if (aparic[i].empty() && deg[i] > 1) {
            dfs(i);
            aparic[st].pb(actT++);
        }
    }
}

bool inRange (int x, int c) {
    return (aparic[x][0] > aparic[c][0] && aparic[x][0] < aparic[c].back());
}

int main() {
    int n,m,q; fs(n), fs(m), fs(q);

    forn(i,m) {
        int u,v; fs(u), fs(v); u--, v--;
        G[u].pb({v,i});
        G[v].pb({u,i});
        edges[i] = {u,v};
    }

    tarjan(0);
    actT = 1;
    dfs(MAXN);

    forn(i,q) {
        int a,b,c; fs(a), fs(b), fs(c); a--, b--, c--;

        if (a == c || b == c) printf("NO\n");
        else if (a == b) printf("YES\n");
        else if (deg[c] == 1) printf("YES\n");
        else {
            if (deg[a] == 1) a = BCT[a][0];
            if (deg[b] == 1) b = BCT[b][0];

            if (aparic[b][0] < aparic[a][0]) swap(a,b);

            bool cond1 = inRange(a,c), cond2 = inRange(b,c);

            if (cond1 != cond2) printf("NO\n"); // uno adentro y uno afuera, siempre me corta
            else if (cond1 == 1) { // si son los dos hijos, tienen que estar en la misma rama
                auto it = upper_bound(all(aparic[c]),aparic[a][0]);
                if (it == aparic[c].end() || *it > aparic[b][0])
                    printf("YES\n");
                else printf("NO\n");
            } else printf("YES\n"); // si están los dos afuera, es posible
        }

    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!