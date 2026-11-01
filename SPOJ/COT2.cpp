#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 4e4+5;
int const MAXQ = 1e5+5;
int const K = 17;

int w[MAXN];
vi G[MAXN];
int tt[2*MAXN],ft[MAXN],lt[MAXN];
int prox = 0;
bitset<MAXN> done;
ii queries[MAXQ];
int cnt[MAXN];
int byval[MAXN];
int uniq = 0;
vi we;

void tour(int st) {
    done[st] = true;
    ft[st] = prox;
    tt[prox] = st;
    lt[st] = prox++;

    for (auto &i : G[st])
        if (!done[i]) {
            tour(i);
        }

    tt[prox] = st;
    lt[st] = prox++;
}



int nt,sq,nq;
struct qu{int l,r,llca,id;};
qu qs[MAXQ];
int ans[MAXQ];

void change(int v) {
    if (cnt[v]%2 == 0) {
        byval[w[v]]--;
        if (!byval[w[v]]) uniq--;
    }
    else {
        if (!byval[w[v]]) uniq++;
        byval[w[v]]++;
    }
}

void add(int i) {
    int v = tt[i];
    cnt[v]++;
    change(v);
}

void remove(int i) {
    int v = tt[i];
    cnt[v]--;
    change(v);
}

int get_ans(qu que) {
    int r = uniq;
    if (que.llca != -1 && !byval[w[que.llca]]) r++;
    return r;
}

bool qcomp(const qu &a, const qu &b){
    if(a.l/sq!=b.l/sq) return a.l<b.l;
    return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}
void mos(){
    forn(i,nq)qs[i].id=i;
    sq=sqrt(nt)+.5;
    sort(qs,qs+nq,qcomp);
    int l=0,r=0;
    forn(i,nq){
        qu q=qs[i];
        while(l>q.l)add(--l);
        while(r<q.r)add(r++);
        while(l<q.l)remove(l++);
        while(r>q.r)remove(--r);
        ans[q.id]=get_ans(q);
    }
}

int F[K][1<<K],D[1<<K];
int n;
void lca_dfs(int x){
	forn(i,G[x].size()){
		int y=G[x][i];if(y==F[0][x])continue;
		F[0][y]=x;D[y]=D[x]+1;lca_dfs(y);
	}
}
void lca_init(){
	D[0]=0;F[0][0]=-1;
	lca_dfs(0);
	forsn(k,1,K)forn(x,n)
		if(F[k-1][x]<0)F[k][x]=-1;
		else F[k][x]=F[k-1][F[k-1][x]];
}
int lca(int x, int y){
	if(D[x]<D[y])swap(x,y);
	for(int k=K-1;k>=0;--k)if(D[x]-(1<<k)>=D[y])x=F[k][x];
	if(x==y)return x;
	for(int k=K-1;k>=0;--k)if(F[k][x]!=F[k][y])x=F[k][x],y=F[k][y];
	return F[0][x];
}

int main() {
    FAST_IO;

    cin >> n >> nq;

    forn(i,n) cin >> w[i], we.pb(w[i]);

    sort(all(we));
    we.erase(unique(all(we)),we.end());

    forn(i,n) w[i] = lower_bound(all(we),w[i])-we.begin();

    forn(i,n-1) {
        int u,v; cin >> u >> v; --u, --v;
        G[u].pb(v), G[v].pb(u);
    }

    lca_init();

    tour(0);
    nt = prox;

    forn(i,nq) {
        int u,v; cin >> u >> v; --u, --v;
        int l = lca(u,v);
        if (l == u) qs[i] = {ft[u],ft[v]+1,-1};
        else if (l == v) qs[i] = {ft[v],ft[u]+1,-1};
        else if (lt[u] < ft[v]) qs[i] = {lt[u],ft[v]+1,l};
        else qs[i] = {lt[v],ft[u]+1,l};
    }

    mos();

    forn(i,nq) cout << ans[i] << '\n';

    return 0;
}
