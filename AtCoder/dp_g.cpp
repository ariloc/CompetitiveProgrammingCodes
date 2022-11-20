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

vi G[MAXN];
int deg[MAXN], dp[MAXN];

int main() {
    int n,m; scanf("%d %d", &n, &m);
    forn(i,m) {
        int u,v; scanf("%d %d", &u, &v), u--, v--;
        G[u].pb(v);
        deg[v]++;
    }

    queue<int> Q;
    forn(i,n) if (!deg[i]) Q.push(i);
    cerr << endl;

    while (!Q.empty()) {
        auto e = Q.front(); Q.pop();

        for (auto &i : G[e]) {
            dp[i] = max(dp[i], dp[e] + 1);
            if (!(--deg[i])) Q.push(i);
        }
    }

    int maxi = 0;
    forn(i,n) maxi = max(maxi,dp[i]);

    printf("%d", maxi);

    return 0;
}

