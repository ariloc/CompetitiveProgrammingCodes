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

const int MAXN = 2005;
const int INF = 1e9+5;

char mat[MAXN][MAXN];
int dp[MAXN][MAXN];
ii P[MAXN][MAXN];
bool done[MAXN][MAXN];

const int X[] = {0,1};
const int Y[] = {1,0};

struct node {
    int x,y; char c;

    bool operator< (const node &o) const{
        return o.c < c;
    }
};

int main() {
    //FAST_IO;

    forn(i,MAXN) forn(j,MAXN) dp[i][j] = INF;

    int n,k; scanf("%d %d ",&n,&k);
    forn(i,n) {forn(j,n) scanf("%c",&mat[i+1][j+1]); getchar();}
    n++;

    dp[1][0] = dp[0][1] = 0;

    forsn(i,1,n) forsn(j,1,n)
        dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + (mat[i][j] != 'a');

    //forsn(i,1,n) {forsn(j,1,n) cerr << dp[i][j]; cerr << endl;}

    vector<ii> inds; int indS = 0; int maxi = 0;
    forsn(i,1,n) forsn(j,1,n)
        if ((dp[i][j] > maxi or (dp[i][j] == maxi and (i+j-1) >= indS)) and dp[i][j] <= k) {
            if ((dp[i][j] > maxi) or ((i+j-1) > indS)) inds.clear();
            maxi = max(maxi,dp[i][j]);
            inds.pb({j,i}); indS = i+j-1;
            //cout << j << ' ' <<i << ' ' << dp[i][j] <<' ' << mat[i][j] << endl;
        }

    string rta;
    rta += string(indS,'a');

    queue<node> Q; priority_queue<node> toProcesar;
    for (auto &i : inds) Q.push({i.fst,i.snd,'a'});
    if (inds.empty()) {Q.push({1,1,mat[1][1]}); rta += mat[1][1];}

    while (not Q.empty() or not toProcesar.empty()) {
        while (not Q.empty()) {
            auto e = Q.front(); Q.pop();

            //cerr << e.x << ' ' << e.y << endl;

            forn(i,2) {
                int tX = e.x+X[i], tY = e.y+Y[i];
                if (tX >= n or tY >= n) continue;
                if (done[tX][tY]) continue;
                //cerr << tX << ' ' << tY << endl;
                done[tX][tY] = true;
                toProcesar.push({tX,tY,mat[tY][tX]});
            }
        }
        //cerr << "OK";
        if (toProcesar.empty()) break;

        char myC = toProcesar.top().c; rta += myC;
        while (not toProcesar.empty()) {
            if (toProcesar.top().c == myC) Q.push(toProcesar.top());
            toProcesar.pop();
        }
    }

    if (dp[n-1][n-1] <= k) {forsn(i,1,2*(n-1)) putchar('a'); return 0;}

    printf("%s",rta.c_str());

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!