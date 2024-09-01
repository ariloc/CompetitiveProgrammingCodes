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

int const MAXN = 205;
int const MAXP = 1e5+5;
int const INF = 2e9;

struct weapon {
    int a,b,c;

    bool operator< (const weapon &o) const {
        return b*(ll)(o.a-1) > o.b*(ll)(a-1);
    }
};

int dp[MAXN][MAXP];
vector<weapon> wep, lst;

int main() {
    FAST_IO;

    int n,p; cin >> n >> p;

    forn(i,n) {
        int a,b,c; cin >> a >> b >> c;
        if (a > 1)
            wep.pb({a,b,c});
        else lst.pb({a,b,c});
    }

    sort(all(wep));

    for (auto &i : wep)
        lst.pb(i);

    forn(i,MAXN) forn(j,MAXP)
        dp[i][j] = -INF;
    dp[n][0] = 0;

    dforsn(i,1,n+1) forn(j,MAXP) {
        weapon cur = lst[i-1];
        ll np = j * (ll)cur.a + cur.b;
        if (np < MAXP)
            dp[i-1][np] = max(dp[i-1][np], dp[i][j] + cur.c);
        dp[i-1][j] = max(dp[i-1][j], dp[i][j]);
    }

    int maxi = 0;
    forsn(i,1,p+1)
        maxi = max(maxi, dp[0][i]);

    cout << maxi << '\n';
    
    return 0;
}
