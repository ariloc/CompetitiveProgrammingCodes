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

int const MAXN = 2e5+5;

ii pts[MAXN];
map<int,int> byX, byY, byDif, bySum;

int main() {
    int t; scanf("%d",&t);
    forn(_,t) {
        int n; scanf("%d",&n);

        byX.clear(), byY.clear(), byDif.clear(), bySum.clear();

        forn(i,n) {
            int x,y; scanf("%d %d",&x,&y);
            pts[i] = {x,y};
            byX[x]++;
            byY[y]++;
            byDif[x-y]++;
            bySum[x+y]++;
        }

        ll rta = 0;
        forn(i,n) {
            int x = pts[i].fst, y = pts[i].snd;
            rta += byX[x]-1 + byY[y]-1 + byDif[x-y]-1 + bySum[x+y]-1;
        }
        printf("%lld\n",rta);
    }
          
    return 0;
}
