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
int const MAXG = 5e5+5;
int const MAXK = 320;
int const INF = 2e9;

struct vertex {
	map<char,int> next,go;
	int p,link;
	char pch;
	vector<int> leaf;
    int len,lastleaf;
	vertex(int p=-1, char pch=-1, int len=0):p(p),pch(pch),link(-1),len(len),lastleaf(-1){}
};
vector<vertex> t;
void aho_init(){ //do not forget!!
	t.clear();t.pb(vertex());
}
void add_string(string s, int id){
	int v=0;
	for(char c:s){
		if(!t[v].next.count(c)){
			t[v].next[c]=t.size();
			t.pb(vertex(v,c,t[v].len+1));
		}
		v=t[v].next[c];
	}
	t[v].leaf.pb(id);
}
int go(int v, char c);
int get_link(int v){
	if(t[v].link<0) {
		if(!v||!t[v].p)t[v].link=0;
		else t[v].link=go(get_link(t[v].p),t[v].pch);
    }
	return t[v].link;
}
int get_lastleaf(int v) {
    if (t[v].lastleaf<0){
        if (!v||!t[v].p)t[v].lastleaf=0;
        else {
            int link = get_link(v);
            t[v].lastleaf = t[link].leaf.empty() ? get_lastleaf(link) : link;
        }
    }
    return t[v].lastleaf;
}
int go(int v, char c){
	if(!t[v].go.count(c)) {
		if(t[v].next.count(c))t[v].go[c]=t[v].next[c];
		else t[v].go[c]=v==0?0:go(get_link(v),c);
    }
	return t[v].go[c];
}

vector<ii> queries[MAXN];
int rta[MAXQ];
int minipos[MAXN],bk[MAXN];
int block[MAXK];

int main() {
    FAST_IO;

    string s; cin >> s;
    int n = sz(s);

    aho_init();

    int g; cin >> g;
    forn(i,g) {
        string ge; cin >> ge;
        add_string(ge,i+1);
    }

    int q; cin >> q;
    forn(i,q) {
        int l,r; cin >> l >> r; --l, --r;
        queries[r].pb({l,i});
    }

    forn(i,n) minipos[i] = INF, bk[i] = i/MAXK;
    forn(i,MAXK) block[i] = INF;

    int cur = 0;
    forn(i,n) {
        cur = go(cur,s[i]);
        int gcur = cur;
        // at most 1000 jumps, since each one jumps to a different length (1+2+...+1000 = 5e5)
        while (gcur > 0) { 
            if (!t[gcur].leaf.empty()) {
                int id = t[gcur].leaf.back();
                int pos = i-t[gcur].len+1;
                minipos[pos] = min(minipos[pos],id);
                block[bk[pos]] = min(block[bk[pos]],id);
            }
            gcur = get_lastleaf(gcur); // ensure to dif length with only leaves
        }

        for (auto &e : queries[i]) {
            int ret = INF;
            if (bk[e.fst] == bk[i]) forsn(j,e.fst,i+1) ret = min(ret,minipos[j]);
            else {
                int lb = e.fst/MAXK + 1, rb = i/MAXK - 1;
                int l = lb*MAXK, r = (rb+1)*MAXK-1; 
                forsn(j,e.fst,l) ret = min(ret,minipos[j]);
                forsn(j,lb,rb+1) ret = min(ret,block[j]);
                forsn(j,r+1,i+1) ret = min(ret,minipos[j]);
            }
            rta[e.snd] = ret == INF ? -1 : ret;
        }
    }

    forn(i,q) cout << rta[i] << '\n';

    return 0;
}
