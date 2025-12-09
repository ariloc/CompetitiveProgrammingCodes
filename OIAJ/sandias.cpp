#include<bits/stdc++.h>
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)
 
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;
typedef long double ld;

int const MAXN = 5005;
int const MAXT = 5005;

bitset<MAXT> dp;
ii P[MAXT];

int sandias(int T, vector<int> &x, vector<int> &p, vector<int> &ubicaciones) {
    int N = (int)x.size();

    P[0] = {-1,-1}, dp[0] = true;
    forn(i,N) {
        dforsn(j,p[i],T+1)
            if (!dp[j] && dp[j-p[i]]) {
                dp[j] = true;
                P[j] = {j-p[i],i};
            }
    }

    int maxi;
    dforn(i,T+1) if (dp[i]) { maxi = i; break; }
    
    vi ubic;
    int cur = maxi;
    while (cur > 0) {
        ubic.pb(x[P[cur].snd]);
        cur = P[cur].fst;
    }
    reverse(all(ubic)); // pues construyo en orden creciente de ubicaciones

    ubicaciones = ubic;
    return maxi;
}
