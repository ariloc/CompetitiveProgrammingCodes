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
 
const int MAXN = 2e5+5;
const int MAXK = 18;
 
int P[MAXK][MAXN];
 
int query (int l, int r) {
    int dif = r-l;
    int bit = (31-__builtin_clz(dif));
    return min(P[bit][l], P[bit][r-(1<<bit)+1]);
}
 
int main() {
    int n; scanf("%d",&n);
 
    forn(i,n) scanf("%d",&P[0][i]);
 
    forsn(k,1,MAXK) forn(i,n)
        P[k][i] = min(P[k-1][i], P[k-1][i+(1<<(k-1))]);
 
    ll rta = 0;
    forn(i,n) {
        int low = i, high = n-1;
        while (high-low > 1) {
            int mid = (high+low)/2;
            if (query(i,mid) < P[0][i]) high = mid;
            else low = mid;
        }
 
        int r = high;
        if (P[0][r] >= P[0][i]) r = n;
 
        low = 0, high = i;
        while (high-low > 1) {
            int mid = (high+low)/2;
            if (query(mid,i) < P[0][i]) low = mid;
            else high = mid;
        }
 
        int l = low;
        if (P[0][l] >= P[0][i]) l = -1;
 
        rta = max(rta, (ll)(r-l-1)*P[0][i]);
    }
 
    printf("%lld",rta);
 
    return 0;
}
