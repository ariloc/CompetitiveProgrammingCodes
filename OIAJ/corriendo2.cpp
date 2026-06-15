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

int const INF = 2e9;
int const MAXN = 1e5+5;

int dp[MAXN];

vector<int> subidas(int N, vector<int> &cuadras) {
    int t = (int)cuadras.size();
    int mini = INF, maxi = -INF;

    int up = 0;
    forn(i,t) dp[i+1] = dp[i] + cuadras[i], up += cuadras[i];

    forn(i,t) {
        int cur = N/t * up;
        int rest = N%t;
        cur += dp[min(t, i+1+rest)] - dp[i+1];
        rest -= min(t-i-1, rest);
        cur += dp[rest];
        mini = min(mini,cur);
        maxi = max(maxi,cur);
    }
    return {mini, maxi};
}
