#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <cstring>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);
#define bint __int128

using namespace std;
using ll = long long;
using pii = pair<int, int>;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long double ld;

int const K = 20;
int const INF = 1e9;

int F[K][1<<K],D[1<<K];
vi g[1<<K]; int n;
bool tk[1<<K];
int fat[1<<K];
int szt[1<<K];

int dcent[1<<K],cand[1<<K];

int ret[1<<K];

int calcsz(int x, int f) {
    szt[x] = 1;
    for(auto y:g[x])if(y!=f&&!tk[y])szt[x]+=calcsz(y,x);
    return szt[x];
}
void cdfs(int x=0, int f=-1, int sz=-1) {
    if(sz<0)sz=calcsz(x,-1);
    for(auto y:g[x])if(!tk[y]&&szt[y]*2>=sz) {
        szt[x]=0;cdfs(y,f,sz);return;
    }
    tk[x]=true;fat[x]=f;
    for(auto y:g[x])if(!tk[y])cdfs(y,x);
}
void centroid(){
    memset(tk,false,sizeof(tk));
    cdfs();
}

void lca_dfs(int x) {
    forsn(i,0,g[x].size()) {
        int y=g[x][i];if(y==F[0][x])continue;
        F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
    }
}
void lca_init(){
    D[0]=0;F[0][0]=-1;
    lca_dfs(0);
    forsn(k,1,K)forsn(x,0,n)
        if (F[k-1][x]<0)F[k][x]=-1;
        else F[k][x]=F[k-1][F[k-1][x]];
}
int lca (int x, int y) {
    if(D[x]<D[y])swap(x,y);
    for(int k=K-1;k>=0;--k)if(D[x]-(1<<k)>=D[y])x=F[k][x];
    if (x==y) return x;
    for(int k=K-1;k>=0;--k)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];
    return F[0][x];
}

int dis (int u, int v) {
    int p = lca(u,v);
    return D[u]+D[v]-2*D[p];
}

void update (int x) {
    int cur = x;
    while (cur != -1) {
        int dist = dis(x,cur);
        if (dist < dcent[cur]) {
            dcent[cur] = dist;
            cand[cur] = x;
        }
        else if (dist == dcent[cur] && cand[cur] > x)
            cand[cur] = x;

        cur = fat[cur];
    }
}

int getmini (int x) {
    int cur = x;
    int rta = INF, chosen = -1;
    while (cur != -1) {
        if (cand[cur] != -1) {
            int dist = dis(cand[cur],x);
            if (dist < rta) {
                rta = dist; chosen = cand[cur];
            }
            else if (dist == rta && chosen > cand[cur])
                chosen = cand[cur];
        }
        cur = fat[cur];
    }
    return chosen;
}

int main() {
    FAST_IO;

    cin >> n;
    forn(i,n-1) {
        int u,v; cin >> u >> v; --u, --v;
        g[u].pb(v), g[v].pb(u);
    }

    forn(i,n) cand[i] = -1, dcent[i] = INF;
    centroid();
    lca_init();

    dforn(i,n) {
        int auxi = getmini(i);
        if (auxi == -1) ret[i] = i;
        else ret[i] = auxi;
        update(i);
    }

    forn(i,n) cout << ret[i]+1 << ' ';
    cout << '\n';

    return 0;
}
