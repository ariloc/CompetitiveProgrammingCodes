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
int const BLOCK = 320;

vi G[MAXN];
int ft[MAXN],lt[MAXN],tt[2*MAXN];
int prox = 0;

void tour(int st) {
    ft[st] = prox;
    tt[prox++] = st;

    for (auto &i : G[st])
        if (ft[i] == -1)
            tour(i);

    lt[st] = prox-1;
}

int col[MAXN],bycol[MAXN],byam[MAXN],par[MAXN];
int blocks[BLOCK],ind[MAXN];

void add(int st) {
    int v = tt[st];
    byam[bycol[col[v]]]--;
    blocks[ind[bycol[col[v]]]]--;
    bycol[col[v]]++;
    byam[bycol[col[v]]]++;
    blocks[ind[bycol[col[v]]]]++;
}

void remove(int st) {
    int v = tt[st];
    byam[bycol[col[v]]]--;
    blocks[ind[bycol[col[v]]]]--;
    bycol[col[v]]--;
    byam[bycol[col[v]]]++;
    blocks[ind[bycol[col[v]]]]++;
}


int nt,sq,nq; // array size, sqrt(array size), #queries
struct qu{int l,r,k,id;};
qu qs[MAXN];
ll ans[MAXN]; // ans[i] = answer to ith query
bool qcomp(const qu &a, const qu &b){
    if(a.l/sq!=b.l/sq) return a.l<b.l;
    return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}

int get_ans(qu q) {
    int r = 0;
    int bl = q.k, br = MAXN-2;
    forsn(i,bl,min(MAXN,(ind[bl]+1)*BLOCK)) r += byam[i];
    forsn(i,ind[bl]+1,ind[br]) r += blocks[i];
    forsn(i,ind[br]*BLOCK,br) r += byam[i];

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


int main() {
    FAST_IO;

    int n,m; cin >> n >> m;

    forn(i,n) cin >> col[i];

    forn(i,n-1) {
        int u,v; cin >> u >> v; --u, --v;
        G[u].pb(v), G[v].pb(u);
    }

    fill(ft,ft+n,-1);
    tour(0);
    nt = prox;

    forn(i,MAXN) ind[i] = i/BLOCK;
    byam[0] = n;
    blocks[0] = n;

    nq = m;
    forn(i,nq) {
        int v,k; cin >> v >> k; --v;
        qs[i] = {ft[v],lt[v]+1,k};
    }

    mos();

    forn(i,nq) cout << ans[i] << '\n';

    return 0;
}
