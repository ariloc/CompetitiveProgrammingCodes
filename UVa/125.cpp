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
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const int MAXN = 35;

int ady[MAXN][MAXN];
ll D[MAXN][MAXN];
bitset<MAXN> done, inCycle;

bool dfs (int st, int n, int rt) {
    done[st] = true;

    forn(i,n)
        if (D[i][st] && (i == rt || (!done[i] && dfs(i,n,rt))))
            return true;

    return false;
}

int main() {
    int m, cnt = 0;
    while (scanf("%d",&m) != -1) {
        forn(i,MAXN) forn(j,MAXN) D[i][j] = 0;
        inCycle.reset(); 

        int n = -1;
        forn(i,m) {
            int u,v; scanf("%d %d",&u,&v);
            D[u][v]++;
            n = max(n,max(u,v));
        }
        n++;
        
        forn(i,n) {
            done.reset();
            inCycle[i] = dfs(i,n,i);
        }

        forn(k,n) forn(i,n) forn(j,n)
            D[i][j] = D[i][j] + D[i][k]*D[k][j];

        forn(k,n) forn(i,n) forn(j,n)
            D[i][j] = (inCycle[k] || D[i][k] == -1 || D[k][j] == -1) && D[i][k] && D[k][j] ? -1 : D[i][j];

        printf("matrix for city %d\n",cnt);
        forn(i,n) {
            forn(j,n) {
                printf("%lld",D[i][j]);
                if (j != n-1) printf(" ");
            }
            puts("");
        }

        cnt++;
    }

    return 0;
}
