#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const INF = 2e9+5;

struct Dinic{
    int nodes,src,dst;
    vector<int> dist,q,work;
    struct edge {int to,rev;ll f,cap;};
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
                edge &e=g[u][i];int v=g[u][i].to;
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
                if(df>0){e.f+=df;g[v][e.rev].f-=df;return df;}
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

int n,m;
vector<ii> edges, posibedges;

bool posib(int mid) {
    Dinic d(n+m+2);
    forn(i,n) d.add_edge(0, i+1, mid);
    forn(i,m) {
        d.add_edge(edges[i].fst, n+i+1, 1);
        d.add_edge(edges[i].snd, n+i+1, 1);
        d.add_edge(n+i+1, n+m+1, 1);
    }
    if (d.max_flow(0,n+m+1) != m)
        return false;
    posibedges.clear();
    forn(i,n) {
        for (auto &e : d.g[i+1])
            if (e.f > 0 && e.to >= n+1) {
                ii edge = edges[e.to-n-1];
                int ot = edge.fst == i+1 ? edge.snd : edge.fst;
                posibedges.pb({i+1, ot});
            }
    }
    return true;
}

int main() {
    FAST_IO;

    cin >> n >> m;

    forn(i,m) {
        int x,y; cin >> x >> y;
        edges.pb({x,y});
    }

    int low = -1, high = n;
    while (high - low > 1) {
        int mid = (high+low)/2;
        if (posib(mid)) high = mid;
        else low = mid;
    }

    posib(high);

    cout << high << '\n';
    for (auto &e : posibedges)
        cout << e.fst << ' ' << e.snd << '\n';

    return 0;
}
