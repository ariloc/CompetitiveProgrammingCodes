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

int const MAXK = 18;
int const MAXN = 1<<MAXK;

int SP[MAXK][MAXN];

int query (int l, int r) {
    if (r == l) return SP[0][l];
    int dif = r-l;
    int bit = (31-__builtin_clz(dif));
    return max(SP[bit][l], SP[bit][r-(1<<bit)+1]);
}

int main() {
    int n; scanf("%d",&n);
    forn(i,n) scanf("%d",&SP[0][i]);
    int m,x,y; scanf("%d %d %d",&m,&x,&y);

    forsn(k,1,MAXK) forn(i,n)
        SP[k][i] = max(SP[k-1][i], SP[k-1][i+(1<<(k-1))]);

    ll rta = 0;
    forn(i,m) {
        rta += query(min(x,y),max(x,y));
        
        x = (x+7)%(n-1);
        y = (y+11)%n;
    }

    printf("%lld",rta);
        
    return 0;
}
