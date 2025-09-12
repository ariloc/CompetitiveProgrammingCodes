#include <bits/stdc++.h>

#define forn(i,n) for(int i =0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;

int const MAXE = 20+1;
ll const INF = 9e18;

ll dp[2][1<<MAXE];
int n,b,t;
vector<pair<ll,ll>> coords;
vi cant;
vi sob,falt;

ll dist (int i, int j) {
    return abs(coords[i].fst - coords[j].fst) + abs(coords[i].snd - coords[j].snd);
}

ll superbicis (vector<ll> &x, vector<ll>&y, vi &c) {
    t = 0;
    cant = c;
    n = (int)cant.size();
    forn(i,n) t += cant[i];
    b = 2*t/n;
    forn(i,n) coords.pb({x[i],y[i]});

    forn(i,n) {
        int dif = cant[i]-b/2;
        if (dif < 0) {
            forn(k,-dif) falt.pb(i); 
        }
        if (dif > 0) {
            forn(k,dif) sob.pb(i);
        }
    }

    int s = (int)sob.size(), f = (int)falt.size();
    forn(i,1<<s) dp[0][i] = INF;
    dp[0][0] = 0;
    forsn(j,1,1<<s) {
        ll mini = INF;
        int i = __builtin_popcount(j);
        forn(k,s) if (j&(1<<k)) {
            mini = min(mini,dp[1-(i&1)][j^(1<<k)] + dist(falt[i-1],sob[k]));
        }
        dp[i&1][j] = mini;
    }
    ll r = dp[f&1][(1<<s) - 1];

    return r == INF ? 0 : r;
}
