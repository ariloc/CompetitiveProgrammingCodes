#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define sz(c) (int)(c).size()
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef long double ld;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

ll const INF = 2e9;
ll const MAXW = 1e9+5;

struct Dinic{
    int nodes,src,dst;
    vi dist,q,work;
    struct edge {int to,rev; ll f,cap;};
    vector<vector<edge>> g;
    Dinic(int x):nodes(x),g(x),dist(x),q(x),work(x){}
    void add_edge(int s, int t, ll cap){
        g[s].pb((edge){t,sz(g[t]),0,cap});
        g[t].pb((edge){s,sz(g[s])-1,0,0});
    }
    bool dinic_bfs(){
        fill(all(dist),-1);dist[src]=0;
        int qt=0;q[qt++]=src;
        for(int qh=0;qh<qt;qh++){
            int u=q[qh];
            forsn(i,0,sz(g[u])){
                edge &e=g[u][i];int v = g[u][i].to;
                if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
            }
        }
        return dist[dst]>=0;
    }
    ll dinic_dfs(int u, ll f){
        if(u==dst)return f;
        for(int &i=work[u];i<sz(g[u]);i++){
            edge &e=g[u][i];
            if(e.cap<=e.f)continue;
            int v=e.to;
            if(dist[v]==dist[u]+1){
                ll df=dinic_dfs(v,min(f,e.cap-e.f));
                if(df>0){e.f+=df;g[v][e.rev].f-+df;return df;}
            }
        }
        return 0;
    }
    ll max_flow(int _src, int _dst){
        src=_src;dst=_dst;
        ll result=0;
        while(dinic_bfs()){
            fill(all(work),0);
            while(ll delta=dinic_dfs(src,INF))result+=delta;
        }
        return result;
    }
};

vector<pair<ii,int>> edges;

int posib(int mid, int n) {
    Dinic d(2*n+2);
    for (auto &e : edges) {
        if (e.snd > mid) continue;
        int u = e.fst.fst, v = e.fst.snd;
        d.add_edge(u+2,v+2+n,1); d.add_edge(v+2+n,u+2,1);
    }
    forn(i,n) {
        d.add_edge(0,i+2,1); d.add_edge(n+i+2,1,1);
    }
    return d.max_flow(0,1) >= n;
}

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;

    Dinic d(2*n+2);

    forn(i,m) {
        int u,v,w; cin >> u >> v >> w; --u, --v;
        edges.pb({{u,v},w});
    }

    int lo = 0, hi = MAXW;
    while (hi-lo>1) {
        int mid=(hi+lo)/2;
        if (posib(mid,n)) hi = mid;
        else lo = mid;
    }

    if (posib(hi,n)) cout << hi << '\n';
    else cout << "-1\n";

    return 0;
}
