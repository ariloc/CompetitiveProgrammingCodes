#include<bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define sz(c) (int)(c).size()
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef long double ld;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

int const INF = 2e9+5;
int const MAXN = 1e5+5;
int const MAXT = 2*MAXN;
int const MAXST = 1<<(32-__builtin_clz(MAXT));

struct mon {
    int v, pos;
    mon(){};
    mon (int v, int pos) : v(v), pos(pos){};
    mon operator+ (const mon &o) const {
        if (v >= o.v) return *this;
        return o;
    }
};

mon NEUT = mon(-1,-1);

mon ST[2*MAXST];
int N;

void upd(int p, int r) {
    p += N;
    if (r < 0) ST[p] = NEUT;
    else ST[p] = {r,p-N};
    while (p > 1) p /= 2, ST[p] = ST[2*p] + ST[2*p+1];
}

mon query2(int i, int bl, int br, int geq, int tl, int tr) {
    if (tr-tl <= 1) {
        if (ST[i].v >= geq) return ST[i];
        return NEUT;
    }
    int mid = (tl+tr)/2;
    if (2*i < 2*MAXST && ST[2*i].v >= geq) return query2(2*i,bl,br,geq,tl,mid);
    return query2(2*i+1,bl,br,geq,mid,tr);
}

mon op(const mon &lhs, const mon &rhs) {
    if (lhs.v != -1) return lhs;
    return rhs;
}

mon query(int i, int bl, int br, int geq, int tl = 0, int tr = N) {
    if (tl >= br || tr <= bl) return NEUT;
    if (bl <= tl && tr <= br) return query2(i,bl,br,geq,tl,tr);
    //cerr << i << ' ' << bl << ' ' << br << ' ' << geq << ' ' << tl << ' ' << tr << endl;
    int mid = (tl+tr)/2;
    return op(query(2*i,bl,br,geq,tl,mid),query(2*i+1,bl,br,geq,mid,tr));
}

mon query(int l, int r, int geq) {return query(1,l,r,geq);}

struct rang {
    int s,f,t;
    bool isbus;
    int id;

    bool operator< (const rang &o) const {
        if (s != o.s) return s < o.s;
        return isbus > o.isbus;
    }
};

vi ts;
vector<rang> ra;
int rta[MAXN];
int busmap[MAXT];

void update (int &x, vi &vec) {
    x = lower_bound(all(vec),x)-vec.begin();
}

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,n) {
        int s,f,t; cin >> s >> f >> t;
        ts.pb(t);
        ra.pb({s,f,t,true,i});
    }

    forn(i,m){
        int s,f,t; cin >> s >> f >> t;
        ts.pb(t);
        ra.pb({s,f,t,false,i});
    }

    sort(all(ts));
    ts.erase(unique(all(ts)),ts.end());

    for (auto &i : ra) {
        update(i.t,ts);
        if (i.isbus) busmap[i.t] = i.id;
    }

    sort(all(ra));

    N = 1<<(32-__builtin_clz(sz(ts)+5));
    forn(i,N) ST[i+N] = NEUT;
    dforsn(i,1,N) ST[i] = ST[2*i] + ST[2*i+1];

    priority_queue<ii, vector<ii>, greater<ii>> todel;
    for (auto &i : ra) {
        while (!todel.empty() && (todel.top()).fst < i.s) {
            auto e = todel.top(); todel.pop();
            upd(e.snd,-1);
        }
        if (i.isbus) {
            upd(i.t,i.f);
            todel.push({i.f,i.t});
            //cerr << "OKI" << ' ' << i.s << ' ' << i.f << ' ' << i.t << ' ' << ts[i.t] << endl;
        }
        else {
            mon ret = query(i.t,sz(ts)+1,i.f);
            //cerr << ts[i.t] << ' ' << i.s << ' ' << i.f << endl;
            if (ret.pos == -1) rta[i.id] = -1;
            else rta[i.id] = busmap[ret.pos]+1;
        }
    }

    forn(i,m) cout << rta[i] << ' ';
    cout << '\n';

    return 0;
}
