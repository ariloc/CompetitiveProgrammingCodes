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

struct DS {
    vi p,r;
    vector<set<int>> secs;
    
    void init(int N) {
        p.assign(N,0);
        r.assign(N,0);
        secs.resize(N);
        forn(i,N) p[i] = i;
    }

    int find (int x) {return p[x] == x ? x : p[x] = find(p[x]);}

    void J_OR (int x, int y) {
        for (auto &i : secs[x]) secs[y].insert(i);
    }

    void J_AND (int x, int y) {
        set<int> aux;
        for (auto &i : secs[x]) if (secs[y].count(i)) aux.insert(i);
        aux.swap(secs[y]);
    }

    void J_XOR (int x, int y) {
        for (auto &i : secs[x])
            if (secs[y].count(i)) secs[y].erase(i);
            else secs[y].insert(i);
    }

    bool join(int a, int b, char op) {
        int x = find(a), y = find(b);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x,y);
        if (r[x] == r[y]) r[y]++;
        p[x] = y;
        if (op == 'O') J_OR(x,y);
        if (op == 'A') J_AND(x,y);
        if (op == 'X') J_XOR(x,y);
        return true;
    }
};

char typ[MAXN];
DS UF;
vi P[MAXN];

int dfs (int st) {
    for (auto &i : P[st]) i = dfs(i);
    
    if (typ[st] == 'E') return st;
    if (typ[st] != 'L') {
        UF.join(P[st][0],P[st][1],typ[st]);
        return P[st][0];
    }
    return -1;
}

int main() {
    int n; scanf("%d",&n);
    UF.init(n);
    
    scanf("%s",typ);

    forn(i,n) {
        int m; scanf("%d",&m);
        if (typ[i] == 'E')
            forn(j,m) {
                int x; scanf("%d",&x);
                UF.secs[i].insert(x);
            }
        else forn(j,m) {
            int x; scanf("%d",&x);
            P[i].pb(x);
        }
    }

    forn(i,n) {
        if (typ[i] == 'L') {
            dfs(i);
            int cmp = UF.find(P[i][0]);
            for (auto &j : UF.secs[cmp]) printf("%d ",j);
        }
        putchar('\n');
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!