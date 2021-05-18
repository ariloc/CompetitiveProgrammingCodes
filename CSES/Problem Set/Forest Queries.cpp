#include <bits/stdc++.h>
 
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
 
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
 
const int MAXN = 1005;
 
int TAd[MAXN][MAXN];
char forest[MAXN][MAXN];
 
int main() {
    int n,q; scanf("%d %d",&n,&q);
    forn(i,n) scanf("%s",forest[i]);
 
    forsn(i,1,n+1) forsn(j,1,n+1) {
        TAd[i][j] += (forest[i-1][j-1] == '*');
        TAd[i+1][j] += TAd[i][j];
        TAd[i][j] += TAd[i][j-1];
    }
 
    forn(i,q) {
        int x1,y1,x2,y2; scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        printf("%d\n",TAd[x2][y2] + TAd[x1-1][y1-1] - TAd[x2][y1-1] - TAd[x1-1][y2]);
    }
 
    return 0;
}
 
/// ESCRIB� en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO B�SICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!