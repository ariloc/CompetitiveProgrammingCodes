#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

struct edges {
    int v; ll w;

    bool operator< (const edges &o) const{
        return o.w < w;
    }
};

const int MAXN = 1e5+5;

vector<edges> G[MAXN];
bitset<MAXN> done;
ll D[MAXN];

void dijsktra(int st) {
    priority_queue<edges> Q;
    Q.push({st,0}); D[st] = 0;

    while (not Q.empty()) {
        auto e = Q.top().v; Q.pop();
        if (done[e]) continue;
        done[e] = true;

        for (auto &i : G[e]) {
            if (D[i.v] == -1 or D[i.v] > D[e] + i.w) {
                D[i.v] = D[e] + i.w;
                Q.push({i.v,D[i.v]});
            }
        }
    }
}

int main() {
    //FAST_IO;

    memset(D,-1,sizeof(D));

    int n,m; scanf("%d %d",&n,&m);

    forn (i,m) {
        int a,b,w; scanf("%d %d %d",&a,&b,&w); a--; b--;
        G[a].pb({b,w});
    }

    dijsktra(0);

    forn(i,n) printf("%lld ",D[i]);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
