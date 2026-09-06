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

int const MAXN = 3e5+5;

int mod;
int pot10[MAXN];

struct mon {
    int v,dig;
    mon(){v = 0; dig = 0;};
    mon(int vv) : v(vv){dig = 1;}
    mon(int vv, int digg) : v(vv), dig(digg){};

    mon operator+ (const mon &o) const {
        return mon(((v * (ll)pot10[o.dig])%mod + o.v)%mod, dig+o.dig);
    }
};

#define NEUT mon()
struct STree { // segment tree for min over integers
	vector<mon> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void init(int k, int s, int e, int *a){
		if(s+1==e){st[k]=mon(a[s]);return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=st[2*k]+st[2*k+1];
	}
	void upd(int k, int s, int e, int p, int v){
		if(s+1==e){st[k]=mon(v);return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=st[2*k]+st[2*k+1];
	}
	mon query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return query(2*k,s,m,a,b)+query(2*k+1,m,e,a,b);
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int p, int v){upd(1,0,n,p,v);}
	mon query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);


int vals[MAXN];

vi dominando(string n, int d, vi t, vi a, vi b) {
    mod = d;
    pot10[0] = 1;
    forsn(i,1,MAXN) pot10[i] = (10LL * pot10[i-1])%mod;

    forn(i,sz(n)) vals[i] = (n[i]-'0')%mod;

    STree rmq(sz(n));
    rmq.init(vals);

    vi rta;
    forn(i,sz(t)) {
        if (!t[i]) {
            --a[i];
            rta.pb(rmq.query(a[i],b[i]).v);
        }
        else {
            --a[i];
            rmq.upd(a[i],b[i]%mod);
        }
    }
    return rta;
}
