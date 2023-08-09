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

int const MAXN = 1005;

int arr[MAXN],n;

bool posib (int ind, int mid, ll k) {
    int cur = mid;
    forsn(i,ind,n-1) {
        k -= cur-arr[i];
        if (cur <= arr[i+1]+1) {
            return (k >= 0);
        }
        --cur;
    }
    return (k >= 0) && (arr[n-1] >= cur);
}

int main() {
    int t; scanf("%d",&t);
    forn(_,t) {
        int k; scanf("%d %d",&n,&k);
        forn(i,n) scanf("%d",&arr[i]);

        int maxi = 0;
        forn(i,n) maxi = max(maxi,arr[i]);

        forn(i,n) {
            int low = arr[i], high = arr[i]+k+1;
            while (high-low > 1) {
                int mid = (high + low) / 2;
                if (posib(i,mid,k)) low = mid;
                else high = mid;
            }
            maxi = max(maxi,low);
        }

        printf("%d\n",maxi);
    }

    return 0;
}
