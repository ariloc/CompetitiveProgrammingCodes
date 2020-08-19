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

const int MAXN = 105;
const int MAXP = 2;
const int INF = 1e9+2;

int arr[MAXN], N;
int dp[MAXN][MAXN][MAXP]; // posición, cantidad de impares, paridad

int main() {
    FAST_IO;

    forn(i,MAXN) forn(j,MAXN) forn(k,2) dp[i][j][k] = INF;

    cin >> N;
    int odC = (N+1)/2;

    forsn (i,1,N+1) cin >> arr[i];

    dp[0][0][0] = dp[0][0][1] = 0;
    forsn (i,1,N+1) forn (j,odC+2)
        if (arr[i]) forn (k,2) {
            bool st = arr[i] & 1;
            dp[i][j+st][st] = min(dp[i][j+st][st],dp[i-1][j][k] + (k != st));
        }
        else forn(k,2) forn(o,2)
            dp[i][j+k][k] = min(dp[i][j+k][k],dp[i-1][j][o] + (o != k));


    cout << min(dp[N][odC][0],dp[N][odC][1]);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!