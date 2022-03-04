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
const ll INF = 9e18;

int arr[MAXN];
ll tad[MAXN];
vector<ll> dp[MAXN];

int main() {
    int t; scanf("%d",&t);
    forn(o,t) {
        int n; scanf("%d",&n);
        forn(i,n) scanf("%d",&arr[i]);
        forn(i,n+2) dp[i].clear(), tad[i] = 0; // reset

        forsn(i,1,n+1) tad[i] = arr[i-1];
        forsn(i,1,n+1) tad[i] += tad[i-1];

        dp[n-1].pb(arr[n-1]);
        int acc = 1, cnt = 1;
        dforn(i,n-1) {
            forn(j,cnt) dp[i].pb(dp[i+1][j]);
            if (n-i-cnt > acc) acc += ++cnt, dp[i].pb(-INF);
            dp[i][0] = max(dp[i][0], (ll)arr[i]);
            forsn(j,1,cnt) {
                ll s = tad[i+j+1]-tad[i];
                if (dp[i+j+1][j-1] > s) dp[i][j] = max(dp[i][j], s);
            }
        }

        int maxk = 1;
        forn(i,dp[0].size())
            if (dp[0][i] != -INF) maxk = i+1;

        printf("%d\n",maxk);
    }

    return 0;
}