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

const int MAXN = 3e5+5;

struct DS {
    vi p,r;

    void init (int N) {
        p.assign(N,0);
        r.assign(N,0);
        forn(j,N) p[j] = j;
    }

    int find (int x) {return p[x] == x ? x : p[x] = find(p[x]);}
    bool join (int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x,y);
        p[x] = y; if (r[x] == r[y]) r[y]++;
        return true;
    }
};

DS UF;
vi G[MAXN]; set<int> cmps;
bitset<MAXN> done,suf;
int inp[MAXN],inDegree[MAXN],nxt[MAXN],prv[MAXN];

bool dfs (int st, vi &rta) {
    if (done[st]) return true;
    bool v = false; done[st] = true;
    if (prv[st] != -1) v = dfs(prv[st],rta);
    rta.pb(st);
    return v;
}

int main() {
    FAST_IO;
    UF.init(MAXN);
    memset(nxt,-1,sizeof(nxt));
    memset(prv,-1,sizeof(prv));

    int n,k; cin >> n >> k;
    forn(j,n) cin >> inp[j], inp[j]--;

    forn(i,k) {
        int a,b; cin >> a >> b; a--; b--;
        if (prv[b] != -1 || nxt[a] != -1) return cout << 0, 0;
        UF.join(a,b); // uno componentes
        nxt[a] = b; prv[b] = a; // guardo contiguos para luego reconstruir
    }

    forn(i,n)
        if (inp[i] >= 0) {
            int u = UF.find(inp[i]), v = UF.find(i);
            if (u == v) continue;
            G[u].pb(v); inDegree[v]++; // trazo requisitos
        }
    forn(i,n) cmps.insert(UF.find(i)); // cuento componentess

    // topological sort de componentes
    vi topSort; queue<int> Q;
    for (auto &j : cmps) if (!inDegree[j]) Q.push(j);
    while (!Q.empty()) {
        int e = Q.front(); Q.pop();
        topSort.pb(e);

        for (auto &i : G[e])
            if (!(--inDegree[i])) Q.push(i);
    }

    if ((int)topSort.size() < (int)cmps.size()) return cout << 0, 0;

    vi rta;
    forn (j,topSort.size()) {
        bool cycle = dfs(UF.find(topSort[j]),rta); // reconstruyo atrás
        if (cycle) return cout << 0, 0;
        if (nxt[topSort[j]] != -1) // reconstruyo adelante
            for (int i = nxt[topSort[j]]; i != -1; i = nxt[i])
                rta.pb(i);
    }

    dforn(j,rta.size()) {
        if (inp[rta[j]] == -1) {
            if (j) NOPE: return cout << 0, 0;
        } else if (suf[inp[rta[j]]]) goto NOPE;
        suf[rta[j]] = true;
    }
    for (auto &i : rta) cout << i+1 << ' ';

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
