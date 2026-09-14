#include<bits/stdc++.h>
#include<cassert>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define sz(c) ((int)c.size())
#define all(c) (c).begin(),(c).end()
#define forall(it,v) for(auto it=v.begin();it!=v.end();++it)
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 505;

int dp[MAXN][MAXN];

int solve(int i, int j) {
    if (i < 0 || j < 0) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    dp[i][j] = i*j;
    forsn(k,1,i) dp[i][j] = min(dp[i][j],solve(k,j)+solve(i-k,j));
    forsn(k,1,j) dp[i][j] = min(dp[i][j],solve(i,k)+solve(i,j-k));
    return dp[i][j];
}

int barbijos(int W, int H, vector<int> &w, vector<int> &h) {
    forn(i,MAXN) forn(j,MAXN) dp[i][j] = -1;
    forn(i,sz(w)) dp[w[i]][h[i]] = 0;
    return solve(W,H);
}
