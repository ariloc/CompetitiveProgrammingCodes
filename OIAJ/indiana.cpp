#include <bits/stdc++.h>

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = 0; i < int(n); i++)
#define dforn(i,n) for(int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define fst first
#define snd second
#define pb push_back
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

const int MAXN = 2002;
const int MAXW = 2;
const int INF = 1e9+2;

char sent[MAXN][MAXN]; // true -> horario | false -> antihorario
int dp[MAXN][MAXN][MAXW]; // 0 -> viene de izq | 1 -> de arriba

int main() {
    freopen("indiana.in","r",stdin);
    freopen("indiana.out","w",stdout);

    int N; scanf("%d",&N);

    forn(i,MAXN) forn (j,MAXN) dp[i][j][0] = dp[i][j][1] = INF; // Bloqueo donde no corresponde
    forn(i,N) scanf("%s",sent[i]);

    dp[0][0][1] = (sent[0][0] ? 1 : 3); // puedo técnicamente venir de arriba, dando la vuelta
    dp[0][0][0] = 0; // salgo de la izquierda
    forn(i,MAXN-1) forn(j,MAXN-1) {
        dp[i][j+1][0] = min(dp[i][j][0]+2,dp[i][j][1]+(sent[i][j] == 'H' ? 1 : 3)); // ways to right
        dp[i+1][j][1] = min(dp[i][j][0]+(sent[i][j] == 'H' ? 3 : 1),dp[i][j][1]+2); // ways to down
    }

    printf("%d",dp[N-1][N][0]);
    return 0;
}
