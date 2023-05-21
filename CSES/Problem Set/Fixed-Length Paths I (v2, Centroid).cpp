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
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;
 
const int MAXN = 2e5+5;
 
int N,K;
vi G[MAXN];
bitset<MAXN> dones, centroid, donec, donesolve, donecnt;
int branch[MAXN], cur[MAXN], nb = 0, nc = 0;
 
int cent = -1;
ll rta = 0;
 
vi pass;
int find_centroid (int st, int n) {
    donec[st] = true;
    pass.pb(st);
    
    int s = 0;
    bool posib = true;
    for (auto &i : G[st]) {
        if (!donec[i] && !centroid[i]) {
            int aux = find_centroid(i,n);
            s += aux;
            if (aux > n/2) posib = false;
        }
    }
    if (n-s-1 > n/2) posib = false;
 
    if (posib) cent = st;
 
    return s+1;
}
 
void dfs (int st, int lvl = 0) {
    dones[st] = true;
    pass.pb(st);
 
    if (lvl) {
        branch[lvl]++;
        if (nb <= lvl) nb = lvl+1;
    }
 
    for (auto &i : G[st]) {
        if (!dones[i] && !centroid[i]) {
            dfs(i, lvl+1);
 
            if (!lvl) {
                forn(j,nb) 
                    if (K-j >= 0)
                        rta += (ll)branch[j] * cur[K-j];
 
                forn(j,nb)
                    cur[j] += branch[j], branch[j] = 0;
 
                nc = max(nc, nb);
                nb = 0;
            }
        }
    }
}
 
int dfs2 (int st) {
    donecnt[st] = true;
    pass.pb(st);
 
    int ret = 1;
    for (auto &i : G[st])
        if (!donecnt[i] && !centroid[i])
            ret += dfs2(i);
 
    return ret;
}
 
void reset(bitset<MAXN> &toReset) {
    for (auto &i : pass) toReset[i] = 0;
    pass.clear();
}
 
void solve (int st) {
    int n = dfs2(st);
    reset(donecnt);
 
    find_centroid(st,n);
    reset(donec);
 
    forn(i,nc) cur[i] = 0;
    cur[0] = 1, nc = 1;
 
    dfs(cent);
    reset(dones);
 
    centroid[cent] = true;
 
    for (auto &i : G[cent])
        if (!centroid[i])
            solve(i);
}
 
int main() {
    scanf("%d %d",&N,&K);
    forn(i,N-1) {
        int u,v; scanf("%d %d",&u,&v), u--, v--;
        G[u].pb(v), G[v].pb(u);
    }
 
    solve(0);
 
    printf("%lld",rta);
    
    return 0;
}
