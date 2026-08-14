#include<bits/stdc++.h>
#include<cassert>

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

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
    vi p,r;
    vector<vi> nod;
    vector<bool> col;
    void init(int n) {
        p.assign(n,0);
        r.assign(n,0);
        nod.assign(n,{});
        col.assign(n,false);
        forn(i,n) p[i] = i, nod[i].pb(i);
    }
    int find(int x){return p[x] == x ? x : p[x] = find(p[x]);}
    void merge(int x, int y, bool flip) {
        for (auto &i : nod[x]) {
            if (flip) col[i] = !col[i];
            nod[y].pb(i);
        }
    }
    bool join(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) { // only false if no longer bipartite
            if (col[a] == col[b]) return false;
            return true;
        }
        if (r[x] > r[y]) swap(x,y);
        p[x] = y;
        merge(x,y,col[a] == col[b]);
        if (r[x] == r[y]) r[y]++;
        return true;
    }
};

DS UF;
vector<pair<int,ii>> conn2[MAXN];
bitset<MAXN> passed;

int seecomp[MAXN], cntcmp = 0;
int seenode[2][MAXN], cnt[2] = {0,0};
vi tracksee[2];
bitset<MAXN> marksee[2];

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
        
    auto inc = [&](ii ed, int idx) {
        ++cnt[idx], seenode[idx][ed.fst]++, seenode[idx][ed.snd]++;
        if (!marksee[idx][ed.fst]) marksee[idx][ed.fst] = true, tracksee[idx].pb(ed.fst);
        if (!marksee[idx][ed.snd]) marksee[idx][ed.snd] = true, tracksee[idx].pb(ed.snd);
    };
    auto clear = [&](int idx) {
        cnt[idx] = 0;
        for (auto &i : tracksee[idx]) marksee[idx][i] = false, seenode[idx][i] = 0;
        tracksee[idx].clear();
    };

    vi rta;
    bool cont = true;
    dforn(i,sz(we)) {
        vector<ii> safe;
        forn(j,sz(byw[i])) {
            ii cur = byw[i][j];
            if (UF.find(cur.fst) == UF.find(cur.snd) && UF.col[cur.fst] != UF.col[cur.snd])
                continue;
            safe.pb(cur);
        }
        
        bool ok = false;
    
        auto check = [&](ii ed, int idx) {
            int su = seenode[idx][ed.fst] + seenode[idx][ed.snd];
            if (su < cnt[idx]) ok = true;
        };

        vi exts;
        for (auto &j : safe) {
            int c1 = UF.find(j.fst), c2 = UF.find(j.snd);
            if (c1 > c2) swap(c1,c2), swap(j.fst, j.snd);
            conn2[c1].pb({c2,{j.fst,j.snd}});
            conn2[c2].pb({c1,{j.snd,j.fst}});

            // edges that do not share any comp
            int su = seecomp[c1] + (c1 != c2 ? seecomp[c2] : 0);
            if (su < cntcmp) ok = true;
            seecomp[c1]++;
            if (c1 != c2) seecomp[c2]++;
            cntcmp++;

            if (!passed[c1]) passed[c1] = true, exts.pb(c1);
            if (!passed[c2]) passed[c2] = true, exts.pb(c2);
        }

        for (auto &j : exts) sort(all(conn2[j]));

        // edges that share both comps
        auto go = [&](vector<ii> &vec) {
            vector<ii> p1,p2;
            for (auto &k : vec) if (UF.col[k.fst]) p2.pb(k); else p1.pb(k);

            clear(0);
            for (auto &k : p1) inc(k,0);
            for (auto &k : p2) check(k,0);
        };
        auto goconn = [&](int j, int l, int r) {
            vector<ii> eq,neq;
            forsn(k,l,r) {
                ii cur = conn2[j][k].snd;
                if (UF.col[cur.fst] == UF.col[cur.snd]) eq.pb(cur); else neq.pb(cur);
            }

            go(eq); go(neq);
        };
        for (auto &j : exts) {
            int idx = 0;
            forn(k,sz(conn2[j])) {
                if (k && conn2[j][k-1].fst != conn2[j][k].fst) {
                    goconn(j,idx,k);
                    idx = k;
                }
            }
            goconn(j,idx,sz(conn2[j]));
        }

        clear(0); clear(1);

        // edges that share only one comp
        for (auto &j : exts) {
            clear(0); clear(1);

            int idx = 0;
            forn(k,sz(conn2[j])) {
                if (k && conn2[j][k-1].fst != conn2[j][k].fst) {
                    forsn(l,idx,k) {
                        ii cur = conn2[j][l].snd;
                        if (UF.col[cur.fst]) inc(cur,1);
                        else inc(cur,0);
                    }
                    idx = k;
                }
                ii cur = conn2[j][k].snd;
                if (UF.col[cur.fst]) check(cur,0);
                else check(cur,1);
            }
        }

        clear(0); clear(1);
        for (auto &j : exts) {
            conn2[j].clear(), passed[j] = false;
            seecomp[j] = 0;
            cntcmp = 0;
        }

        if (ok) rta.pb(i);

        for (auto &j : byw[i]) if(!UF.join(j.fst,j.snd)) cont = false;
        if (!cont) break;
    }

    sort(all(rta));

    if (!cont && rta.empty()) cout << "IMPOSSIBLE\n";
    else {
        if (cont) cout << "0\n";
        for (auto &i : rta) cout << we[i] << '\n';
    }
    
    return 0;
}
