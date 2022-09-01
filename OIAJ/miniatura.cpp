#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int MAXN = 2005;

ll dp[MAXN][MAXN][3];
int n = -1, m = -1;

void inicializar(vector<vector<int>> &rojo, vector<vector<int>> &verde, vector<vector<int>> &azul) {
    n = rojo.size(), m = rojo[0].size();

    forn(i,n) forn(j,m) dp[i+1][j+1][0] = rojo[i][j];
    forn(i,n) forn(j,m) dp[i+1][j+1][1] = verde[i][j];
    forn(i,n) forn(j,m) dp[i+1][j+1][2] = azul[i][j];

    // TAd
    forn(k,3) {
        forn(i,MAXN) forsn(j,1,MAXN) {
            if (i+1 < MAXN) dp[i+1][j][k] += dp[i][j][k];
            dp[i][j][k] += dp[i][j-1][k];
        }
    }

    //forn(i,n+1) {forn(j,m+1) cerr << dp[i][j][2] << ' '; cerr << endl;}
}

void miniatura(int k, int l, vector<vector<int>> &rojo, vector<vector<int>> &verde, vector<vector<int>> &azul) {
    for (int i = 0, i2 = 0; i < n; ++i2, i = (i2*n)/k) {
        for (int j = 0, j2 = 0; j < m; ++j2, j = (j2*m)/l) {
            int lY = i, lX = j;
            int rY = ((i2+1)*n)/k - 1;
            int rX = ((j2+1)*m)/l - 1;

            int cnt = (rY-lY+1) * (rX-lX+1);

            //cerr << i2 << ' ' << j2 << ' '  << i << ' ' << j << ' '  << cnt << " !!!" << endl;

            forn(col,3) {
                ll sum = dp[rY+1][rX+1][col] - dp[lY][rX+1][col] - dp[rY+1][lX][col] + dp[lY][lX][col];
                ll prom = sum / cnt;

                //cerr << sum << ' ' << col << " !!!" << endl;

                if (!col) rojo[i2][j2] = prom;
                else if (col == 1) verde[i2][j2] = prom;
                else azul[i2][j2] = prom;
            }
        }
    }
}
