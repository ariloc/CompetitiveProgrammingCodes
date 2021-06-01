#include <bits/stdc++.h>

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

const int MAXN = 6005;
const int MAXK = 55;
const int MAXS = 16;
const int INF = 1e9;

int dp[MAXN][MAXK][MAXS];

int sumMod (int a, int b) {
    a += b;
    if (a >= MAXS) a -= MAXS;
    return a;
}

void reset(int n, int k) {
    forn(i,n+2) forn(j,k+2) forn(l,MAXS) dp[i][j][l] = -INF; 
}

void go (int n, int k, int s_i, vi &ronda, bool mode = 0) {
    reset(n,k);

    if (mode) {
        int aux = ronda[0];
        dp[1][1][ronda[1]] = aux*aux;
    }
    else dp[0][0][sumMod(s_i,ronda[0])] = 0;

    forsn(i,mode,n) {
        int nxtS = ronda[i+1];
        forsn(j,mode,k) forn(sum,MAXS) { 
            int nxt = sumMod(sum,ronda[i+1]), me = dp[i][j][sum];
            dp[i+1][j][nxt] = max(dp[i+1][j][nxt], me);
            dp[i+1][j+1][nxtS] = max(dp[i+1][j+1][nxtS], me + sum*sum);
        }
    }
}

vector<int> romperonda(vector<int> &ronda, int k) {
    int n = ronda.size();
    int maxi = 0;

    ronda.pb(0); // dummy
    for (auto &i : ronda) i %= MAXS;

    k++;
    forsn(stSum,1,MAXS) {
        go(n,k,stSum,ronda);
        maxi = max(maxi,dp[n][k-1][stSum]);
    }
    k--;
    go(n,k,0,ronda);
    maxi = max(maxi,dp[n][k][0]);

    go(n,k,0,ronda,1);
    int maxi2 = dp[n][k][0];

    return {maxi,maxi2};
}