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
const int INF = 2e9+5;
const int MOD = 1e9+7;

struct edges {
    int a,b,w;

    bool operator< (const edges &o) const {
        return o.w > w;
    }
};

edges G[MAXN];
ll cntPerSet[MAXN];

struct DS {
    vi p,r;

    void init(int N) {
        p.assign(N+3,-1);
        r.assign(N+3,-1);
    }

    int find(int x) {return (p[x] == -1 ? x : p[x] = find(p[x]));}
    ll join (int &a, int &b) {
        int x = find(a), y = find(b);
        if (x == y) return 0;

        ll val = cntPerSet[y]*cntPerSet[x];
        if (r[x] < r[y]) swap(x,y);
        p[y] = x; cntPerSet[x] += cntPerSet[y];
        if (r[y] == r[x]) r[x]++;

        return val;
    }
};

DS UF;

int main() {
    //FAST_IO;

    int N; scanf("%d",&N);
    forn (i,MAXN) cntPerSet[i] = 1;
    UF.init(N);

    forn (i,N-1) {
        int a,b,w; scanf("%d %d %d",&a,&b,&w);
        a--; b--;
        G[i] = {a,b,w};
    }

    sort(G,G+N-1); // ordeno aristas por costo menor a mayor

    ll rta = 0;
    forn (i,N-1) {
        auto e = G[i];
        ll newComb = UF.join(e.a,e.b);
        rta = ((rta + (((newComb % MOD)*e.w) % MOD)) % MOD);
    }

    printf("%lld",((rta + MOD) % MOD));

    return 0;
}
