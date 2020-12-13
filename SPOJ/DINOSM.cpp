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

const int MAXN = 310;

struct edges  {
    int v; double w;

    bool operator< (const edges &o) const {
        return w > o.w;
    }
};

vector<edges> G[MAXN];
double D[MAXN];

void dijkstra (int st) {
    priority_queue<edges> Q; D[st] = 0;
    Q.push({st,0});

    while (!Q.empty()) {
        auto e = Q.top().v; Q.pop();
        for (auto &i : G[e]) {
            if (D[i.v] == -1 || D[i.v] > max(D[e],i.w)) {
                D[i.v] = max(D[e],i.w);
                Q.push({i.v,D[i.v]});
            }
        }
    }
}

int main() {
    FAST_IO;

    int N,W,H;
    while(cin >> N >> W >> H) {
        if (N == -1) break;
        forn(j,N+2) G[j].clear(), D[j] = -1;
        vector<ii> past = {{0,H},{W,0}};
        forn(i,N) {
            int x,y; cin >> x >> y;
            past.pb({x,y});
        }
        forsn(i,2,past.size()) forsn(j,i+1,past.size()) {
            double v = hypot(abs(past[i].fst-past[j].fst),abs(past[i].snd-past[j].snd))/(double)2;
            G[i].pb({j,v});
            G[j].pb({i,v});
        }
        forsn(i,2,past.size()) {
            G[0].pb({i,min(abs((double)H-past[i].snd),(double)past[i].fst)});
            G[i].pb({0,min(abs((double)H-past[i].snd),(double)past[i].fst)});
            G[1].pb({i,min((double)past[i].snd,(double)abs(W-past[i].fst))});
            G[i].pb({1,min((double)past[i].snd,(double)abs(W-past[i].fst))});
        }

        dijkstra(0);
        cout << fixed << setprecision(3) << D[1] << '\n';
    }

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
