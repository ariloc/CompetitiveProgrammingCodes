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

const int MAXN = 2005;

int dp[MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;

    forn(i,t) {
        memset(dp,-1,sizeof(dp));

        int n; cin >> n;
        int maxi = -1, ind = 0;
        vi blocks;

        forn(j,2*n) {
            int x; cin >> x;
            if (x > maxi) {
                if (maxi != -1) blocks.pb(j-ind);
                maxi = x; ind = j;
            }
        }

        dp[0] = 1;
        forn (j,blocks.size()) {
            for (int k = n; k >= blocks[j]; k--)
                dp[k] = max(dp[k-blocks[j]],dp[k]);
        }

        if (dp[n] != -1) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!