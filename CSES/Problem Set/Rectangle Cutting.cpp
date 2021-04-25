#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 505;
const int INF = 1e9+5;

int dp[MAXN][MAXN];

int main() {
    FAST_IO;

    forn(i,MAXN) forn(j,MAXN) dp[i][j] = INF; // all infinite
    forn(i,MAXN) dp[i][i] = 0; // if it's a square, it's all good

    int a,b; cin >> a >> b;

    forsn(i,1,a+1) forsn(j,1,b+1) {
        forsn(k,1,(i+1)/2+1) dp[i][j] = min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
        forsn(k,1,(j+1)/2+1) dp[i][j] = min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
    }

    cout << dp[a][b];

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
