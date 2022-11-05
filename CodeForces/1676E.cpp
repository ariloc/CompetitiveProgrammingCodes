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
        int n,q; scanf("%d %d",&n,&q);

        vector<ll> arr;
        forn(i,n) {int x; scanf("%d",&x); arr.pb(x);}
        sort(all(arr), greater<int>());
        forsn(i,1,n) arr[i] += arr[i-1];

        forn(i,q) {
            int x; scanf("%d",&x);
            int ind = lower_bound(all(arr), x)-arr.begin();
            if (ind >= n) printf("-1\n");
            else printf("%d\n",ind+1);
        }
    }

    return 0;
}
