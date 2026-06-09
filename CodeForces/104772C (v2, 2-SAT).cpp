#include<bits/stdc++.h>

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
bitset<MAXN> done;
vi percol[MAXN];

vi G[MAXN];

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

void dfs2(int st, int p = -1) {
    done[st] = true;
    
    if (p != -1) G2[st].pb(p), G2[neg(p)].pb(neg(st));

    for (auto &i : G[st]) 
        if (!done[i])
            dfs2(i,st);
}

vi go(int rt, int N) {
    forn(i,2*N) done[i] = false;
    forn(i,4*N) G2[i].clear();

    n = 2*N;
    dfs2(rt);

    forn(i,N) {
        int a = percol[i][0], b = percol[i][1];
        addor(a,b);
        addor(neg(a),neg(b));
    }

    if (!satisf())
        return {};

    vi ret;
    forn(i,2*N) if (truth[i]) ret.pb(i);
    return ret;
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

        vi rta;
        for (auto &i : percol[0]) {
            vi r = go(i,N);
            if (!r.empty()) {rta = r; break;}
        }

        if (rta.empty()) cout << "-1\n";
        else {
            for (auto &i : rta) cout << i+1 << ' ';
            cout << '\n';
        }
    }

    return 0;
}
