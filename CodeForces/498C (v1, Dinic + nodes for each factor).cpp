#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const INF = 2e9;
int const MAXN = 105;

struct Dinic{
	int nodes,src,dst;
	vector<int> dist,q,work;
	struct edge {int to,rev;ll f,cap;};
	vector<vector<edge>> g;
	Dinic(int x):nodes(x),g(x),dist(x),q(x),work(x){}
	void add_edge(int s, int t, ll cap){
		g[s].pb((edge){t,(int)g[t].size(),0,cap});
		g[t].pb((edge){s,(int)g[s].size()-1,0,0});
	}
	bool dinic_bfs(){
		fill(all(dist),-1);dist[src]=0;
		int qt=0;q[qt++]=src;
		for(int qh=0;qh<qt;qh++){
			int u=q[qh];
			forsn(i,0,g[u].size()){
				edge &e=g[u][i];int v=g[u][i].to;
				if(dist[v]<0&&e.f<e.cap)dist[v]=dist[u]+1,q[qt++]=v;
			}
		}
		return dist[dst]>=0;
	}
	ll dinic_dfs(int u, ll f){
		if(u==dst)return f;
		for(int &i=work[u];i<(int)g[u].size();i++){
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

vi fac[MAXN];
int arr[MAXN];

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,n) cin >> arr[i];

    forn(i,n) {
        int x = arr[i];
        for (int j = 2; j*j <= x; j++)
            while (!(x % j)) fac[i].pb(j), x /= j;
        if (x > 1) fac[i].pb(x);
    }

    Dinic d(30*n+2);
    forn(_,m) {
        int a,b; cin >> a >> b; --a, --b;
        if (a&1) swap(a,b);
        forn(i,fac[a].size()) forn(j,fac[b].size())
            if (fac[a][i] == fac[b][j])
                d.add_edge(30*a+i,30*b+j,1);
    }

    forn(j,30*n) {
        int i = j/30;
        if (i&1) d.add_edge(j,30*n+1,1);
        else d.add_edge(30*n,j,1);
    }

    cout << d.max_flow(30*n,30*n+1) << '\n';
    
    return 0;

}
