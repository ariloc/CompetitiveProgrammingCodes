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

const int MAXN = 5005;
const int INF = 2e9+5;

int col[MAXN],dp[MAXN][MAXN];
int N;

int main() {
    FAST_IO;

    cin >> N;
    int sz = 0;
    forn (i,N) {int x; cin >> x; if (!i or x != col[sz-1]) col[sz++] = x;}

    dforsn (i,1,sz+1) forsn(j,i+1,sz+1)
        if (col[i-1] == col[j-1]) dp[i][j] = dp[i+1][j-1]+1;
        else dp[i][j] = min(dp[i+1][j],dp[i][j-1])+1;

    cout << dp[1][sz];

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!