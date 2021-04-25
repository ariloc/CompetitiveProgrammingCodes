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

int cost[MAXN],pages[MAXN],dp[MAXN];

int main() {
    FAST_IO;

    int n,x; cin >> n >> x;
    forn(i,n) cin >> cost[i];
    forn(i,n) cin >> pages[i];

    dp[0] = 0;
    forn(i,n) dforsn(j,cost[i],x+1)
        dp[j] = max(dp[j],dp[j-cost[i]]+pages[i]);

    int maxi = 0;
    forn(i,x+1) maxi = max(maxi,dp[i]);
    cout << maxi;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
