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

int const MAXN = 1005;

int dp[MAXN][MAXN];
string s;
int n;

bool check (int l, int k, int r) {
    return s[l] != s[k] && s[k] != s[r] && s[l] != s[r];
}

bool solve(int l, int r) {
    if (r < l+2) return 1;
    if (r == l+2) {
        return check(l,l+1,l+2);
    }
    if (dp[l][r] != -1) return dp[l][r];
    for (int k = l+1; k <= r-1; k += 3)
        if (check(l,k,r) && solve(l+1,k-1) && solve(k+1,r-1))
            return dp[l][r] = 1;
    for (int k = r-1; k >= l+1; k -= 3)
        if (check(l,k,r) && solve(l+1,k-1) && solve(k+1,r-1))
            return dp[l][r] = 1;
    if (solve(l+3,r) && check(l,l+1,l+2)) return dp[l][r] = 1;
    if (solve(l,r-3) && check(r-2,r-1,r)) return dp[l][r] = 1;
    return dp[l][r] = 0;
}

int main() {
    FAST_IO;

    cin >> s;
    n = sz(s);

    forn(i,MAXN) forn(j,MAXN) dp[i][j] = -1;

    if (n%3) return cout << "N\n", 0;

    bool ok = false;
    for (int i = 0; i < n; i += 3)
        for (int j = i+2; j < n; j += 3)
            if (solve(i,j) && solve(0,i-1) && solve(j+1,n-1))
                ok = true;

    cout << (ok ? "S" : "N") << '\n';

    return 0;
}
