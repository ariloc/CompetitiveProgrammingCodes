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

int main() {
    int t; scanf("%d",&t);
    forn(o,t) {
        int n,m; scanf("%d %d",&n,&m);
        
        printf("Case #%d:\n",o+1);
        forn(i,2*n+1) {
            forn(j,2*m+1) {
                if (i < 2 && j < 2) putchar('.');
                else if (i&1) putchar((j&1) ? '.' : '|');
                else putchar((j&1) ? '-' : '+');
            }
            if (i < 2*n+1) puts("");
        }
    }

    return 0;
}
