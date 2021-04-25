#include <bits/stdc++.h>

//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define forsn(i,s,n) for(int i = int(s); i < int(n); i++)
#define dforn(i,n) for (int i = int(n)-1; i >= 0; i--)
#define dforsn(i,s,n) for(int i = int(n)-1; i >= int(s); i--)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define fst first
#define snd second
#define FAST_IO ios::sync_with_stdio(false);cin.tie(nullptr);

using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> ii;

const int MAXN = 15e4+5;
const int MOD = 1e9+7;

int dp[MAXN];

int main() {
    FAST_IO;

    int n; cin >> n;
    int sum = (n*(n+1))/2;

    dp[0] = 1;
    forsn (i,1,n+1) dforsn(j,i,sum/2+1)
        dp[j] = (dp[j]+dp[j-i])%MOD;

    if (!(sum & 1)) cout << (dp[sum/2]*(ll)(MOD+1)/2)%MOD;
    else cout << 0;

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
