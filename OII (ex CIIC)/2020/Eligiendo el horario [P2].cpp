#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

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

const int MAXN = 2e5+5;

struct edges {
    int v; ll w,i,f;
};

struct dijkEdge {
    int v; ll w;

    bool operator< (const dijkEdge &o) const{
        return w < o.w;
    }
};

vector<edges> G[MAXN];
int N,M; ll L;
ll D[MAXN],passD[MAXN];

ll dijkstra(int st) {
    priority_queue<dijkEdge> Q;
    D[st] = L; Q.push({st,L});

    while (not Q.empty()) {
        auto ele = Q.top(); auto e = ele.v; Q.pop();
        if ((passD[e] != -1 and passD[e] >= ele.w) or ele.w < D[e]) continue;
        passD[e] = ele.w;

        if (!e) break; // conseguí llegar

        for (auto &i : G[e]) {
            ll arrival = D[e] - i.w;
            if (arrival < 0 or i.i > arrival) continue;
            ll margin = (i.f ? (arrival-i.i)%i.f : 0);
            ll calc = arrival - margin;
            if (calc < 0) continue; // si me paso de llegar a casa

            if (D[i.v] == -1 or D[i.v] < calc) { // quiero aquel que llega antes
                D[i.v] = calc;
                Q.push({i.v,calc});
            }
        }
    }
    return D[0];
}

int main() {
    forn(i,MAXN) D[i] = passD[i] = -1; // reset

    scanf("%d %d %lld",&N,&M,&L);
    forn (i,M) {
        int A,B; ll T,I,F; scanf("%d %d %lld %lld %lld",&A,&B,&T,&I,&F);
        G[B].pb({A,T,I,F});
    }

    printf("%lld",max(-1LL,dijkstra(N-1)));

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
