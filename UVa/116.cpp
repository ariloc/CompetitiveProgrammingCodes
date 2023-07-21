#include <bits/stdc++.h>
 
//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma")
 
#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define dbg(x) cerr << #x << " = " << x << endl;
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);
 
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
typedef long double ld;

int const MAXR = 12;
int const MAXC = 105;
int const INF = INT_MAX;

int mat[MAXR][MAXC], dp[MAXR][MAXC], S[MAXR][MAXC];

int main() {
    int r,c;
    while (scanf("%d %d",&r,&c) != -1) {
        forn(i,r) forn(j,c) scanf("%d",&mat[i][j]);

        forn(i,r) forn(j,c) dp[i][j] = INF, S[i][j] = -1;
        
        forn(i,r) dp[i][c-1] = mat[i][c-1], S[i][c-1] = -1;
        dforsn(j,1,c) forn(i,r) {
            int opt[] = {(i-1+r)%r,i,(i+1)%r};

            forn(k,3) {
                int calc = dp[i][j]+mat[opt[k]][j-1];
                if (calc < dp[opt[k]][j-1])
                    dp[opt[k]][j-1] = calc, S[opt[k]][j-1] = i;
            }
        }

        int mini = INF, ind = -1;
        forn(i,r) if (dp[i][0] < mini) mini = dp[i][0], ind = i;

        int curcol = 0, currow = ind;
        while (curcol < c)
            printf("%d%c",currow+1," \n"[curcol == c-1]), currow = S[currow][curcol], curcol++;

        printf("%d\n",mini);
    }
          
    return 0;
}
