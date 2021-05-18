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
 
int FT[MAXN][MAXN];
char forest[MAXN][MAXN];
 
void setFT (int y, int x, int v) {
    for (int i = y; i < MAXN; i += i & -i)
        for (int j = x; j < MAXN; j += j & -j)
            FT[i][j] += v;
}
 
int getFT (int y, int x) {
    int r = 0;
    for (int i = y; i; i -= i & -i)
        for (int j = x; j; j -= j & -j)
            r += FT[i][j];
    return r;
}
 
int main() {
    int n,q; scanf("%d %d",&n,&q);
 
    forn(i,n) scanf("%s",forest[i]);
    forn(i,n) forn(j,n) if (forest[i][j] == '*') setFT(i+2,j+2,1);
 
    forn(i,q) {
        int typ; scanf("%d",&typ);
        if (typ == 1) {
            int y,x; scanf("%d %d",&y,&x); y--; x--;
            bool put = (forest[y][x] == '.');
            forest[y][x] = (put ? '*' : '.');
            setFT(y+2,x+2,(put ? 1 : -1));
        }
        else {
            int y1,x1,y2,x2; scanf("%d %d %d %d",&y1,&x1,&y2,&x2); y1++; x1++; x2++; y2++;
            printf("%d\n",getFT(y2,x2)+getFT(y1-1,x1-1)-getFT(y1-1,x2)-getFT(y2,x1-1));
        }
    }
 
    return 0;
}
 
/// ESCRIB� en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO B�SICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!