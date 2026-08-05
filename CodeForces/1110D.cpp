#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define snd second
#define fst first
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr)

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

int const MAXN = 1e6+5;
int const MAXM = 1e6+5;
int const INF = 2e9;

int histo[MAXN];
int dp[2][5][3];

int main() {
    FAST_IO;

    int n,m; cin >> n >> m;
    forn(i,n) {
        int x; cin >> x;
        histo[x-1]++;
    }

    if (m <= 2) {
        cout << histo[0]/3 + histo[1]/3 << '\n';
        return 0;
    }

    dp[1][0][0] = 0;
    forsn(i,2,m) {
        forn(j,3) forn(k,5) dp[i%2][k][j] = -INF;
        forn(j,min(3,histo[i]+1)) forsn(k,j,min(5,histo[i-1]+1)) forsn(l,k-j,min(5,histo[i-2]-j+1)) {
            if (k-j < 3) dp[i%2][k][j] = max(dp[i%2][k][j], dp[1-(i%2)][l][k-j] + j + (histo[i-2]-l-j)/3);
        }
        /*
        forn(j,5) forn(k,3)
            if (dp[i%2][k][j] != -INF) cerr << dp[i%2][k][j] << ' ' << i << ' ' << k << ' ' << j << ' ' << histo[i] << endl;*/
    }

    int maxi = -INF;
    forn(i,5) forn(j,3) maxi = max(maxi, dp[(m-1)%2][i][j] + (histo[m-2]-i)/3 + (histo[m-1]-j)/3);

    cout << maxi << '\n';

    return 0;
}
