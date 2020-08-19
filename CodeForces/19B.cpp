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
const ll INF = 1e18+5;

pair<ll,ll> arr[MAXN];
ll dp[MAXN];

int main() {
    FAST_IO;

    forn(i,MAXN) dp[i] = INF;

    int n; cin >> n;

    forn (i,n) {
        int t,c; cin >> t >> c;
        arr[i] = {t,c};
    }

    dp[0] = 0;
    forn (i,n) dforn(j,n+1)
        if (j-arr[i].fst-1 >= 0) dp[j] = min(dp[j],dp[j-arr[i].fst-1] + arr[i].snd);
        else dp[j] = min(dp[j],arr[i].snd);

    cout << dp[n];
    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!