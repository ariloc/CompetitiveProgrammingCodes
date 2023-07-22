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

int const INF = 1e9;
int const MAXN = 2e5+5;

int arr[MAXN];
int n;

__int128 calc (int mid) {
    __int128 r = 0;
    forn(i,n) r += 4LL*arr[i]*(ll)mid + (mid*(ll)mid)*4LL;
    return r;
}

int main() {
    int t; scanf("%d",&t);
    forn(_,t) {
        ll c; scanf("%d %lld",&n,&c);

        forn(i,n) {
            scanf("%d",&arr[i]);
            c -= arr[i]*(ll)arr[i];
        }
        
        int low = 0, high = INF;
        while(high-low > 1) {
            int mid = (high+low)/2;
            if (calc(mid) >= c) high = mid;
            else low = mid;
        }

        printf("%d\n",high);
    }
          
    return 0;
}
