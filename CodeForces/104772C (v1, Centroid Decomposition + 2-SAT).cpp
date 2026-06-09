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

int dep[MAXN], col[MAXN];
bitset<MAXN> done, blocked;
vi percol[MAXN];

vi G[MAXN];
bool taken[MAXN];//poner todos en FALSE al principio!!
int padre[MAXN];//padre de cada nodo en el centroid tree

int szt[MAXN];
void calcsz(int v, int p) {
	szt[v] = 1;
	forall(it,G[v]) if (*it!=p && !taken[*it])
		calcsz(*it,v), szt[v]+=szt[*it];
}
void centroid(int v=0, int f=-1, int lvl=0, int tam=-1) {//O(nlogn)
	if(tam==-1)	calcsz(v, -1), tam=szt[v];
	forall(it, G[v]) if(!taken[*it] && szt[*it]>=tam/2)
		{szt[v]=0; centroid(*it, f, lvl, tam); return;}
	taken[v]=true;
	padre[v]=f;
	forall(it, G[v]) if(!taken[*it])
		centroid(*it, v, lvl+1, -1);
}


int dfs(int st) {
    if (padre[st] == -1)
        return dep[st] = 0;
    if (dep[st] != -1)
        return dep[st];

    return dep[st] = dfs(padre[st])+1;
}



vi G2[2*MAXN];
int stTime[2*MAXN], cmp[2*MAXN], posTopSort[2*MAXN];
bitset<2*MAXN> matched, truth;
int prox_libre = 1, actTime = 0, pos = 0;
int n,m;

#define addor(a, b) (G2[neg(a)].pb(b), G2[neg(b)].pb(a))

vi pila;
int tarjan (int st) { // SCC con Tarjan
    stTime[st] = actTime++;
    pila.pb(st);

    int mini = actTime-1;
    for (auto &i : G2[st]) {
        if (stTime[i] == -1) mini = min(mini,tarjan(i));
        if (!matched[i]) mini = min(mini,stTime[i]);
    }

    if (mini >= stTime[st])
        while (not pila.empty()) {
            int e = pila.back(); pila.pop_back();
            cmp[e] = prox_libre; matched[e] = true;

            posTopSort[e] = pos++;

            if (e == st) {prox_libre++; break;}
        }

    return mini;
}

int neg(int i) {return i >= n ? i-n : i+n;}

bool satisf() {
    pila.clear();
    prox_libre = 1;
    actTime = pos = 0;
    forn(i,2*n+2) stTime[i] = -1, matched[i] = false;
    forn(i,2*n) if(stTime[i] == -1) tarjan(i);

    forn(i,n) {
        if (cmp[i] == cmp[neg(i)]) return false;
        truth[i] = posTopSort[i] < posTopSort[neg(i)];
    }
    return true;
}

vi seen;
vector<ii> edges;
void dfs2(int st, int p = -1) {
    done[st] = true;
    
    seen.pb(st);

    if (p != -1) edges.pb({st,p});

    for (auto &i : G[st]) 
        if (!done[i] && !blocked[i])
            dfs2(i,st);
}

vi go(vi &rts, int N) {
    forn(i,2*N) done[i] = false;
    forn(i,4*N) G2[i].clear();

    for (auto &v : rts) {
        seen.clear();
        edges.clear();

        dfs2(v);
        set<int> cols;
        for (auto &i : seen) cols.insert(col[i]);
        if ((int)cols.size() < N) continue;

        sort(all(seen));
        seen.erase(unique(all(seen)), seen.end());
        n = (int)seen.size();

        for (auto &e : edges) {
            int ia = lower_bound(all(seen),e.fst)-seen.begin();
            int ib = lower_bound(all(seen),e.snd)-seen.begin();
            G2[ia].pb(ib);
            G2[neg(ib)].pb(neg(ia));
        }

        forn(i,N) {
            int a = percol[i][0], b = percol[i][1];
            int ia = lower_bound(all(seen),a)-seen.begin();
            int ib = lower_bound(all(seen),b)-seen.begin();
            if (!blocked[a] && !blocked[b]) {
                addor(ia,ib);
                addor(neg(ia),neg(ib));
            }
            else if (!blocked[a]) {
                addor(ia,ia);
            }
            else if (!blocked[b]) {
                addor(ib,ib);
            }
            else return {};
        }

        if (!satisf())
            return {};

        vi ret;
        forn(i,n) if (truth[i]) ret.pb(seen[i]);
        return ret;
    }
    return {};
}

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(_,t) {
        int N; cin >> N;
        forn(i,N) percol[i].clear();
        forn(i,2*N) {
            int x; cin >> x;
            col[i] = x;
            percol[x-1].pb(i);
        } 

        forn(i,2*N) G[i].clear();
        forn(i,2*N-1) {
            int u,v; cin >> u >> v; --u, --v;
            G[u].pb(v), G[v].pb(u);
        }

        forn(i,2*N) padre[i] = -1, taken[i] = false;
        centroid();

        forn(i,2*N) dep[i] = -1;
        int maxdep = 0;
        forn(i,2*N) if (dep[i] == -1) maxdep = max(maxdep, dfs(i));

        vector<vi> lvl(maxdep+1,(vi){});
        forn(i,2*N) lvl[dep[i]].pb(i), blocked[i] = false;

        vi rta;
        forn(i,maxdep+1) {
            vi r = go(lvl[i],N);
            if (!r.empty()) {
                rta = r; break;
            }
            for (auto &j : lvl[i]) {
                blocked[j] = true;
            }
        }

        if (rta.empty()) cout << "-1\n";
        else {
            for (auto &i : rta) cout << i+1 << ' ';
            cout << '\n';
        }
    }

    return 0;
}
