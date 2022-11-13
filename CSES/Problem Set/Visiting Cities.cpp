#include <bits/stdc++.h>
#include <cstdio>
 
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
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

void fs (int &x) {
    x = 0;
    char c = getchar_unlocked();
    if (c < '0' || c > '9') c = getchar_unlocked();
    for (; c >= '0' && c <= '9'; c = getchar_unlocked()) {
        x = 10*x + c-'0';
    }
}
 
const int MAXN = 1e5+5;
 
struct edge {
    int v; ll w;
 
    bool operator< (const edge &o) const {
        return w > o.w;
    }
};
 
int n,m,s,t;
vector<edge> G[MAXN];
vi G2[MAXN];
ll D[MAXN];
vi P[MAXN];
bitset<MAXN> done;
 
void dijkstra (int st) {
    forn(i,n) D[i] = -1;
 
    priority_queue<edge> Q;
    Q.push({st,0});
    D[st] = 0;
 
    while (!Q.empty()) {
        auto e = Q.top().v; Q.pop();
 
        if (done[e]) continue;
        done[e] = true;
 
        for (auto &i : G[e]) {
            if (D[i.v] == -1 || D[i.v] > D[e] + i.w) {
                D[i.v] = D[e] + i.w;
                P[i.v].clear();
                Q.push({i.v, D[i.v]});
            }
            if (D[i.v] == D[e] + i.w) 
                P[i.v].pb(e);
        }
    }
}
 
bitset<MAXN> done2;
void dfs (int st) {
    done2[st] = true;
 
    for (auto &i : P[st]) {
        if (!done2[i]) dfs(i);
        G2[i].pb(st), G2[st].pb(i);
    }
}
 
 
int actT = 1;
int tin[MAXN];
bitset<MAXN> isArtic;
 
int artic (int st, int p = -1) {
    tin[st] = actT++;
 
    int mini = tin[st], child = 0;
    for (auto &i : G2[st]) {
        if (i == p) continue;
 
        int act_mini = tin[st];
        if (!tin[i]) {
            act_mini = min(act_mini, artic(i, st));
            child++;
 
            // if acá adentro porque tengo que evitar la inversa de los back edges (no dirigido)
            // p != -1 porque si es una sola componente, entonces no debería contarlo, luego veo raíz
            if (act_mini >= tin[st] && p != -1)
                isArtic[st] = true;
        }
 
        act_mini = min(act_mini, tin[i]);
        mini = min(mini, act_mini);
    }
 
    // caso raíz
    if (child > 1 && p == -1)
        isArtic[st] = true;
 
    return mini;
}
 
int main() {
    fs(n), fs(m);
 
    forn(i,m) {
        int u,v,w; fs(u), fs(v), fs(w), u--, v--;
        G[u].pb({v,w});
    }
 
    dijkstra(0);
    dfs(n-1);
 
    artic(0);
    isArtic[0] = isArtic[n-1] = true; // in this case, I'd always go through these
    
    vi rta;
    forn(i,n)
        if (isArtic[i]) rta.pb(i);
 
    printf("%d\n",(int)rta.size());
    for (auto &i : rta) printf("%d ", i+1);
 
    return 0;
}
