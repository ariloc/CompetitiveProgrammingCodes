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
const int MAXST = (1<<(32-__builtin_clz(MAXN)));
const int INF = 2e9;
const int NEUT = -INF;
 
void fs (int &x) {
    x = 0;
    int c; c = getchar();
    if (c < '0' || c > '9') c = getchar();
    for (; c >= '0' && c <= '9'; c = getchar())
        x = 10*x + c-'0';
}
 
struct mon {
    int v;
 
    mon operator+ (const mon &o) const {
        return {max(v,o.v)};
    }
};
 
vi G[MAXN];
int vals[MAXN], P[MAXN], hd[MAXN], pos[MAXN], hv[MAXN], dep[MAXN], cntPos = 0;
int n,q,N;
mon ST[2*MAXST];
 
// HLD (Heavy/Light Decompositiion)
int dfs (int st, int lvl) {
    dep[st] = lvl;
 
    int maxi = NEUT, ind = -1, cnt = 0;
    for (auto &i : G[st])
        if (P[st] != i) {
            P[i] = st;
            int aux = dfs(i,lvl+1);
            cnt += aux;
            if (aux > maxi) maxi = aux, ind = i;
        }
 
    hv[st] = ind;
    return cnt+1;
}
 
void decompose(int st, int m_hd) {
    pos[st] = cntPos++, hd[st] = m_hd;
    if (hv[st] != -1)
        decompose(hv[st],m_hd);
    for (auto &i : G[st])
        if (hv[st] != i && P[st] != i)
            decompose(i,i);
}
 
void update (int p, int v) {
    p += N; ST[p].v = v;
    while (p > 1) 
        p /= 2, ST[p] = ST[2*p] + ST[2*p+1];
}
 
mon query (int l, int r) {
    mon acc = {NEUT};
    l += N, r += N;
    for (; l < r; l /= 2, r /= 2) {
        if (l&1) acc = (acc + ST[l++]);
        if (r&1) acc = (acc + ST[--r]);
    }
    return acc;
}
 
int query_lca (int a, int b) {
    int maxi = NEUT;
    // notar que la condición siempre depende que los caminos heavy no convergen
    for (; hd[a] != hd[b]; b = P[hd[b]]) {
        if (dep[hd[a]] > dep[hd[b]]) swap(a,b);
        maxi = max(maxi, query(pos[hd[b]],pos[b]+1).v);
    }
    if (pos[a] > pos[b]) swap(a,b);
    maxi = max(maxi, query(pos[a],pos[b]+1).v);
    return maxi;
}
 
int main() {
    //freopen("test_input.txt","r",stdin);
    fs(n), fs(q);
    forn(i,n) fs(vals[i]);
    forn(i,n-1) {
        int u,v; fs(u), fs(v); u--, v--;
        G[u].pb(v), G[v].pb(u);
    }
 
    P[0] = -1;
    dfs(0,0); decompose(0,0);
 
    N = (1<<(32-__builtin_clz(n)));
    //cerr << N << endl;
    forn(i,n) ST[pos[i]+N].v = vals[i];
    dforsn(i,1,N) ST[i] = ST[2*i]+ST[2*i+1];
 
    forn(i,q) {
        int typ; fs(typ);
 
        if (typ == 1) {
            int s,x; fs(s), fs(x); s--;
            update(pos[s],x);
        }
        else {
            int a,b; fs(a), fs(b); a--, b--;
            printf("%d ",query_lca(a,b));
        }
    }
 
    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!