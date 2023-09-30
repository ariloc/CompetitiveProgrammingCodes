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

int main() {
    int t; scanf("%d",&t);
    forn(_,t) {
        int n,x,y; scanf("%d %d %d",&n,&x,&y); 

        ll s = n * (ll)(n+1) / 2;
        ll lcm = ((ll)x * y) / __gcd(x,y);

        ll divlcm = n/lcm;

        ll divx = max(0LL,n/x - divlcm);
        ll sx = s - ((n-divx) * (ll)(n-divx+1) /2);

        ll divy = max(0LL,n/y - divlcm);
        ll sy = (divy * (ll)(divy+1) /2);

        printf("%lld\n",sx - sy);
    }
    
    return 0;
}
