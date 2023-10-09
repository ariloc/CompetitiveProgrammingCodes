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
int const MAXST = (1<<(32-__builtin_clz(MAXN)));
int const INF = 2e9;

typedef ll tc;
struct Line{tc m,h;};
struct CHT { // for minimum (for maximum just change the sign of lines)
	vector<Line> c;
	int pos=0;
	tc in(Line a, Line b){
		tc x=b.h-a.h,y=a.m-b.m;
		return x/y+(x%y?!((x>0)^(y>0)):0); // ==ceil(x/y)
	}
	void add(tc m, tc h){ // m's should be non increasing
		Line l=(Line){m,h};
		if(c.size()&&m==c.back().m){
			l.h=min(h,c.back().h);c.pop_back();if(pos)pos--;
		}
		while(c.size()>1&&in(c.back(),l)<=in(c[c.size()-2],c.back())){
			c.pop_back();if(pos)pos--;
		}
		c.pb(l);
	}
	inline bool fbin(tc x, int m){return in(c[m],c[m+1])>x;}
	tc eval(tc x){
		// O(log n) query:
		int s=0,e=c.size();
		while(e-s>1){int m=(s+e)/2;
			if(fbin(x,m-1))e=m;
			else s=m;
		}
		return c[s].m*x+c[s].h;
		// O(1) query (for ordered x's):
		while(pos>0&&fbin(x,pos-1))pos--;
		while(pos<c.size()-1&&!fbin(x,pos))pos++;
		return c[pos].m*x+c[pos].h;
	}
};

struct mon {
    CHT v;
    mon(){v = CHT();}

    mon operator+ (const mon &o) const {
        mon aux = mon();
        int l = 0, r = 0;
        while (l < (int)v.c.size() && r < (int)o.v.c.size()) {
            if (v.c[l].m > o.v.c[r].m) aux.v.add(v.c[l].m, v.c[l].h), l++;
            else aux.v.add(o.v.c[r].m, o.v.c[r].h), r++;
        }
        while (l < (int)v.c.size()) aux.v.add(v.c[l].m, v.c[l].h), l++;
        while (r < (int)o.v.c.size()) aux.v.add(o.v.c[r].m, o.v.c[r].h), r++;

        return aux;
    }
};

mon ST[2*MAXST];
int N;
vector<ii> tokens;
vi rta[MAXN];

int query (int i, ii tok, int tl = 0, int tr = N) {
    if (tr-tl <= 1) return i;

    int mid = (tl+tr)/2;
    if (ST[2*i].v.eval(tok.fst) < -tok.snd) return query(2*i,tok,tl,mid);
    return query(2*i+1,tok,mid,tr);
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(i,t) {
        int x,y; cin >> x >> y;
        tokens.pb({x,y});
    }
    int p; cin >> p;
    N = (1<<(32-__builtin_clz(p)));
    forn(i,p) {
        int a,b; cin >> a >> b;
        if (-a > 0) {
            ST[i+N].v.add(-a,-b);
            ST[i+N].v.add(0,INF);
        }
        else {
            ST[i+N].v.add(0,INF);
            ST[i+N].v.add(-a,-b);
        }
    }
    
    forsn(i,p,N) ST[i+N].v.add(0,INF);
    dforsn(i,1,N) ST[i] = ST[2*i] + ST[2*i+1];

    forn(i,t) {
        ii cur = tokens[i];
        int ind = query(1,cur);
        if ((int)ST[ind].v.c.size() == 1 && ST[ind].v.c[0].h == INF) continue;
        rta[ind-N].pb(i);
    }

    forn(i,p) {
        cout << (int)rta[i].size() << ' ';
        for (auto &j : rta[i]) cout << j+1 << ' ';
        cout << '\n';
    }

    return 0;
}
