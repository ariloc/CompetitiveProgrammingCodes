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

const int MAXN = 1e5+5;

struct edges {
    int v; ll w;

    bool operator< (const edges &o) const{
        return w > o.w;
    }
};

void fastscan (int &x) {
    int c; x = 0;
    c=getchar_unlocked();
    for(; c>='0' && c<='9'; c=getchar_unlocked())
        x = 10*x + c-'0';
}

vector<edges> G[MAXN];
int pass[MAXN];
vector<ll> rta;

void dijkstra (int st, int nd, int k) {
    priority_queue<edges> Q;
    Q.push({st,0});

    while (not Q.empty()) {
        auto e = Q.top(); Q.pop();

        if (e.v == nd) rta.pb(e.w);
        if ((int)rta.size() >= k) break;
        if (pass[e.v] >= k) continue;
        pass[e.v]++;

        for (auto &i : G[e.v])
            if (pass[i.v] < k) Q.push({i.v,e.w+i.w});
    }
}

int main() {
    int n,m,k; fastscan(n); fastscan(m); fastscan(k);
    forn(i,m) {
        int u,v,w; fastscan(u); fastscan(v); fastscan(w); u--; v--;
        G[u].pb({v,w});
    }

    dijkstra(0,n-1,k);
    forn(i,k) printf("%lld ",rta[i]);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
