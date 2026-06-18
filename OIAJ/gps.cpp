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
typedef pair<ll,int> li;
typedef vector<li> vli;

const int MAXN = 1002;

vli G[MAXN];
int pasadas[MAXN];
vll caminos;

void antiDijkstra (int st, int nd, int K) {
    priority_queue<li,vli,greater<li>> Q;
    Q.push({0,st});

    while (not Q.empty()) {
        auto x = Q.top(); Q.pop();

        if (pasadas[x.snd] >= K) continue;
        pasadas[x.snd]++;

        if (x.snd == nd) {
            caminos.push_back(x.fst);
            if ((int)caminos.size() >= K) break;
        }

        for (auto &w : G[x.snd])
            if (pasadas[w.snd] < K)
                Q.emplace((x.fst + w.fst), w.snd);
    }
}

vector<long long> gps(int N, int M, int comienzo, int fin, int K, vector<int> origen, vector<int> destino, vector<int> tiempo)
{
    forn (i,M)
        G[origen[i]-1].emplace_back(tiempo[i],destino[i]-1);

    antiDijkstra(comienzo-1,fin-1,K);

    return caminos;
}
