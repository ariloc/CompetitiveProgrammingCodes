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

const int MAXN = 1e6+5;
const int MOD = 1e9+7;
const int INF = 1e9+5;

int dp[MAXN],arr[MAXN];

int main() {
    forn(i,MAXN) dp[i] = INF;

    int n,x; scanf("%d %d",&n,&x);
    dp[0] = 0;
    forn(i,n) scanf("%d",&arr[i]);
    forn(i,x+1) forn(j,n) if(i >= arr[j]) dp[i] = min(dp[i],dp[i-arr[j]]+1);

    printf("%d",dp[x] == INF ? -1 : dp[x]);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
