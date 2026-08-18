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

int const MAXN = 2e5+5;

struct op {
    int f; // set to f
    int dec; // set to dec, dec-1, dec-2, ...

    bool operator==(const op &o) const {return f == o.f && dec == o.f;}
};

op const NEUTL = {-1,-1};
int const INF = 2e9;

struct STree { // example: range sum with range addition
	vector<int> st;int n;
    vector<op> lazy;
	STree(int n): st(4*n+5,0), lazy(4*n+5,NEUTL), n(n) {}
	void push(int k, int s, int e){
		if(lazy[k] == NEUTL)return; // if neutral, nothing to do
        if(lazy[k].f) st[k] = max(st[k],lazy[k].f);
        if(lazy[k].dec) st[k] = max(st[k],lazy[k].dec);
        int mid = (s+e)/2;
        int dif = mid-s;
		if(s+1<e){
            if (lazy[k].f != -1) {
                lazy[2*k].f = max(lazy[2*k].f,lazy[k].f);
                lazy[2*k+1].f = max(lazy[2*k+1].f,lazy[k].f);
            }
            if (lazy[k].dec != -1) {
                lazy[2*k].dec = max(lazy[2*k].dec,lazy[k].dec);
                lazy[2*k+1].dec = max(lazy[2*k+1].dec,lazy[k].dec - dif);
            }
		}
		lazy[k]=NEUTL;
	}
	void upd(int k, int s, int e, int a, int b, const int typ, const int v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
            if (!typ) lazy[k].f = max(lazy[k].f,v);
            else lazy[k].dec = max(lazy[k].dec, v - (s-a));
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,typ,v);upd(2*k+1,m,e,a,b,typ,v);
		st[k]=max(st[2*k],st[2*k+1]);
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return -INF;
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return max(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(int a, int b, int typ, int v){upd(1,0,n,a,b,typ,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
};

struct state {int len,link;map<char,int> next;}; //clear next!!
state st[2*MAXN+10];
int sz,last;
void sa_init(){
	last=st[0].len=0;sz=1;
	st[0].link=-1;
}
void sa_extend(char c){
	int k=sz++,p;
	st[k].len=st[last].len+1;
	for(p=last;p!=-1&&!st[p].next.count(c);p=st[p].link)st[p].next[c]=k;
	if(p==-1)st[k].link=0;
	else {
		int q=st[p].next[c];
		if(st[p].len+1==st[q].len)st[k].link=q;
		else {
			int w=sz++;
			st[w].len=st[p].len+1;
			st[w].next=st[q].next;st[w].link=st[q].link;
			for(;p!=-1&&st[p].next[c]==q;p=st[p].link)st[p].next[c]=w;
			st[q].link=st[k].link=w;
		}
	}
	last=k;
}

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    string a; cin >> a;

    sa_init();

    forn(i,m) {
        string s; cin >> s;
        for (auto &j : s) sa_extend(j);
        sa_extend('#');
    }

    STree rmq(2*sz(a)+5);

    int v = 0, l = 0;
    forn(i,2*n) {
        char c = a[i%n];
        while (v && !st[v].next.count(c)) {
            v = st[v].link;
            l = st[v].len;
        }
        if (st[v].next.count(c)) {
            v = st[v].next[c];
            l++;
        }

        int il = max(0,i-n+1);
        rmq.upd(il,i-l+1,0,l);
        rmq.upd(i-l+1,i+1,1,l);
    }

    int mini = INF;
    forn(i,n) mini = min(mini,rmq.query(i,i+1));

    cout << mini << '\n';

    return 0;
}
