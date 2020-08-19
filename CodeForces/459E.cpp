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

const int MAXN = 6e5+5;
const int INF = 1e9+5;

struct edges {
    int a,b,w;

    bool operator< (const edges &o) const{
        return o.w > w;
    }
};

int dp[MAXN];
edges aristas[MAXN];

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;

    forn (i,m) {
        int a,b,w; cin >> a >> b >> w; a--; b--;
        aristas[i] = {a,b,w};
    }

    sort(aristas,aristas+m);

    forn (i,m) {
        vector<ii> changes; int ind = i;
        while (ind < m and aristas[ind].w == aristas[i].w) {
            changes.pb({aristas[ind].b,dp[aristas[ind].a]+1});
            ind++;
        }
        for (auto &o : changes) dp[o.fst] = max(dp[o.fst],o.snd);
        i = ind-1;
    }

    int maxi = 0;
    forn(i,n) maxi = max(maxi,dp[i]);

    cout << maxi;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!