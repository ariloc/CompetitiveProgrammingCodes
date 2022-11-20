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

const int MAXN = 105;
const int MAXK = 1e5+5;

int n,k;
int arr[MAXN];
int dp[MAXK][2];

bool solve (int cnt, bool turn) {
    if (dp[cnt][turn] != -1) return dp[cnt][turn];

    bool posib = false;
    forn(i,n)
        if (cnt - arr[i] >= 0) posib |= 1^solve(cnt-arr[i], 1^turn);

    return (dp[cnt][turn] = posib);
}

int main() {
    scanf("%d %d",&n,&k);

    forn(i,k+1) dp[i][0] = dp[i][1] = -1;

    forn(i,n) scanf("%d", &arr[i]);

    printf("%s", solve(k,0) ? "First" : "Second");
   
    return 0;
}

