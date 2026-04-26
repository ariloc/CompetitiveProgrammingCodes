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

int const MAXN = 305;

ld dp[MAXN][MAXN][MAXN];
int arr[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    forn(i,n) cin >> arr[i];

    int cnt[3] = {0,0,0};
    forn(i,n) cnt[arr[i]-1]++;

    dp[cnt[0]][cnt[1]][cnt[2]] = 1;
    dforn(k,n+1) {
        dforn(j,n+1) {
            dforn(i,n+1) {
                int s = k+j+i;
                if (j && s) dp[i][j][k] += dp[i][j-1][k+1]*(k+1)/s;
                if (i && s) dp[i][j][k] += dp[i-1][j+1][k]*(j+1)/s;
                dp[i][j][k] += dp[i+1][j][k]*(i+1)/(s+1);
            }
        }
    }

    ld rta = 0;
    forn(i,n+1) {
        forn(j,n+1) {
            forn(k,n+1) {
                int s = i+j+k;
                // Distribución Geométrica -> Esperanza 1/p
                // La probabilidad de agarrar de uno con sushi es s/n
                // Entonces la esperanza de este proceso en este punto es n/s
                if (s) rta += dp[i][j][k]*n/(ld)s;
            }
        }
    }

    cout << fixed << setprecision(10) << rta << '\n';

    return 0;
}
