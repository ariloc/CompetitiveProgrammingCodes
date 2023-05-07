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

const int MAXN = 2100;
const int MAXM = 1e6+5;

ll dp[MAXN][MAXN];
ii inds[MAXN*MAXN];

int main() {
    FAST_IO;

    ll ind = 1;
    forsn(i,1,MAXN) forsn(j,1,i+1) {
        inds[ind] = {i,j};
        if (i >= 2) dp[i][j] -= dp[i-2][j-1];
        dp[i][j] += dp[i-1][j] + dp[i-1][j-1] + ind*ind;
        ind++;
    }

    int t; cin >> t;
    forn(_,t) {
        int n; cin >> n;
        ii aux = inds[n];
        cout << dp[aux.fst][aux.snd] << '\n';
    }
    
    return 0;
}
