#include <algorithm>
#include <bits/stdc++.h>
 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);
 
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int MAXN = 1e5+5;
const int INF = 2e9;
const int MOD = 1e9+7;

vi G[MAXN];
int cost[MAXN];
int tin[MAXN], actT = 1, prox_libre = 0;
ii cmp_mini[MAXN];
bitset<MAXN> matched;

vi pila;
int tarjan (int st) {
    tin[st] = actT++;
    pila.pb(st);

    int mini = tin[st];
    for (auto &i : G[st]) {
        if (!tin[i]) mini = min(mini, tarjan(i));
        if (!matched[i]) mini = min(mini, tin[i]);
    }

    if (mini >= tin[st])
        while (!pila.empty()) {
            auto e = pila.back(); pila.pop_back();
            matched[e] = true;
            if (cost[e] < cmp_mini[prox_libre].fst) 
                cmp_mini[prox_libre] = {cost[e], 0};
            if (cost[e] == cmp_mini[prox_libre].fst)
                cmp_mini[prox_libre].snd++;
            if (e == st) {prox_libre++; break;}
        }

    return mini;
}

int main() {
    int n; scanf("%d", &n);
    forn(i,n) scanf("%d", &cost[i]);

    int m; scanf("%d", &m);
    forn(i,m) {
        int u,v; scanf("%d %d",&u,&v), u--, v--;
        G[u].pb(v);
    }

    forn(i,n) cmp_mini[i] = {INF, INF};
    forn(i,n) if (!tin[i]) tarjan(i);

    ll cost_min = 0;
    int posib = 1;
    forn(i,prox_libre) {
        cost_min += cmp_mini[i].fst;
        posib = (posib * (ll)cmp_mini[i].snd)%MOD;
    }

    printf("%lld %d", cost_min, posib);
 
    return 0;
}
