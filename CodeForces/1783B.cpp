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

const int MAXN = 52;

const int X[] = {1,0,-1,0};
const int Y[] = {0,1,0,-1};

int arr[MAXN][MAXN];

int main() {
    int t; scanf("%d",&t);
    forn(_,t) {
        int n; scanf("%d",&n);

        int x = 0, y = 0, dir = 0;
        int lim[4] = {0,n,n,0};
        forn(i,n*n) {
            arr[y][x] = i%2 ? n*n-(i/2) : (i/2)+1;

            int tX = x + X[dir], tY = y + Y[dir];
            if (tX < lim[3] || tY < lim[0] || tX >= lim[1] || tY >= lim[2]) {
                lim[dir] += 1 * (dir == 0 || dir == 3 ? 1 : -1);
                dir = (dir+1)%4, tX = x + X[dir], tY = y + Y[dir];
            }
            x = tX, y = tY;
        }

        forn(i,n) forn(j,n) printf("%d%c",arr[i][j]," \n"[j == n-1]);
    }
   
    return 0;
}
