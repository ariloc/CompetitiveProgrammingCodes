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

int const MAXN = 105;
int const X[] = {0,1,-1,0};
int const Y[] = {1,0,0,-1};

vector<ii> coords;
int n,m,k;
int mint[MAXN][MAXN];

int main() {
    int T; scanf("%d",&T);

    forn(_,T) {
        coords.clear();
        scanf("%d %d %d",&n,&m,&k);

        int x,y; scanf("%d %d",&x,&y); x--, y--;
        forn(i,k) {
            int xi,yi; scanf("%d %d",&xi,&yi); xi--, yi--;
            coords.pb({yi,xi});
        }
    
        bool posib = false;
        forn(i,n) forn(j,m) {
            int d = abs(y-i) + abs(x-j);
            bool covered = false;
            for (auto &o : coords)
                if ((d&1) == ((abs(o.fst-i)+abs(o.snd-j))&1)) {
                    covered = true; break;
                }
            if (!covered) {
                posib = true;
            }
        }

        printf("%s\n",posib ? "YES" : "NO");
    }
          
    return 0;
}
