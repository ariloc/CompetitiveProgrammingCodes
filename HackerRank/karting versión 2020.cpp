// https://www.hackerrank.com/contests/simulacro-provincial-2020/challenges/karting
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

const int MAXN = 3005;
const int X[] = {0,1,0,-1};
const int Y[] = {1,0,-1,0};

bool done[MAXN][MAXN];
int grid[MAXN][MAXN];
int n;
pair<ii,int> dp[MAXN][MAXN];
vector<ii> G[MAXN][MAXN];

ii st = {-1,-1}, nd = {-1,-1}; int rta = -1;

void dfs (int i, int j) {
    done[i][j] = true;

    pair<ii,int> meBst = {{i,j},0};
    forn (k,4) {
        int tY = i+Y[k], tX = j+X[k];
        if (tY < 0 or tX < 0 or tY >= n or tX >= n) continue;
        if (grid[tY][tX] >= grid[i][j]) continue;
        if (!done[tY][tX]) dfs(tY,tX);
        if (dp[tY][tX].snd+1 > meBst.snd) {
            meBst.snd = dp[tY][tX].snd+1;
            meBst.fst = dp[tY][tX].fst;
        }
    }
    dp[i][j] = meBst;
}

int main() {
    scanf("%d",&n);
    forn(i,n) forn(j,n) scanf("%d",&grid[i][j]);
    forn(i,n) forn(j,n) if (!done[i][j]) {
        dfs(i,j);
        if (dp[i][j].snd > rta) {
            rta = dp[i][j].snd;
            st = {i,j}; nd = dp[i][j].fst;
        }
    }

    printf("%d\n%d %d %d %d",rta,st.snd+1,st.fst+1,nd.snd+1,nd.fst+1);

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
