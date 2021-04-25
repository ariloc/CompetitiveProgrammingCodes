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

const int MAXN = 1e5+5;
const int MOD = 1e9+7;

vi G[MAXN];
bitset<MAXN> done;
int dp[MAXN];

void dfs (int st) {
    done[st] = true;

    int sum = 0;
    for (auto &i : G[st]) {
        if (!done[i]) dfs(i);
        sum = (sum+dp[i])%MOD;
    }

    dp[st] = sum;
}

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,m) {
        int a,b; cin >> a >> b; a--; b--;
        G[a].pb(b);
    }
    dp[n-1] = 1; done[n-1] = true;

    dfs(0);
    cout << dp[0];

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
