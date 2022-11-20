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

const int MAXN = 3005;

ld prob[MAXN], dp[MAXN][2];

int main() {
    int n; scanf("%d", &n);
    forn(i,n) scanf("%Lf", &prob[i]);

    dp[0][1] = 1;
    forn(i,n) forn(j,n+1)
        dp[j][i&1] = dp[j][1^(i&1)] * (1-prob[i]) + (j-1 >= 0 ? dp[j-1][1^(i&1)] * prob[i] : 0);

    ld rta = 0;
    forsn(i,(n+1)/2,n+1) rta += dp[i][(n-1)&1];

    printf("%.10Lf", rta);
   
    return 0;
}

