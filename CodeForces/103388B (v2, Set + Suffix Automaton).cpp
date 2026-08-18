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
int const INF = 2e9;

struct state {int len,link;map<char,int> next;}; //clear next!!
state st[2*MAXN];
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

struct quer {
    int v,idx;
    bool del;

    bool operator< (const quer &o) const {
        if (v != o.v) return v < o.v;
        if (idx != o.idx) return idx < o.idx;
        return del < o.del;
    }
    quer operator- () {
        return {v,idx,!del};
    }
};

set<quer> val, decs;
vector<quer> squery[MAXN];
vector<quer> decquery[MAXN];

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
        squery[il].pb({l,i,false});
        squery[i-l+1].pb({l,i,true});

        decquery[i-l+1].pb({l,i,false});
        decquery[i+1].pb({l,i,true});
    }

    int mini = INF;
    forn(i,n) {
        for (auto &j : squery[i]) {
            if (j.del) val.erase(-j);
            else val.insert(j);
        }
        
        for (auto &j : decquery[i]) {
            if (j.del) {
                int ppos = (-j.idx)-j.v+1;
                decs.erase({j.v+ppos,j.idx,false});
            }
            else decs.insert({j.v+i,j.idx,false});
        }

        mini = min(mini, max((val.empty() ? -INF : (*val.rbegin()).v), (decs.empty() ? -INF : (*decs.rbegin()).v-i)));
    }

    cout << mini << '\n';

    return 0;
}
