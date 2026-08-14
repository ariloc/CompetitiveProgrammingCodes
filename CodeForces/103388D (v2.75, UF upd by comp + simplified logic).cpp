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

int const MAXN = 5e5+5;

struct edge {
    int u,v,w;
};

vector<edge> edges;
vi we;
vector<ii> byw[MAXN];

void update (int &x) {
    x = lower_bound(all(we),x)-we.begin();
}

struct DS {
    vi p,r,col;
    void init(int n) {
        p.assign(n,0);
        r.assign(n,0);
        col.assign(n,0);
        forn(i,n) p[i] = i;
    }
    ii find(int x) {
        if (p[x] == x) return {x,col[x]};
        ii aux = find(p[x]);
        col[x] = col[x]^aux.snd; p[x] = aux.fst;
        return {p[x],col[x]};
    }
    bool join(int a, int b) {
        ii x = find(a), y = find(b);
        if (x.fst == y.fst) { // only false if no longer bipartite
            if (x.snd == y.snd) return false;
            return true;
        }
        if (r[x.fst] > r[y.fst]) swap(x,y);
        p[x.fst] = y.fst;
        if (x.snd == y.snd) col[x.fst] ^= 1;
        if (r[x.fst] == r[y.fst]) r[y.fst]++;
        return true;
    }
};

DS UF;

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,m) {
        int x,y,b; cin >> x >> y >> b; --x, --y;
        edges.pb({x,y,b});
        we.pb(b);
    }

    UF.init(n);

    sort(all(we));
    we.erase(unique(all(we)),we.end());

    for (auto &i : edges) update(i.w);
    for (auto &i : edges) byw[i.w].pb({i.u,i.v});

    vi rta;
    bool cont = true;
    dforn(i,sz(we)) {
        bool ok = false;

        set<int> exts;
        int cnt = 0;
        map<int,int> seenode;
        for (auto &j : byw[i]) {
            ii a1 = UF.find(j.fst), a2 = UF.find(j.snd);
            if (a1.fst == a2.fst && a1.snd != a2.snd)
                continue;
            int ex1 = 2*a1.fst+a1.snd, ex2 = 2*a2.fst+a2.snd;

            int su = seenode[ex1] + (ex1 != ex2 ? seenode[ex2] : 0);
            if (su < cnt) ok = true;

            seenode[ex1]++;
            if (ex1 != ex2) seenode[ex2]++;
            ++cnt;
        }

        if (ok) rta.pb(i);

        for (auto &j : byw[i]) if(!UF.join(j.fst,j.snd)) cont = false;
        if (!cont) break;
    }

    reverse(all(rta));

    if (!cont && rta.empty()) cout << "IMPOSSIBLE\n";
    else {
        if (cont) cout << "0\n";
        for (auto &i : rta) cout << we[i] << '\n';
    }
    
    return 0;
}
