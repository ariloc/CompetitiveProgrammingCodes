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

const int MAXN = 1e6+5;

ll arr[MAXN];

int main() {
    int n; scanf("%d",&n);
    forn(i,n) scanf("%lld",&arr[i]);

    sort(arr,arr+n,greater<int>());
    forsn(i,1,n) arr[i] += arr[i-1];

    int q; scanf("%d",&q);
    forn(i,q) {
        ll x; scanf("%lld",&x);
        int aux = lower_bound(arr,arr+n,x)-arr;
        printf("%d\n",aux >= n ? -1 : aux+1);
    }
    
    return 0;
}