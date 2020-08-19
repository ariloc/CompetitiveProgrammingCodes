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

const int X[] = {0,1,0,-1};
const int Y[] = {1,0,-1,0};

const int MAXD = 102;
const int MAXP = 10005;
const int MAXL = 22;
const int MAXA = 28;
const int INF = 1e9+2;

char let[MAXD][MAXD]; int val[MAXD][MAXD];
int dp[MAXD][MAXD][2];
vector<ii> posib[MAXA]; // reduzco tiempo buscando sólo los adyacentes a letras

int main() {
    freopen("rayuela.in","r",stdin);
    freopen("rayuela.out","w",stdout);

    int D,P; scanf("%d %d",&D,&P);

    forn (i,D) forn (j,D) {
        scanf(" %c %d",&let[i][j],&val[i][j]);
        posib[let[i][j]-'a'].pb({i,j});
    }

    while (P--) {
        char pal[MAXL]; scanf("%s",pal);

        forn(i,D) forn(j,D) dp[i][j][0] = dp[i][j][1] = -INF;
        for (auto &e : posib[pal[0]-'a']) dp[e.fst][e.snd][0] = val[e.fst][e.snd]; // reset

        int p, maxi = 0; bool me = 0, prev = 1;
        for (p = 1; pal[p]; p++) {
            me = !me; prev = !prev;
            for (auto &e : posib[pal[p]-'a']) {
                int i = e.fst, j = e.snd, tmp = -INF;

                forn (k,4) {
                    int tY = i+Y[k], tX = j+X[k];
                    if (tX < 0 or tY < 0 or tX >= D or tY >= D or let[tY][tX] != pal[p-1]) continue;
                    tmp = max(tmp,dp[tY][tX][prev]+val[i][j]);
                }

                dp[i][j][me] = tmp;
            }
        }

        for (auto &e : posib[pal[p-1]-'a']) maxi = max(maxi,dp[e.fst][e.snd][me]);

        printf("%d\n",maxi);
    }

    return 0;
}
