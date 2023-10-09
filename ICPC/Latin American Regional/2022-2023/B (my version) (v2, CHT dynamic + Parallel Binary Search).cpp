#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 1e5+5;
int const MAXB = 17;

typedef ll tc;
const tc is_query=-(1LL<<62); // special value for query
struct Line {
	tc m,b;
	mutable multiset<Line>::iterator it,end;
	const Line* succ(multiset<Line>::iterator it) const {
		return (++it==end? NULL : &*it);}
	bool operator<(const Line& rhs) const {
		if(rhs.b!=is_query)return m<rhs.m;
		const Line *s=succ(it);
		if(!s)return 0;
		return b-s->b<(s->m-m)*rhs.m;
	}
};
struct HullDynamic : public multiset<Line> { // for maximum
	bool bad(iterator y){
		iterator z=next(y);
		if(y==begin()){
			if(z==end())return false;
			return y->m==z->m&&y->b<=z->b;
		}
		iterator x=prev(y);
		if(z==end())return y->m==x->m&&y->b<=x->b;
		return (x->b-y->b)*(z->m-y->m)>=(y->b-z->b)*(y->m-x->m);
	}
	iterator next(iterator y){return ++y;}
	iterator prev(iterator y){return --y;}
	void add(tc m, tc b){
		iterator y=insert((Line){m,b});
		y->it=y;y->end=end();
		if(bad(y)){erase(y);return;}
		while(next(y)!=end()&&bad(next(y)))erase(next(y));
		while(y!=begin()&&bad(prev(y)))erase(prev(y));
	}
	tc eval(tc x){
		Line l=*lower_bound((Line){x,is_query});
		return l.m*x+l.b;
	}
};


vector<ii> tok;
vector<Line> lines;
ii querying[MAXN];
vi toCheck[MAXN];
HullDynamic cht;
vi rta[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int x,y; cin >> x >> y;
        tok.pb({x,y});
    }
    int p; cin >> p;
    forn(i,p) {
        int a,b; cin >> a >> b;
        lines.pb({a,b});
    }

    forn(i,t) querying[i] = {-1,p};
    forn(_,MAXB) {
        cht = HullDynamic();
        forn(i,t) {
            int l,r; tie(l,r) = querying[i];
            if (r-l > 1) {
                int mid = (l+r)/2;
                toCheck[mid].pb(i);
            }
        }
        forn(i,p) {
            cht.add(lines[i].m,lines[i].b);
            
            for (auto &j : toCheck[i]) {
                if (cht.eval(tok[j].fst) > tok[j].snd) querying[j].snd = i;
                else querying[j].fst = i;
            }

            toCheck[i].clear();
        }
    }

    forn(i,t) if (querying[i].snd != p) rta[querying[i].snd].pb(i);

    forn(i,p) {
        cout << (int)rta[i].size() << ' ';
        for (auto &j : rta[i]) cout << j+1 << ' ';
        cout << '\n';
    }
  
    return 0;
}
