// AC -> UVa 10405 (Online Judge)

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

const int MAXN = 1005;

int dp[MAXN][MAXN];

int main() {
    FAST_IO;

    string a,b;
    while (getline(cin,a) and getline(cin,b)) {
        forn(i,a.size()+1) dp[i][0] = 0; // reset
        forn(i,b.size()+1) dp[0][i] = 0;
        forsn(i,1,a.size()+1) forsn(j,1,b.size()+1)
            dp[i][j] = max({dp[i-1][j],dp[i][j-1],(dp[i-1][j-1]+1)*(a[i-1] == b[j-1])});
        cout << dp[(int)a.size()][(int)b.size()] << '\n';
    }

    return 0;
}

/// ESCRIBÍ en vez de tanto dar vueltas
/// si te parece que no va PROBALO PRIMERO!
/// CODEA LO BÁSICO PRIMERO!
/// HACE C-A-S-O-S D-E P-R-U-E-B-A.A.A.A.A!!!
