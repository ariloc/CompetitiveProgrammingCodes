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

const int MAXN = 3e5+5;
const int INF = 1e9+5;

int arr[MAXN];
int dp[MAXN];

bool isPosib (int mid, int n, int k) {
    forn(i,n+1) dp[i] = 0;
    dp[0] = 1, dp[1] = -1;
    
    int r = 0;
    forn(l,n+1) {
        while (r < n+1 && arr[r]-arr[l+1] <= mid) r++;
        if (dp[l] && r >= l+k) ++dp[l+k], --dp[r];
        dp[l+1] += dp[l];
    }

    return (dp[n] > 0);
}

int main() {
    int n,k; scanf("%d %d",&n,&k);
    forn(i,n) scanf("%d",&arr[i+1]);

    sort(arr+1,arr+1+n);

    int low = -1, high = INF;
    while (high-low > 1)  {
        int mid = (high+low)/2;
        if (isPosib(mid,n,k)) high = mid;
        else low = mid;
    }

    printf("%d",high);

    return 0;
}