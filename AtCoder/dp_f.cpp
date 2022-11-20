#include <algorithm>
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
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

const int MAXN = 3005;

pair<int, ii> dp[MAXN][MAXN];

int main() {
    FAST_IO;

    string s,t; cin >> s >> t;
    s.pb('X'), t.pb('Y'); // dummies
    int n = (int)s.size(), m = (int)t.size();

    forn(i,MAXN) forn(j,MAXN) dp[i][j] = {0,{-1,-1}};

    forsn(i,1,n+2) forsn(j,1,m+2) {
        dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
        if (s[i-1] == t[j-1])
            dp[i+1][j+1] = max(dp[i+1][j+1], {dp[i][j].fst+1, {i,j}});
    }

    ii aux = dp[n+1][m+1].snd;
    string r;
    while (aux.fst != -1) r.pb(s[aux.fst-1]), aux = dp[aux.fst][aux.snd].snd;
    reverse(all(r));

    cout << r;

    return 0;
}

