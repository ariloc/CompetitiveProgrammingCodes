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

const int MAXN = 1e5+2;

ll arr[MAXN],dp[MAXN],dpR[MAXN];

int main() {
    FAST_IO;

    int n,k; cin >> n >> k;
    ll sum = 0;
    forn(i,n) {cin >> arr[i]; sum += arr[i];}

    priority_queue<ii,vector<ii>,greater<ii>> Q;
    forn(i,min(k,n)) Q.push({arr[i],i});
    if (min(k,n) == k) dp[0] = Q.top().fst;
    forsn(i,1,n-k+1) {
        Q.push({arr[i+k-1],i+k-1});
        while (Q.top().snd < i) Q.pop();
        dp[i] = Q.top().fst;
    }

    ll maxi = 0;
    dforn(i,n) {
        if (i+k < n) dp[i] = dp[i]+dpR[i+k];
        maxi = max(dp[i],maxi);
        dpR[i] = maxi;
    }

    cout << sum-maxi;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
