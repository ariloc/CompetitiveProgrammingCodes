// https://www.hackerrank.com/contests/simulacro-provincial-2020/challenges/juego-de-television/problem
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

const int MAXC = 3005;
const int MAXM = 1005;
const int MOD = 10000007;
const int INF = 2e9+5;

struct edge {
    int a,b,c;
};

struct data {
    int ng,maxp,nmaxp;
    // ng son juegos
    // maxp es mayor premio
    // nmaxp es cantidad de formas para mayor premio
};

edge carpet[MAXC];
data dp[MAXM][MAXC];
vi black;

int main() {
    forn(i,MAXM) forn(j,MAXC) dp[i][j] = {0,-INF,0};
    int c,s,m; scanf("%d %d %d",&c,&s,&m);
    forn(i,c) {
        int A,E,C; scanf("%d %d %d",&A,&E,&C);
        carpet[i] = {A-1,E-1,C};
    }
    forn(i,s) {int x; scanf("%d",&x); black.pb(x-1);}

    dp[0][0] = {1,0,1};

    forn(i,m) forn(j,c) {
        // cant juegos
        dp[i+1][carpet[j].a].ng = (dp[i+1][carpet[j].a].ng+dp[i][j].ng)%MOD;
        if (carpet[j].a != carpet[j].b) dp[i+1][carpet[j].b].ng = (dp[i+1][carpet[j].b].ng+dp[i][j].ng)%MOD;

        // max premio
        int calcA = dp[i][j].maxp+carpet[j].c;
        if (calcA >= dp[i+1][carpet[j].a].maxp) {
            if (calcA == dp[i+1][carpet[j].a].maxp) dp[i+1][carpet[j].a].nmaxp = (dp[i+1][carpet[j].a].nmaxp+dp[i][j].nmaxp)%MOD;
            else dp[i+1][carpet[j].a].nmaxp = dp[i][j].nmaxp;
            dp[i+1][carpet[j].a].maxp = dp[i][j].maxp+carpet[j].c;
        }

        if (dp[i][j].maxp >= dp[i+1][carpet[j].b].maxp) {
            if (dp[i][j].maxp == dp[i+1][carpet[j].b].maxp) dp[i+1][carpet[j].b].nmaxp = (dp[i+1][carpet[j].b].nmaxp+dp[i][j].nmaxp)%MOD;
            else dp[i+1][carpet[j].b].nmaxp = dp[i][j].nmaxp;
            dp[i+1][carpet[j].b].maxp = dp[i][j].maxp;
        }
    }

    int maxP = 0, NmaxP = 0, Ng = 0; // consigo el (max) max premio y cantidad de formas
    for (auto &i : black) {
        if (dp[m][i].maxp >= maxP) {
            if (dp[m][i].maxp == maxP) NmaxP = (NmaxP+dp[m][i].nmaxp)%MOD;
            else NmaxP = dp[m][i].nmaxp;
            maxP = dp[m][i].maxp;
        }
        Ng = (Ng+dp[m][i].ng)%MOD;
    }

    printf("%d %d %d",Ng,maxP,NmaxP);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
