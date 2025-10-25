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
 
int const MAXN = 1005;
 
int dp[MAXN][MAXN];
ii p[MAXN][MAXN];
int arr1[MAXN], arr2[MAXN];
 
int main() {
    FAST_IO;
 
    int n,m; cin >> n >> m;
    forn(i,n) cin >> arr1[i+1];
    forn(i,m) cin >> arr2[i+1];
 
    forn(i,n+1) forn(j,n+1) p[i][j] = {-1,-1};
 
    auto calc = [&](int i, int j, int i2, int j2) {
        if (dp[i2][j2] > dp[i][j]) {
            dp[i][j] = dp[i2][j2];
            p[i][j] = {i2,j2};
        }
    };
    forsn(i,1,n+1) forsn(j,1,m+1) {
        calc(i,j,i-1,j);
        calc(i,j,i,j-1);
 
        if (arr1[i] == arr2[j]) {
            int auxi = dp[i-1][j-1] + 1;
            if (auxi > dp[i][j]) {
                dp[i][j] = auxi;
                p[i][j] = {i-1,j-1};
            }
        }
    }
 
    cout << dp[n][m] << '\n';
 
    vi seq;
    int ix = n, jx = m;
    while (ix > 0 && jx > 0) {
        ii pad = p[ix][jx];
        if (pad.fst != -1 && pad.snd != -1 &&  dp[ix][jx] != dp[pad.fst][pad.snd]) seq.pb(arr1[ix]);
        ix = pad.fst, jx = pad.snd;
    }
    reverse(all(seq));
    for (auto &i : seq) cout << i << ' ';
    cout << '\n';
 
    return 0;
 
}
