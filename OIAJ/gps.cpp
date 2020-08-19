#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ll> vll;

const int MAXN = 1002;

struct nodo {
    ll v,d;

    bool operator< (const nodo &o) const{
        return o.d < d;
    }
};

vector<nodo> G[MAXN];
int pasadas[MAXN];
vll caminos;

void antiDijkstra (int st, int nd, int K) {
    priority_queue<nodo> Q;
    Q.push({st,0});

    while (not Q.empty()) {
        auto x = Q.top(); Q.pop();

        if (x.v == nd) {
            caminos.push_back(x.d);
            if (caminos.size() >= K) break;
        }

        if (pasadas[x.v] >= K) continue;
        pasadas[x.v]++;

        for (auto &w : G[x.v])
            Q.push({w.v,  (x.d + w.d)});
    }
}

vector<long long> gps(int N, int M, int comienzo, int fin, int K, vector<int> origen, vector<int> destino, vector<int> tiempo)
{
    forn (i,M)
        G[origen[i]-1].push_back({destino[i]-1,tiempo[i]});

    antiDijkstra(comienzo-1,fin-1,K);

    return caminos;
}
