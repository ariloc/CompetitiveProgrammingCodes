#include<bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 1e5+5;
int const MAXM = 2e5+5;

struct edge {
    int v,c;
};

int p[MAXN];
int tin[MAXN], actT = 1;
bitset<MAXN> matched;
vi G[MAXN], G2[MAXN];
int comp[MAXN], comps = 0;
int indeg[MAXN];
ll sum_comp[MAXN], dp[MAXN];

vi pila;
int tarjan (int st) {
    tin[st] = actT++;
    pila.pb(st);

    int mini = tin[st];
    for (auto &i : G[st]) {
        if (!tin[i]) mini = min(mini, tarjan(i));
        if (!matched[i]) mini = min(mini, tin[i]);
    }

    if (mini >= tin[st]) {
        while (!pila.empty()) {
            auto e = pila.back(); pila.pop_back();
            matched[e] = true;
            comp[e] = comps;
            sum_comp[comps] += p[e];
            if (e == st) {comps++; break;}
        }
    }

    return mini;
}


int main() {
    FAST_IO;

    int n,m; cin >> n >> m;

    forn(i,n) cin >> p[i];

    forn(i,m) {
        int x,y; cin >> x >> y; --x, --y;
        G[x].pb(y);
    }

    forn(i,n) if (!tin[i]) tarjan(i);

    // condensed
    forn(i,n) for (auto &j : G[i]) if (comp[i] != comp[j]) G2[comp[i]].pb(comp[j]), indeg[comp[j]]++;

    ll maxi = 0;

    // toposort
    queue<int> Q;
    forn(i,comps) if (!indeg[i]) Q.push(i);
    while (!Q.empty()) {
        auto v = Q.front(); Q.pop();
        dp[v] += sum_comp[v];
        maxi = max(maxi,dp[v]);
        for (auto &i : G2[v]) {
            dp[i] = max(dp[i], dp[v]);
            if (!(--indeg[i])) {
                Q.push(i);
            }
        }
    }

    cout << maxi << '\n';

    return 0;
}
