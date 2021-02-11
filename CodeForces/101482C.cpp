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

const int MAXN = 2005;
const int MAXD = 22;
const int INF = 1e9+5;

int dp[MAXN][MAXD];
int prices[MAXN];

int myRound (int x) {
    if ((x%10) >= 5) return x+10-(x%10);
    else return x-(x%10);
}

int main() {
    FAST_IO;

    int n,d; cin >> n >> d;
    forn(i,n) cin >> prices[i+1];
    forsn(i,1,n+1) prices[i] += prices[i-1];

    forn(i,MAXN) forn(k,MAXD) dp[i][k] = INF;
    forn(i,MAXN) dp[i][0] = myRound(prices[i]);
    forsn(i,1,n+1) forn(j,i) forsn(k,1,d+1) {
        dp[i][k] = min({dp[i][k],myRound(dp[j][k-1]+prices[i]-prices[j])});
    }

    int mini = INF;
    forn(i,d+1) mini = min(mini,dp[n][i]);

    cout << mini;

    return 0;
}

/// ¡¡¡¡¡ HACE CASOS DE PRUEBAAAAAAAAAAAAAAAA !!!!!!!!!
/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
