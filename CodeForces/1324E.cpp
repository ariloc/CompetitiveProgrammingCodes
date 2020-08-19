#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 2e3+2;

int times[MAXN],n,h,l,r;
int dp[MAXN][MAXN];

int solve(int ind, int time) {
    if (ind >= n) return (time >= l and time <= r ? 1 : 0);
    if (dp[ind][time] != -1) return dp[ind][time];
    int calcTime1 = time + times[ind];
    calcTime1 %= h;
    int calcTime2 = calcTime1-1;
    if (calcTime2 < 0) calcTime2 = h-1;
    return dp[ind][time] = max(solve(ind+1,calcTime1),solve(ind+1,calcTime2)) + (time >= l and time <= r ? 1 : 0);
}

int main() {
    FAST_IO;
    memset(dp,-1,sizeof(dp));

    cin >> n >> h >> l >> r;

    forn (i,n) {
        int x; cin >> x; times[i] = x;
    }

    cout << solve(0,0)-(!l ? 1 : 0);

    return 0;
}