#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define snd second
#define fst first
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

int const MAXN = 5e5+5;
int const MAXE = 2*MAXN + 5;
int const MAXST = 1<<(32-__builtin_clz(MAXE));
ll const INF = 2e15;

struct edge {
    int v;
    ll w;

    bool operator< (const edge &o) const {
        return w > o.w;
    }
};

vector<edge> G[MAXN];
ll D[MAXN];
int n,q;

void dijk(int st) {
    priority_queue<edge> Q;
    Q.push({st,0});
    fill(D,D+n,-1);
    D[st] = 0;

    while (!Q.empty()) {
        auto e = Q.top(); Q.pop();

        if (e.w != D[e.v]) continue;

        for (auto &i : G[e.v])
            if (D[i.v] == -1 || D[i.v] > D[e.v] + i.w) {
                D[i.v] = D[e.v] + i.w;
                Q.push({i.v,D[i.v]});
            }
    }
}

int T[MAXE], F[MAXE], L[MAXE];
bitset<MAXE> done, isleaf;
int prox_libre = 0;
void tour(int st) {
    T[prox_libre] = st;
    F[st] = prox_libre++;

    bool found = false;
    for (auto &i : G[st])
        if (F[i.v] == -1) tour(i.v), found = true;

    L[st] = prox_libre-1;
    if (!found) isleaf[st] = true;
}

struct mon {
    ll v;
    mon(){v = INF;}
    mon(ll vv) : v(vv){}

    mon operator+(const mon &o) const {
        return mon(min(v,o.v));
    }
};

mon ST[2*MAXST];
ll lazy[2*MAXST];
int N;

void passLazy(int i) {
    ST[i].v += lazy[i];
    if (2*i < 2*MAXST) lazy[2*i] += lazy[i];
    if (2*i+1 < 2*MAXST) lazy[2*i+1] += lazy[i];
    lazy[i] = 0;
}

void update (int i, int bl, int br, const ll v, int tl = 0, int tr = N) {
    passLazy(i);
    if (tl >= br || tr <= bl) return;
    if (tl >= bl && tr <= br) {
        lazy[i] += v;
        passLazy(i);
        return;
    }
    int mid = (tl+tr)/2;
    update(2*i,bl,br,v,tl,mid);
    update(2*i+1,bl,br,v,mid,tr);
    ST[i] = ST[2*i]+ST[2*i+1];
}

mon query (int i, int bl, int br, int tl = 0, int tr = N) {
    passLazy(i);
    if (tl >= br || tr <= bl) return mon();
    if (tl >= bl && tr <= br) return ST[i];

    int mid = (tl+tr)/2;
    return query(2*i,bl,br,tl,mid) + query(2*i+1,bl,br,mid,tr);
}

vector<pair<ii,int>> queries[MAXN];
ll rta[MAXN];

void go(int st) {
    done[st] = true;

    for (auto &i : queries[st]) {
        rta[i.snd] = query(1,i.fst.fst,i.fst.snd+1).v;
    }

    for (auto &i : G[st]) {
        if (!done[i.v]) {
            update(1,0,F[i.v],i.w);
            update(1,F[i.v],L[i.v]+1,-i.w);
            update(1,L[i.v]+1,N,i.w);

            go(i.v);

            update(1,0,F[i.v],-i.w);
            update(1,F[i.v],L[i.v]+1,i.w);
            update(1,L[i.v]+1,N,-i.w);
        }
    }
}

int main() {
    FAST_IO;

    cin >> n >> q;
    forn(i,n-1) {
        int p,w; cin >> p >> w; --p;
        G[i+1].pb({p,w}), G[p].pb({i+1,w});
    }

    forn(i,n) {
        sort(all(G[i]),[](const edge &lhs, const edge &rhs){
            return lhs.v < rhs.v;
        });
    }

    dijk(0);

    fill(F,F+MAXE,-1);
    tour(0);

    N = (1<<(32-__builtin_clz(prox_libre)));

    forn(i,prox_libre) if (isleaf[i]) ST[i+N].v = D[T[i]];
    dforsn(i,1,N) ST[i] = ST[2*i] + ST[2*i+1];

    forn(i,q) {
        int v,l,r; cin >> v >> l >> r; --l, --r, --v;
        queries[v].pb({{l,r},i});
    }

    done.reset();
    go(0);

    forn(i,q) cout << rta[i] << '\n';

    return 0;
}
