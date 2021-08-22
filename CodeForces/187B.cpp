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

const int INF = 2e9;
const int MAXM = 62;
const int MAXN = 62;
const int MAXK = 1005;
const int MAXR = 1e5+5;

int n,m,r;
int edges[MAXM][MAXN][MAXN];
int D[MAXK][MAXN][MAXN]; // llegando de la ciudad j a la k, con i cambios

int main() {
    forn(i,MAXK) forn(j,MAXN) forn(k,MAXN) D[i][j][k] = INF; // init

    scanf("%d %d %d",&n,&m,&r);
    forn(i,m) forn(j,n) forn(k,n) scanf("%d",&edges[i][j][k]);

    forn(o,m)
        forn(k,n) forn(i,n) forn(j,n)
            edges[o][i][j] = min(edges[o][i][j], edges[o][i][k] + edges[o][k][j]);

    forn(i,n) forn(j,n) forn(k,m) D[0][i][j] = min(D[0][i][j], edges[k][i][j]);

    forsn(o,1,MAXK)
        forn(k,n) forn(i,n) forn(j,n) 
            D[o][i][j] = min({D[o][i][j], D[o-1][i][j], D[o-1][i][k] + D[0][k][j]});

    forn(i,r) {
        int s,t,k; scanf("%d %d %d",&s,&t,&k); s--, t--;
        printf("%d\n",D[k][s][t]);
    }

    return 0;
}