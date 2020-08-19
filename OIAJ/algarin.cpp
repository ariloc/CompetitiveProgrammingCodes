#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 1010;
const int INF = 1e7+5;

vector<string> mercado;
vector<vi> dp(MAXN, vi(MAXN,-INF));
int r = -INF;
const int T[] = {-1,0,+1};

int main() {
    FAST_IO;

    int n,m;
    cin >> m >> n;

    ii posA = {0,-1};
    forn(i,m) {
        string s;
        cin >> s;
        if (s[0] == 'A') posA.snd = i;
        mercado.push_back(s);
    }
    dp[posA.fst][posA.snd] = 0;

    forsn (x,1,n) {
        forn (y,m) {
            forn (i,3) {
                int tendY = y+T[i],tendX = x-1;
                if (tendY < 0 or tendY >= m) continue;
                if (dp[tendX][tendY] == -INF) continue;
                if (mercado[y][x] == 'M') {
                    if (dp[tendX][tendY] > 0) dp[x][y] = 0;
                    continue;
                }
                dp[x][y] = max(dp[x][y],dp[tendX][tendY]+(mercado[y][x] == 'J' ? 1 : 0));
            }
        }
    }
    forn (i,m) r = max(r,dp[n-1][i]);
    if (r < 0) cout << "SIN SALIDA";
    else cout << r;

    return 0;
}
