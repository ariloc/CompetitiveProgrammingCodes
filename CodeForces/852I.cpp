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
int const K = 18;

bitset<MAXN> boy;
int fav[MAXN];
vi G[MAXN];
int ft[MAXN],lt[MAXN],tt[2*MAXN];
int n;
int prox = 0;

void tour(int st) {
    ft[st] = prox;
    tt[prox++] = st;

    for (auto &i : G[st])
        if (ft[i] == -1)
            tour(i);

    lt[st] = prox;
    tt[prox++] = st;
}

int F[K][1<<K],D[1<<K];
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

int sq,nq;
struct qu{int l,r,lca,id;};
qu qs[MAXN];
ll ans[MAXN];

int cnt[MAXN][2];
bitset<MAXN> par;
ll rta[MAXN];
ll acc = 0;

void flip(int i) {
    par[i] = 1-par[i];
    if (par[i]&1) cnt[fav[i]][boy[i]]++;
    else cnt[fav[i]][boy[i]]--;

    acc -= rta[fav[i]];
    rta[fav[i]] = cnt[fav[i]][1] * (ll)cnt[fav[i]][0];
    acc += rta[fav[i]];
}

void add(int i) {
    flip(tt[i]);
}

void remove(int i) {
    flip(tt[i]);
}

ll get_ans(qu q) {
    if (q.lca == -1) return acc;
    add(ft[q.lca]);
    ll auxi = acc;
    remove(ft[q.lca]);
    return auxi;
}

bool qcomp(const qu &a, const qu &b){
    if(a.l/sq!=b.l/sq) return a.l<b.l;
    return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}
void mos(){
    forn(i,nq)qs[i].id=i;
    sq=sqrt(prox)+.5;
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

vi num;

int main() {
    FAST_IO;

    cin >> n;

    forn(i,n) {int x; cin >> x; boy[i] = x;}
    forn(i,n) cin >> fav[i], num.pb(fav[i]);

    sort(all(num));
    num.erase(unique(all(num)),num.end());

    forn(i,n) fav[i] = lower_bound(all(num),fav[i])-num.begin();

    forn(i,n-1) {
        int a,b; cin >> a >> b; --a, --b;
        G[a].pb(b), G[b].pb(a);
    }

    fill(ft,ft+n,-1);
    tour(0);

    lca_init();

    cin >> nq;
    forn(i,nq) {
        int a,b; cin >> a >> b; --a, --b;
        
        int l = lca(a,b);
        if (l == a) qs[i] = {ft[a],ft[b]+1,-1};
        else if (l == b) qs[i] = {ft[b],ft[a]+1,-1};
        else if (lt[a] < ft[b]) qs[i] = {lt[a],ft[b]+1,l};
        else qs[i] = {lt[b],ft[a]+1,l};
    }

    mos();

    forn(i,nq) cout << ans[i] << '\n';

    return 0;
}
