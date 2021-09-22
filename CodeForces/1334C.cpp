#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define pb push_back
#define fst first
#define snd second
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 3e5+5;
const ll INF = 9e18;

pair<ll,ll> monst[2*MAXN];
ll dp[2*MAXN];

int main() {
    FAST_IO;

    int t; cin >> t;
    forn(o,t) {
        int n; cin >> n;
        forn(i,n) cin >> monst[i].fst >> monst[i].snd;
        forn(i,n) monst[i+n] = monst[i]; // duplico

        dp[0] = monst[0].fst;
        forsn(i,1,2*n) dp[i] = dp[i-1] + max(0LL,monst[i].fst - monst[i-1].snd);

        ll mini = dp[n-1];
        forn(i,n) mini = min(mini, dp[i+n-1] - dp[i-1] - max(0LL,monst[i].fst - monst[i-1].snd) + monst[i].fst);

        cout << mini << '\n';
    }

    return 0;
}