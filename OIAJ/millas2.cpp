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

struct edge {
    int v; ll d,m;

    bool operator< (const edge &o) const {
        if (d == o.d) return m > o.m;
        return d > o.d;
    }
};

vector<edge> G[MAXN];
pair<ll,ll> D[MAXN];
bitset<MAXN> done;

vector<long long> millas(int N, vector<int> &a, vector<int> &b, vector<int> &d, vector<int> &m) {
    int M = sz(a);
    forn(i,M) {
        --a[i], --b[i];
        G[a[i]].pb({b[i],d[i],m[i]});
    }
    fill(D,D+N,(ii){-1,-1});

    priority_queue<edge> Q;
    Q.push({0,0,0});
    D[0] = {0,0};
    while (!Q.empty()) {
        auto e = Q.top(); Q.pop();

        if (e.v == N-1) break;

        if (done[e.v]) continue;
        done[e.v] = true;

        for (auto &i : G[e.v]) {
            if (i.m >= 0) {
                if (D[i.v].fst == -1 || D[i.v].fst > D[e.v].fst || (D[i.v].fst >= D[e.v].fst && D[i.v].snd > D[e.v].snd + i.m)) {
                    D[i.v] = {D[e.v].fst, D[e.v].snd + i.m};
                    Q.push({i.v, D[i.v].fst, D[i.v].snd});
                }
            }
            else {
                if (D[i.v].fst == -1 || D[i.v].fst > D[e.v].fst + i.d) {
                    D[i.v] = {D[e.v].fst + i.d, D[e.v].snd};
                    Q.push({i.v, D[i.v].fst, D[i.v].snd});
                }
            }
        }
    }

    return {D[N-1].fst, D[N-1].snd};
}
