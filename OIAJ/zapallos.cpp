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

const int MAXN = 24e3+2;
const int MAXM = 1005;
const int MAXZ = 1202;
const int MAXA = 23;
const int INF = 1e9+2;

int dp[MAXN][MAXM];
int P[MAXN][MAXM];
bool pasado[MAXN][MAXM];
int zapallos[MAXA][MAXZ];
int amount[MAXA];

int A,M;

int main() {
    freopen("zapallos.in","r",stdin);
    freopen("zapallos.out","w",stdout);

    scanf("%d %d",&A,&M);

    forn (i,A) {
        int K;
        scanf("%d",&K);
        amount[i+1] = K;

        int val = 0;
        forn (j,K) {
            int C;
            scanf("%d",&C);
            val += 10-C; // ganancia hasta este punto

            zapallos[i+1][j+1] = val; // ganancia de agricultor i comprando j+1 zapallos
        }
    }

    forsn (i,1,A+2)  // por cada agricultor
        forn (j,M+1)  // sobrando para tal, j zapallos para poner
            forn (k,min(M-j+1,amount[i]+1)) { // cantidad de zapallos que puedo agarrar o cuántos tiene el agricultor (el menor)
                // la ganancia en agricultor i sobrando tantos zapallos menos como sobran en el anterior + lo que me da el anterior
                int calc = zapallos[i][k] + dp[i-1][j+k];
                if (calc > dp[i][j]) {
                    dp[i][j] = calc; // actualizo si es mejor dada cantidad de zapallos
                    P[i][j] = j+k; // padres
                    pasado[i][j] = true;
                }
            }


    forn (i,A+2) amount[i] = 0;

    int nd = A+1, cnt = 0, prev = 0, cantF = 0, bstW = 0;
    dforn (i,M+1) if (dp[A+1][i] > bstW) {bstW = dp[A+1][i]; cantF = i;}

    for (int i = cantF;; i = P[nd--][i]) {
        amount[nd] = i-prev;
        if (nd<=A and nd >= 0) cnt += i-prev;
        if (!pasado[nd][i]) break;
        prev = i;
    }

    printf("%d %d\n",dp[A+1][cantF],cnt);
    forn (i,A) printf("%d ",amount[i]);

    return 0;
}
