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
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 505;
const int MAXL = 1e5+5;
const ll INF = 9e18;

ii signs[MAXN];
ll dp[MAXN][MAXN]; // hasta esta señal, habiendo quitado k señales

int main() {
    int n,l,k; scanf("%d %d %d",&n,&l,&k);
    forn(i,n) scanf("%d",&signs[i].fst);
    forn(i,n) scanf("%d",&signs[i].snd);

    forn(i,MAXN) forn(j,MAXN) dp[i][j] = INF;
    dp[0][0] = 0;
    signs[n] = {l,-1};
    forn(i,n+1) forn(j,k+1) forn(w,k+1-j)
        if (i+1+w <= n)
            dp[i+1+w][j+w] = min(dp[i+1+w][j+w], dp[i][j] + (signs[i+1+w].fst - signs[i].fst) * (ll)signs[i].snd);
    
    ll mini = INF;
    forn(i,k+1) mini = min(mini,dp[n][i]);
    printf("%lld",mini);

    return 0;
}