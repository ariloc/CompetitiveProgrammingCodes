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

int const MAXN = 1e5+5;
int const MAXQ = 1e5+5;
int const K = 18;

struct edge {
    int v,w;
};

vector<edge> G[MAXN];
int num[MAXN];

int ft[MAXN], lt[MAXN], tt[2*MAXN];
int prox = 0;
void tour (int st) {
    ft[st] = prox;
    tt[prox++] = st;

    for (auto &i : G[st])
        if (ft[i.v] == -1) {
            tour(i.v);
            num[i.v] = i.w;
        }

    lt[st] = prox;
    tt[prox++] = st;
}

int nt,sq,nq;
struct qu{int l,r,lca,id;};
qu qs[MAXQ];
int ans[MAXQ];
bool qcomp(const qu &a, const qu &b){
    if(a.l/sq!=b.l/sq) return a.l<b.l;
    return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}

struct STree {
	vector<int> st;int n;
	STree(int n): st(4*n+5,0), n(n) {}
    STree(){}
	void upd(int k, int s, int e, int p, int v){
		if(s+1==e){st[k]+=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=st[2*k]+st[2*k+1];
	}
    int lookup (int k, int l, int r) {
        if (r-l <= 1) return l;
        int m = (l+r)/2;
        if (st[2*k] < m-l) return lookup(2*k,l,m);
        return lookup(2*k+1,m,r);
    }
	ii query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return {0,-1};
		if(s>=a&&e<=b) {
            if (st[k] < e-s) return {st[k],lookup(k,s,e)};
            return {st[k],-1};
        }

        int m = (s+e)/2;
        ii lr = query(2*k,s,m,a,b);

        if (lr.snd == -1) {
            ii rr = query(2*k+1,m,e,a,b);
            return {lr.fst+rr.fst, rr.snd};
        }

        return lr;
	}
	void upd(int p, int v){upd(1,0,n,p,v);}
	int query(int a, int b){return query(1,0,n,a,b).snd;}
};

int cnt[MAXN],cntval[MAXN];
STree rmq;

void process(int i) {
    if (num[i] == -1) return;
    if (num[i] >= MAXN) return;
    if (cnt[i]%2 == 0) {
        cntval[num[i]]--;
        if (!cntval[num[i]]) rmq.upd(num[i],-1);
    }
    else {
        if (!cntval[num[i]]) rmq.upd(num[i],1);
        cntval[num[i]]++;
    }
}

void add(int i) {
    cnt[tt[i]]++;
    process(tt[i]);
}

void remove(int i) {
    cnt[tt[i]]--;
    process(tt[i]);
}

int get_ans(qu que) {
    if (que.lca != -1 || num[tt[que.l]] == -1 || num[tt[que.l]] >= MAXN || cntval[num[tt[que.l]]] > 1)
        return rmq.query(0,MAXN);

    rmq.upd(num[tt[que.l]],-1);
    int r = rmq.query(0,MAXN);
    rmq.upd(num[tt[que.l]],1);
    return r;
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

int n;
int F[K][1<<K],D[1<<K];
void lca_dfs(int x){
	forn(i,G[x].size()){
		int y=G[x][i].v;if(y==F[0][x])continue;
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

    forn(i,n-1) {
        int u,v,x; cin >> u >> v >> x; --u, --v;
        G[u].pb({v,x}), G[v].pb({u,x});
    }

    forn(i,n) ft[i] = num[i] = -1;
    tour(0);

    lca_init();

    forn(i,nq) {
        int u,v; cin >> u >> v; --u, --v;

        int l = lca(u,v);

        if (u == l) qs[i] = {ft[u], ft[v]+1, -1};
        else if (v == l) qs[i] = {ft[v], ft[u]+1, -1};
        else if (lt[u] < ft[v]) qs[i] = {lt[u], ft[v]+1, l};
        else qs[i] = {lt[v], ft[u]+1, l};
    }

    rmq = STree(MAXN);
    nt = prox;
    mos();

    forn(i,nq) cout << ans[i] << '\n';

    return 0;
}
