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
const int INF = 2e9;
 
void fs (int &x) {
    x = 0;
    int c; c = getchar();
    if (c < '0' || c > '9') c = getchar();
    for(; c >= '0' && c <= '9'; c = getchar())
        x = 10*x + c-'0';
}
 
int n,k;
ll rta = 0;
 
struct DS {
    vi p,r;
    vector<map<int,int>> cmp;
 
    void init(int N) {
        p.assign(N,0);
        r.assign(N,0);
        cmp.assign(N,{});
        forn(i,N) p[i] = i;
    }
 
    int find (int x) {return p[x] == x ? x : p[x] = find(p[x]);}
 
    void merge (map<int,int> &a, map<int,int> &b) {
        int minDep = INF; // el menor es el del nodo que quiero que pasen
        if (!a.empty()) minDep = min(minDep,(*a.begin()).fst);
        if (!b.empty()) minDep = min(minDep,(*b.begin()).fst);
 
        for (auto &i : b) // count
            if (a.count(k-i.fst+2*minDep)) rta += a[k-i.fst+2*minDep]*(ll)i.snd;
 
        for (auto &i : b) a[i.fst] += i.snd; // join
    }
 
    bool join (int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x,y);
        p[x] = y; merge(cmp[y],cmp[x]);
        if (r[x] == r[y]) r[y]++;
        return true;
    }
};
 
vi G[MAXN];
bitset<MAXN> done;
DS UF;
 
void dfs1 (int st, int lvl) {
    done[st] = true;
    UF.cmp[st][lvl]++;
 
    for (auto &i : G[st]) 
        if (!done[i]) {
            dfs1(i,lvl+1);
            UF.join(st,i);
        }
}
 
int main() {
    fs(n), fs(k);
    
    UF.init(n+2);
 
    forn(i,n-1) {
        int u,v; fs(u), fs(v); u--, v--;
        G[u].pb(v), G[v].pb(u);
    }
 
    dfs1(0,0);
 
    printf("%lld",rta);
 
    return 0;
}
 
/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!