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

int const MAXN = 1e5+5;

int a[MAXN], b[MAXN], movs[MAXN];

int main() {
    int t; scanf("%d",&t);
    forn(_,t) {
        int n; scanf("%d",&n);
        forn(i,n) scanf("%d",&a[i]);
        forn(i,n) scanf("%d",&b[i]);

        forn(i,n) {
            int x = a[i], y = b[i];
            int mov = 0;
            // cerr << x << ' ' << y << " STTTT" << endl;
            while (x != y && x && y) {
                if (x < y) {
                    int z = abs(x-y);
                    x = y, y = z; mov++;
                }
                // cerr << x << ' ' << y << "HMM" << endl;
                int rest = x % y;
                int x2 = x-rest;
                int div = x2/y;
                mov += div + div/2;
                x = y, y = rest;
                if (!(div&1)) swap(x,y);
                // cerr << x << ' ' << y << ' ' << mov << "PI" << endl;
            }
            while (x) {
                int z = abs(x-y);
                x = y, y = z;
                mov++;
            }
            movs[i] = mov;
        }

        vi pos;
        forn(i,n) if (a[i] || b[i]) pos.pb(movs[i]);
        for (auto &i : pos) i %= 3;
        bool posib = true;
        forsn(i,1,pos.size()) if (pos[i] != pos[i-1]) posib = false;

        printf("%s\n", posib ? "YES" : "NO");
    }
          
    return 0;
}
