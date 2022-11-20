#include <algorithm>
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

const int MAXN = 1e5+5;
const int INF = 2e9;

int h[MAXN], dp[MAXN];

int main() {
    int n; scanf("%d", &n);
    forn(i,n) scanf("%d", &h[i]);

    forsn(i,1,n) dp[i] = INF;

    forn(i,n) {
        dp[i+1] = min(dp[i+1], dp[i] + abs(h[i]-h[i+1]));
        dp[i+2] = min(dp[i+2], dp[i] + abs(h[i]-h[i+2]));
    }

    printf("%d", dp[n-1]);
 
    return 0;
}

