#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

int const MAXN = 2e5+5;

int caps[MAXN];
ll dp[MAXN];

struct STree {
	vector<ll> st,lazy,lazyfill; int n;
	STree(int n): st(4*n+5,0), lazy(4*n+5,-2), n(n){}
	void init(int k, int s, int e, ll *a) {
		lazy[k] = -2;
		if(s+1==e){st[k]=a[s];}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=st[2*k]+st[2*k+1];
	}
	void push(int k, int s, int e){
		if(lazy[k]==-2)return;
		if (lazy[k] >= 0) st[k]=lazy[k];
		else st[k] = dp[e]-dp[s];
		if(s+1<e){
			lazy[2*k]=lazy[k];
			lazy[2*k+1]=lazy[k];
		}
		lazy[k]=-2;
	}
	void upd(int k, int s, int e, int a, int b, ll v) {
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]=v;
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v),upd(2*k+1,m,e,a,b,v);
		st[k]=st[2*k]+st[2*k+1];
	}
	ll query(int k, int s, int e, int a, int b) {
		if(s>=b||e<=a) return 0;
		push(k,s,e);
		if(s>=a&&e<=b) return st[k];
		int m=(s+e)/2;
		return query(2*k,s,m,a,b)+query(2*k+1,m,e,a,b);
	}
	void init(ll *a){init(1,0,n,a);}
	void upd(int a, int b, ll v){upd(1,0,n,a,b,v);}
	ll query(int a, int b){return query(1,0,n,a,b);}
};

int main() {
	FAST_IO;
	
	int n,m; cin >> n >> m;
	
	forn(i,n) cin >> caps[i];
	forn(i,n) dp[i+1] = dp[i] + caps[i];
	
	STree rmq(n);
	forn(i,m) {
		int op; cin >> op;
		if (op == 1) {
			int b; ll v; cin >> b >> v; --b;
			int lo = 0, hi = b+2;
			while (hi-lo > 1) {
				int mid = (hi+lo)/2;
				if ((dp[b+1]-dp[b+1-mid]) - rmq.query(b+1-mid,b+1) >= v) hi = mid;
				else lo = mid;
			}
			//cerr << b+1-lo << ' ' << b+1 << "!!" << endl;
			//cerr << (dp[b+1]-dp[b+1-lo]) << ' ' << rmq.query(b+1-lo,b+1) <<  endl;
			ll r = v - ((dp[b+1]-dp[b+1-lo]) - rmq.query(b+1-lo,b+1));
			rmq.upd(b+1-lo,b+1,-1);
			//cerr << r << ' ' << b-lo << ' ' << "!!!!" << endl;
			if (r && lo <= b) {
				ll cur = rmq.query(b-lo,b-lo+1);
				rmq.upd(b-lo,b-lo+1,cur+r);
			}
		}
		else {
			int l,r; cin >> l >> r; --l;
			cout << rmq.query(l,r) << '\n';
			rmq.upd(l,r,0);
		}
	}
	
	return 0;
}
