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

int const MAXE = 1005;
int const MAXD = 4005;
int const MAXDEG = 25;
int const MAXN = MAXDEG*MAXE + 2*MAXD;

int lim[MAXE];
vi g[MAXN];

int n,mt[MAXN],qh,qt,q[MAXN],ft[MAXN],bs[MAXN];
bool inq[MAXN],inb[MAXN],inp[MAXN];
int lca(int root, int x, int y){
	memset(inp,0,sizeof(inp));
	while(1){
		inp[x=bs[x]]=true;
		if(x==root)break;
		x=ft[mt[x]];
	}
	while(1){
		if(inp[y=bs[y]])return y;
		else y=ft[mt[y]];
	}
}
void mark(int z, int x){
	while(bs[x]!=z){
		int y=mt[x];
		inb[bs[x]]=inb[bs[y]]=true;
		x=ft[y];
		if(bs[x]!=z)ft[x]=y;
	}
}
void contr(int s, int x, int y){
	int z=lca(s,x,y);
	memset(inb,0,sizeof(inb));
	mark(z,x);mark(z,y);
	if(bs[x]!=z)ft[x]=y;
	if(bs[y]!=z)ft[y]=x;
	forsn(x,0,n)if(inb[bs[x]]){
		bs[x]=z;
		if(!inq[x])inq[q[++qt]=x]=true;
	}
}
int findp(int s){
	memset(inq,0,sizeof(inq));
	memset(ft,-1,sizeof(ft));
	forsn(i,0,n)bs[i]=i;
	inq[q[qh=qt=0]=s]=true;
	while(qh<=qt){
		int x=q[qh++];
		for(int y:g[x])if(bs[x]!=bs[y]&&mt[x]!=y){
			if(y==s||mt[y]>=0&&ft[mt[y]]>=0)contr(s,x,y);
			else if(ft[y]<0){
				ft[y]=x;
				if(mt[y]<0)return y;
				else if(!inq[mt[y]])inq[q[++qt]=mt[y]]=true;
			}
		}
	}
	return -1;
}
int aug(int s, int t){
	int x=t,y,z;
	while(x>=0){
		y=ft[x];
		z=mt[y];
		mt[y]=x;mt[x]=y;
		x=z;
	}
	return t>=0;
}
int edmonds(){ // O(n^2 m)
	int r=0;
	memset(mt,-1,sizeof(mt));
	forsn(x,0,n)if(mt[x]<0)r+=aug(x,findp(x));
	return r;
}

int main() {
    FAST_IO;

    int e,d; cin >> e >> d;
    forn(i,e) cin >> lim[i];

    int cnt = e*MAXDEG;
    forn(i,d) {
        int u,v; cin >> u >> v; --u, --v;
        forn(j,lim[u]) 
            g[e*j+u].pb(cnt), g[cnt].pb(e*j+u);
        forn(k,lim[v])
            g[cnt+1].pb(e*k+v), g[e*k+v].pb(cnt+1);
        g[cnt].pb(cnt+1), g[cnt+1].pb(cnt);
        cnt += 2;
    }

    n = cnt;
    edmonds();

    int r = 0;
    for (int i = e*MAXDEG; i < cnt; i += 2)
        r += (mt[i] != -1 && mt[i+1] != -1 && mt[i] != i+1);

    cout << r << '\n';

    return 0;
}
